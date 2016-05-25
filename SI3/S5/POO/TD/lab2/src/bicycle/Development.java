/**
 * @author Andolerzak Abdelkarim
 * @
 */

package bicycle;

import java.text.DecimalFormat;

public class Development {
    private double[][] devs;
    private MountainBike bike;

    public double[][] getDevs() {
        return devs;
    }

    public Development(MountainBike mountainBike) {
        bike = mountainBike;

        // The +1 in the dimension of the 2D Array is because of the empty case
        // in [0][0] to delimit columns and lines

        devs = new double[bike.getCassette().getSprockets().length + 1][bike
                .getChain().getChains().length + 1];
        for (int i = 0; i < devs.length - 1; i++) {
            devs[i + 1][0] = bike.getCassette().getSprockets()[i].getTeeths();
        }

        for (int i = 0; i < bike.getChain().getChains().length; i++) {
            devs[0][i + 1] = bike.getChain().getChains()[i].getTeeths();
        }

    }

    public double[][] developments() {
        double wheelPerimeter = 2 * Math.PI * bike.getWheel();

        for (int i = 1; i < devs.length; i++) {
            for (int j = 1; j < devs[0].length; j++) {
                devs[i][j] = (wheelPerimeter * bike.getChain().getChains()[j - 1]
                        .getTeeths())
                        / bike.getCassette().getSprockets()[i - 1].getTeeths();
            }
        }
        return devs;
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("###.#");
        for (int i = 0; i < devs.length; i++) {
            for (int j = 0; j < devs[j].length; j++) {
                System.out.print("  " + df.format(devs[i][j]) + " \t");
            }
            System.out.print("\n");
            System.out.println("----------------------------------");

        }
        return "";
    }

}
