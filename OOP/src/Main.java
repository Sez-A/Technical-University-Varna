import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        Table table = new Table();
//
//        TableFiller filler = new TableFiller();
//        filler.fill(table, 0, "Hello");
//        filler.fill(table, 0, "Hi");
//        filler.fill(table, 1, "Second Row");
//
//
//       TablePrinter.print(table);

        TableFiller filler = new TableFiller();
        filler.fillTableFromFile("src/files/second_info_file.txt", table);

        TablePrinter.print(table);
    }
}
