import java.util.ArrayList;
import java.util.List;

public class TablePrinter {

    public static void print(Table table) {
        for (int i = 0; i < table.getContent().size(); i++) {
            List<ArrayList<String>> content = table.getContent();
            ArrayList<String> currentRow = content.get(i);
            for (int j = 0; j < currentRow.size(); j++) {
                if(currentRow.get(j).isEmpty()) {
                    continue;
                }
                System.out.print(currentRow.get(j) + " | ");
            }
            System.out.println();
        }
    }
}
