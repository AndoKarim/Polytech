/**
 * @author Andolerzak Abdelkarim
 * @
 */

package bicycle;

public class Main {
    public static void main(String[] args) {

        MountainBike vtt;
        double wheelDiameter = 26;
        Chainring chain1 = new Chainring(22);
        Chainring chain2 = new Chainring(32);
        Chainring chain3 = new Chainring(44);

        Chainring[] tabChain = { chain1, chain2, chain3 };
        ChainringSet chainringSet = new ChainringSet(tabChain);

        Sprockets sprock1 = new Sprockets(11);
        Sprockets sprock2 = new Sprockets(12);
        Sprockets sprock3 = new Sprockets(14);
        Sprockets sprock4 = new Sprockets(16);
        Sprockets sprock5 = new Sprockets(18);
        Sprockets sprock6 = new Sprockets(21);
        Sprockets sprock7 = new Sprockets(24);
        Sprockets sprock8 = new Sprockets(28);
        Sprockets sprock9 = new Sprockets(32);

        Sprockets[] sprockTab = { sprock1, sprock2, sprock3, sprock4, sprock5,
                sprock6, sprock7, sprock8, sprock9 };
        Cassette cassette = new Cassette(sprockTab);

        vtt = new MountainBike(wheelDiameter, chainringSet, cassette);

        Development dev = new Development(vtt);
        dev.developments();
        System.out.println(dev.toString());

    }

}
