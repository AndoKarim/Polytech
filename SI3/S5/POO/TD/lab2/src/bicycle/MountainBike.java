/**
 * @author Andolerzak Abdelkarim
 * @
 */

package bicycle;

public class MountainBike {
	private double wheel;
	private ChainringSet chain;
	private Cassette cassette;

	private final double ONE_INCH = 0.0254;

	public double getWheel() {
		return wheel;
	}

	public ChainringSet getChain() {
		return chain;
	}

	public Cassette getCassette() {
		return cassette;
	}

	public MountainBike(double wheelDiameter, ChainringSet chainringSet,
			Cassette cass) {
		// Dividing by two because we want the radius and multiplying by the
		// coefficient to have the dimension in meters
		
		wheel = (wheelDiameter * ONE_INCH) / 2;
		chain = chainringSet;
		cassette = cass;
	}

}
