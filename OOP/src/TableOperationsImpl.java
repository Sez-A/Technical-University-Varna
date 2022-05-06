import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class TableOperationsImpl implements TableOperations {
    private final TableFiller tableFiller;

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
        return "Successfully opened " + file.getName();
    }

    @Override
    public void close() {

    }

    @Override
    public void save() {

    }

    @Override
    public void saveAs(String filePath) {

    }

    @Override
    public void edit() {

    }

    @Override
    public void help() {

    }

    @Override
    public void exit() {

    }
}
