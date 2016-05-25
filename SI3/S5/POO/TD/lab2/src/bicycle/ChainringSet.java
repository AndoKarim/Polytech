/**
 * @author Andolerzak Abdelkarim
 * @
 */

package bicycle;

public class ChainringSet {
    private Chainring[] chains;

    public Chainring[] getChains() {
        return chains;
    }

    ChainringSet(Chainring[] chainsTab) {
        if (chainsTab.length == 3) {
            chains = new Chainring[3];
            chains[0] = chainsTab[0];
            chains[1] = chainsTab[1];
            chains[2] = chainsTab[2];

        }
    }
}
