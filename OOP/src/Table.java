import java.util.ArrayList;
import java.util.List;

public class Table {
    private String fileName;
    private List<ArrayList<String>> content;

    public Table() {
        this.content = new ArrayList<ArrayList<String>>();
    }

    public List<ArrayList<String>> getContent() {
        return content;
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }
}
