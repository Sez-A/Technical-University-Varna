import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TableFiller {
    private final String VALID_STRING_PATTERN = "^\"[A-Za-z]+.*\"$";
    private final String VALID_NUMBER_PATTERN = "^-*[0-9]+.{0,1}[\\d+]*$";
    private final String VALID_FORMULA_PATTERN = "^= ([\\d]+)*([A-Z][\\d]+[A-Z][\\d]+)* [+\\-*\\/] ([\\d]+)*([A-Z][\\d]+[A-Z][\\d]+)*$";

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
                if (!validInput(cellInfo)) {
                    throw new InvalidInput(String.format("Error: row %d, %s is unknown data type",
                            rowCnt, cellInfo));
                }
                fill(table, rowCnt, cellInfo);
            }
            rowCnt++;
        }
    }

    private boolean validInput(String data) {
        Pattern pattern
                = Pattern.compile(VALID_STRING_PATTERN);
        Matcher matcher
                = pattern.matcher(data);
        boolean invalidInput = matcher.matches();
        if (!invalidInput) {
            pattern = Pattern.compile(VALID_NUMBER_PATTERN);
            matcher = pattern.matcher(data);
            invalidInput = matcher.matches();
            if (!invalidInput) {
                pattern = Pattern.compile(VALID_FORMULA_PATTERN);
                matcher = pattern.matcher(data);
                invalidInput = matcher.matches();
                if (!invalidInput) {
                    return false;
                }
            }
        }
        return true;
    }
}
