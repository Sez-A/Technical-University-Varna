import java.io.FileNotFoundException;
import java.io.IOException;

public interface TableOperations {
    String open(String filePath, Table table) throws IOException;

    void close();

    void save();

    void saveAs(String filePath);

    void edit();

    void help();

    void exit();
}
