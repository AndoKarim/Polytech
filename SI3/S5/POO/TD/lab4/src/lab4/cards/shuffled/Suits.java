/**
 * @author Abdelkarim Andolerzak
 */

package lab4.cards.shuffled;

public enum Suits {
    CLUBS("clubs"), DIAMONDS("diamonds"), HEARTS("hearts"), SPADES("spades");

    private String name;

    Suits(String val) {
        name = val;
    }

    public String getTexte() {
        return name;
    }

    public static Suits getEnseigne(String txt) {
        if (txt != null) {
            for (Suits ens : Suits.values()) {
                if (txt.toLowerCase().equals(ens.getTexte()))
                    return ens;
            }
        }
        return null;

    }

    public String toString(){
        return "Suit of the card : " + this.getTexte();
    }

}
