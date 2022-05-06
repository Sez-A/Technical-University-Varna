import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class TableOperationsImpl implements TableOperations {
    private final TableFiller tableFiller;
    private boolean fileIsOpenToManipulations;

    public TableOperationsImpl(TableFiller tableFiller) {
        this.tableFiller = tableFiller;
    }

    @Override
    public String open(String filePath, Table table) throws IOException {
        File file = new File(filePath);
        if (!file.exists()) {
            throw new FileNotFoundException("File with file path: " + filePath + " has been not found");
        }
        tableFiller.fillTableFromFile(file, table);
        this.fileIsOpenToManipulations = true;
        return "Successfully opened " + file.getName();
    }

    @Override
    public void close() {
        this.fileIsOpenToManipulations = false;
    }

    @Override
    public String save(Table table) throws IOException {
        this.saveAs(table.getFileName(), table);
        return String.format("Changes are successfully saved in %s", table.getFileName());
    }

    @Override
    public String saveAs(String filePath, Table table) throws IOException {
        FileWriter writer = new FileWriter(filePath);
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < table.getContent().size(); i++) {
            List<ArrayList<String>> content = table.getContent();
            ArrayList<String> currentRow = content.get(i);
            for (int j = 0; j < currentRow.size(); j++) {
                if (currentRow.get(j).isEmpty()) {
                    continue;
                } else if (currentRow.get(j).contains(",")) {
                    builder.append(currentRow.get(j).replace(" | ", ", "));
                } else
                    builder.append(currentRow.get(j)).append(", ");
            }
            builder.append(System.lineSeparator());
        }
        writer.write(builder.toString());
        writer.flush();
        return String.format("Changes are successfully saved in %s", filePath);
    }

    @Override
    public void edit() {

    }
}
