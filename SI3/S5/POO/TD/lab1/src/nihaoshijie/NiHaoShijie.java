package nihaoshijie;

/**
 * Class to create an object to print a message.
 * 
 * @author <a href="mailto:sander@polytech.unice.fr">Peter Sander</a>
 */
public class NiHaoShijie {
    private String message = "Ni hao shijie";

    @Override
    public String toString() {
        return "from NiHaoShijie: " + message;
    }

    public void print() {
        System.out.println(toString());
    }
}
