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

        arrangeTable(table);
    }

    private void arrangeTable(Table table) {
        for (ArrayList<String> currentRow : table.getContent()) {
            if (allCellsInRowIsEmpty(currentRow)) {
                fillEmptyRowWithMaxCellCountInTable(maxCellCountInTable(table), currentRow);
            } else {
                arrangeRow(currentRow, maxCellCountInTable(table));
            }
        }
    }

    private void arrangeRow(ArrayList<String> currentRow, int maxCellCountInTable) {
        for (int i = currentRow.size(); i < maxCellCountInTable; i++) {
            currentRow.add(i, "");
        }
    }

    private boolean allCellsInRowIsEmpty(ArrayList<String> currentRow) {
        for (String dataInCell : currentRow) {
            if (!dataInCell.isEmpty()) {
                return false;
            }
        }
        return true;
    }

    private int maxCellCountInTable(Table table) {
        int maxCellCount = -1;
        for (ArrayList<String> row : table.getContent()) {
            if (row.size() > maxCellCount) {
                maxCellCount = row.size();
            }
        }
        return maxCellCount;
    }

    private void fillEmptyRowWithMaxCellCountInTable(int maxCellCountInTable, ArrayList<String> currentRow) {
        currentRow.clear();
        for (int i = 0; i < maxCellCountInTable; i++) {
            currentRow.add(i, "");
        }
    }
}
