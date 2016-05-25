import jdk.internal.org.objectweb.asm.tree.analysis.Interpreter;

import java.util.Stack;

/**
 * @author : Karim
 * @date :  15/12/2015.
 */
public class ExpressionPolonaise {
    private enum signs {
        PLUS('+'),
        MINUS('-'),
        TIMES('*'),
        DIVIDE('/');

        private char val;

        signs(char s) {
            val = s;
        }

        public char valChar() {
            return val;
        }
    }

    public static String trueVal(String s) {
        Stack operators = new Stack();
        String result = "";
        int cptNb = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case '+':
                    cptNb=0;
                    operators.push('+');
                    break;
                default:
                    cptNb++;
                    if (cptNb >= 3)
                        result = result + s.charAt(i - 2) + operators.pop() + s.charAt(i - 1) + operators.pop() + s.charAt(i);
                    break;
                case '-' :
                    if (cptNb >= 3)
                        result = result + s.charAt(i - 2) +  operators.pop() + s.charAt(i - 1) + operators.pop() + s.charAt(i);                    break;
                case '*' :
                    if (cptNb >= 3)
                        result = result + s.charAt(i - 2) +  operators.pop() + s.charAt(i - 1) + operators.pop() + s.charAt(i);                    break;
                case '/' :
                    if (cptNb >= 3)
                        result = result + s.charAt(i - 2) +  operators.pop() + s.charAt(i - 1) + operators.pop() + s.charAt(i);
                    break;

            }
        }
        return result;
    }

}
