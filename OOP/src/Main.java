import exceptions.InvalidInput;

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        Table table = new Table();
        TableOperations tableOperations = new TableOperationsImpl();
        FormulaExecutor formulaExecutor = new FormulaExecutorImpl(table);
        TableInfoValidator infoValidator = new TableInfoValidatorImpl();
        System.err.println(("Please pay attention that you pass argument (s)" +
                " with single space to operations which works with argument (s)").toUpperCase());
        System.err.println("Example: open {single space} filePath");
        menu();
        System.out.print("Please choose operation: ");

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
                case "formula":
                    try {
                        formulaTypes();
                        System.out.print("Please enter data for formula: ");
                        input = scan.nextLine();
                        if (infoValidator.validInput(input)) {
                            String[] split = input.substring(input.indexOf('=') + 2).split("\\s+");
                            System.out.println("Result is: " +
                                    formulaExecutor.processFormula(split[0], split[1], split[2]));
                        } else {
                            System.out.println("Input " + input + " not correct!");
                        }
                    }catch (UnsupportedOperationException e) {
                        System.out.println();
                        System.err.println(e.getMessage());
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
            System.out.print("Please choose operation: ");
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
        System.out.println("formula -> arithmetical operations");
        System.out.println("print -> print table");
        System.out.println("help -> prints this information");
        System.out.println("exit -> exists the program");
        System.out.println("------------------------------------------------------------------");
    }

    private static void formulaTypes() {
        System.out.println("0. R - row in table, C - column in table, arithmetical sign can be + - * etc.");
        System.out.println("1. Cell references. Example: R1C1 arithmetical sign R2C1");
        System.out.println("2. Cell reference and number. Example: R1C1 arithmetical sign 10");
        System.out.println("3. Number and cell reference. Example: 10.5 arithmetical sign R1C1");
        System.out.println("3. Number and number. Example: 17.5 arithmetical sign 50");
    }
}
