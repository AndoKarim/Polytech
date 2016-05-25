/**
 * @author Abdelkarim Andolerzak
 */

package lab4;

import lab4.cards.shuffled.Suits;

public class Carte {
    private Suits suits;
    private Rang rang;

    public Carte(String ens, String rng) {
        suits = Suits.getEnseigne(ens);
        rang = Rang.getRang(rng);
    }

    public Suits getSuits() {
        return suits;
    }

    public Rang getRang() {
        return rang;
    }

    //L'ordinal repr�sente "l'indice" de l'�num. Le premier �l�men est 0 etc.
    public int comparer(Carte carte) {
        if (rang.ordinal() < carte.rang.ordinal())
            return -1;
        if (rang.ordinal() > carte.rang.ordinal())
            return 1;
        if (rang.ordinal() == carte.rang.ordinal()) {
            if (suits.ordinal() < carte.suits.ordinal())
                return -1;
            if (suits.ordinal() > carte.suits.ordinal())
                return 1;
        }
        // Si les deux cartes sont identiques
        return 0;
    }

    public String toString() {
        return rang.getTexte() + " de " + suits.getTexte();
    }

}
