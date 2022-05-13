import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FormulaExecutorImpl implements FormulaExecutor {
    private static final String VALID_NUMBER_PATTERN = "^-*[0-9]+.{0,1}[\\d+]*$";
    private static final String VALID_COL_REFERENCE_PATTERN = "^[A-Z][\\d]+[A-Z][\\d]+\\b";
    private final Table table;

    public FormulaExecutorImpl(Table table) {
        this.table = table;
    }

    @Override
    public double processFormula(String firstArg, String arithmeticalSign, String secondArg) {
        if (isColReference(firstArg) && isColReference(secondArg)) {
            String[] rowAndColInfo = getIndicesFromColReference(firstArg).split("\\s+");
            double firstNumber = getValidValueForElement(getElementByRowAndCol(
                    Integer.parseInt(rowAndColInfo[0]) - 1,
                    Integer.parseInt(rowAndColInfo[1]) - 1));

            rowAndColInfo = getIndicesFromColReference(secondArg).split("\\s+");
            double secondNumber = getValidValueForElement(getElementByRowAndCol(
                    Integer.parseInt(rowAndColInfo[0]) - 1,
                    Integer.parseInt(rowAndColInfo[1]) - 1));
            return this.calculate(firstNumber, secondNumber, arithmeticalSign);

        } else if (isColReference(firstArg) && elementIsDigit(secondArg)) {

            String[] rowAndColInfo = getIndicesFromColReference(firstArg).split("\\+s");
            double firstNumber = getValidValueForElement(getElementByRowAndCol(
                    Integer.parseInt(rowAndColInfo[0]) - 1,
                    Integer.parseInt(rowAndColInfo[1]) - 1));
            return this.calculate(firstNumber, Double.parseDouble(secondArg), arithmeticalSign);

        } else if (isColReference(secondArg) && elementIsDigit(firstArg)) {
            String[] rowAndColInfo = getIndicesFromColReference(secondArg).split("\\s+");
            double secondNumber = getValidValueForElement(getElementByRowAndCol(
                    Integer.parseInt(rowAndColInfo[0]) - 1,
                    Integer.parseInt(rowAndColInfo[1]) - 1));
            return this.calculate(Double.parseDouble(firstArg), secondNumber, arithmeticalSign);
        } else if (elementIsDigit(firstArg) && elementIsDigit(secondArg)) {
            return this.calculate(Double.parseDouble(firstArg),
                    Double.parseDouble(secondArg), arithmeticalSign);
        }

        throw new UnsupportedOperationException();
    }

    private String getIndicesFromColReference(String colReference) {
        colReference = colReference.replace("R", " ");
        colReference = colReference.replace("C", " ");
        return colReference.trim();
    }

    private String getElementByRowAndCol(int row, int col) {
        if (row >= table.getContent().size()) {
            return "0";
        }
        List<ArrayList<String>> tableContent = table.getContent();
        ArrayList<String> currentRow = tableContent.get(row);
        if (col >= currentRow.size()) {
            return "0";
        }
        return currentRow.get(col);
    }

    private boolean isColReference(String data) {
        Pattern pattern
                = Pattern.compile(VALID_COL_REFERENCE_PATTERN);
        Matcher matcher
                = pattern.matcher(data);
        return matcher.matches();
    }

    private boolean elementIsDigit(String element) {
        Pattern pattern
                = Pattern.compile(VALID_NUMBER_PATTERN);
        Matcher matcher
                = pattern.matcher(element);

        return matcher.matches();
    }

    private double getValidValueForElement(String element) {
        if (elementIsDigit(element)) {
            return Double.parseDouble(element);
        } else {
            return 0;
        }
    }

    private double calculate(double firstNum, double secondNum, String arithmeticalSign) {
        switch (arithmeticalSign) {
            case "+":
                return firstNum + secondNum;
            case "-":
                return firstNum - secondNum;
            case "*":
                return firstNum * secondNum;
            case "/":
                if (secondNum == 0) {
                    throw new UnsupportedOperationException("ERROR");
                } else {
                    return firstNum / secondNum;
                }
            case "^":
                return Math.pow(firstNum, secondNum);

        }

        throw new UnsupportedOperationException();
    }
}
