import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TableInfoValidatorImpl implements TableInfoValidator {
    private static final String VALID_STRING_PATTERN = "^\"[A-Za-z]+.*\"$";
    private static final String VALID_NUMBER_PATTERN = "^-*[0-9]+.{0,1}[\\d+]*$";
    private static final String VALID_FORMULA_PATTERN = "^= ([\\d]+)*([A-Z][\\d]+[A-Z][\\d]+)* [+\\-*\\/] ([\\d]+)*([A-Z][\\d]+[A-Z][\\d]+)*$";

    @Override
    public boolean validInput(String data) {
        Pattern pattern
                = Pattern.compile(VALID_STRING_PATTERN);
        Matcher matcher
                = pattern.matcher(data);
        boolean invalidInput = matcher.matches();
        if (!invalidInput) {
            pattern = Pattern.compile(VALID_NUMBER_PATTERN);
            matcher = pattern.matcher(data);
            invalidInput = matcher.matches();
            if (!invalidInput) {
                pattern = Pattern.compile(VALID_FORMULA_PATTERN);
                matcher = pattern.matcher(data);
                invalidInput = matcher.matches();
                if (!invalidInput) {
                    return false;
                }
            }
        }
        return true;
    }
}
