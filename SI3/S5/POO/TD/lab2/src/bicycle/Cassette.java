/**
 * @author Andolerzak Abdelkarim
 * @
 */

package bicycle;

public class Cassette {
    private Sprockets[] sprockets;

    public Sprockets[] getSprockets() {
        return sprockets;
    }

    Cassette(Sprockets[] sprocketsTab) {
        sprockets = new Sprockets[9];
        if (sprocketsTab.length == 9) {
            sprockets = sprocketsTab;
        }
    }

}
