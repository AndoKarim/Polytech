import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

/**
 * @author : Karim
 * @date :  15/12/2015.
 */
public class Main {
    public static void main(String[] args) {
        String expr = "+*-452+79";
        String result = ExpressionPolonaise.trueVal(expr);
        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine red = manager.getEngineByName("js");
        try {
            int res = (int) red.eval(result);
            System.out.println(res);
        } catch (ScriptException e) {
            e.printStackTrace();
        }
    }
}
