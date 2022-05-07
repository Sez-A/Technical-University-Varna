import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TableFiller {
    private final TableInfoValidator infoValidator;

    public TableFiller() {
        this.infoValidator = new TableInfoValidatorImpl();
    }

    public void fill(Table table, int row, String info) {
        if (table.getContent().size() == row) {
            ArrayList<String> currentRow = new ArrayList<>(List.of(info));
            table.getContent().add(currentRow);
        } else {
            table.getContent().get(row).add(info);
        }
    }

    public void fillTableFromFile(File file, Table table) throws IOException {
        Scanner scanner = new Scanner(file);
        table.setFileName(file.getName());
        int rowCnt = 0;
        while (scanner.hasNextLine()) {
            String[] tokens = scanner.nextLine().trim().split(",");
            if (tokens.length == 0) {
                fill(table, rowCnt, "");
                rowCnt++;
                continue;
            }
            for (int i = 0; i < tokens.length; i++) {
                String cellInfo = tokens[i].trim();
                if (cellInfo.isEmpty()) {
                    fill(table, rowCnt, cellInfo);
                    continue;
                }
                if (cellInfo.contains("\\\"")) {
                    cellInfo = cellInfo.replace("\\\"", "");
                }
                if (!infoValidator.validInput(cellInfo)) {
                    throw new InvalidInput(String.format("Error: At row %d in %s, %s is unknown data type",
                            rowCnt + 1, file.getName(), cellInfo));
                }
                fill(table, rowCnt, cellInfo);
            }
            rowCnt++;
        }
    }
}
