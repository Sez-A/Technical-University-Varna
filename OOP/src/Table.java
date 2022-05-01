import java.util.ArrayList;
import java.util.List;

public class Table {
    private List<ArrayList<String>> content;

    public Table() {
        this.content = new ArrayList<ArrayList<String>>();
    }

    public List<ArrayList<String>> getContent() {
        return content;
    }
}
