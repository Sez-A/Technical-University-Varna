import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TableFiller {
    private final String VALID_STRING_PATTERN = "^\"[A-Za-z]+\"$";
    private final String VALID_NUMBER_PATTERN = "^-*[0-9]+.*[\\d+*]$";
    private final String VALID_FORMULA_PATTERN = "^= ([\\d]+)*([A-Z][\\d]+[A-Z][\\d]+)* [+\\-*\\/] ([\\d]+)*([A-Z][\\d]+[A-Z][\\d]+)*$";

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
            String[] tokens = scanner.nextLine().trim().split(",");
            if (tokens.length == 0) {
                fill(table, rowCnt, "");
                rowCnt++;
                continue;
            }
            for (int i = 0; i < tokens.length; i++) {
                String cellInfo = tokens[i].trim();
                if (inputIsInvalid(cellInfo)) {
                    // TODO: 5/3/2022 Throw appropriate exception
                }
                if (cellInfo.contains("\\\"")) {
                    cellInfo = cellInfo.replace("\\\"", "");
                }
                fill(table, rowCnt, cellInfo);
            }
            rowCnt++;
        }
    }

    private boolean inputIsInvalid(String data) {
        // TODO Check whether data is valid!
        return false;
    }
}
