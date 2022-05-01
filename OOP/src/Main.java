import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        Table table = new Table();
        TableFiller filler = new TableFiller();
        filler.fillTableFromFile("src/files/second_info_file.txt", table);
        TablePrinter.print(table);
    }
}
