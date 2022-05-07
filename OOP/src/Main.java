import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        Table table = new Table();
        TableOperations tableOperations = new TableOperationsImpl();
        System.err.println(("Please pay attention that you pass argument (s)" +
                " with single space to operations which works with argument (s)").toUpperCase());
        System.err.println("Example: open {single space} filePath");
        menu();
        System.out.print("Please chose operation: ");
        String input = scan.nextLine();
        while (!input.equals("exit")) {
            String[] tokens = input.split("\\s+");
            switch (tokens[0].toLowerCase()) {
                case "open":
                    System.out.println(tableOperations.open(tokens[1], table));
                    break;
                case "save":
                    if (tokens.length == 1) {
                        System.out.println(tableOperations.save(table));
                    } else {
                        System.out.println(tableOperations.saveAs(tokens[2], table));
                    }
                    break;
                case "edit":
                    try {
                        System.out.println(tableOperations.edit(Integer.parseInt(tokens[1]),
                                Integer.parseInt(tokens[2]),
                                tokens[3],
                                table));
                    } catch (InvalidInput | IndexOutOfBoundsException e) {
                        System.err.println(e.getMessage());
                        System.out.println();
                    }
                    break;
                case "print":
                    TablePrinter.print(table);
                    break;
                case "help":
                    menu();
                    break;
                default:
                    System.out.println("Operation " + tokens[0] + " not supported!");
                    break;
            }
            System.out.print("Please chose operation: ");
            input = scan.nextLine();
        }


    }

    private static void menu() {
        System.out.println("------------------------------MENU------------------------------");
        System.out.println("The following commands are supported:");
        System.out.println("open <file> argument: filePath -> opens <file> ");
        System.out.println("close -> closes currently opened file");
        System.out.println("save -> saves the currently open file");
        System.out.println("save as <file> -> saves the currently open file in <file>");
        System.out.println("print -> print table");
        System.out.println("help -> prints this information");
        System.out.println("exit -> exists the program");
        System.out.println("------------------------------------------------------------------");
    }
}
