import java.io.FileNotFoundException;
import java.io.IOException;

public interface TableOperations {
    String open(String filePath, Table table) throws IOException;

    void close();

    String save(Table table) throws IOException;

    String saveAs(String filePath, Table table) throws IOException;

    void edit();
}
