import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TableFiller {
    public void fill(Table table, int row, String info) {
        if (table.getContent().size() == row) {
            ArrayList<String> currentRow = new ArrayList<>(List.of(info));
            table.getContent().add(currentRow);
        } else {
            table.getContent().get(row).add(info);
        }
    }

    public void fillTableFromFile(String filePath, Table table) throws IOException {
        File file = new File(filePath);

        Scanner scanner = new Scanner(file);

        int rowCnt = 0;
        while (scanner.hasNextLine()) {
            String[] tokens = scanner.nextLine().split(", ");
            for (int i = 0; i < tokens.length; i++) {
                String cellInfo = tokens[i].trim();
                if (cellInfo.contains("\\\"")) {
                    cellInfo = cellInfo.replace("\\\"", "");
                }
                fill(table, rowCnt, cellInfo);
            }
            rowCnt++;
        }
    }
}
