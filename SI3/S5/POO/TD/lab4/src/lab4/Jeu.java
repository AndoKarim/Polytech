/**
* @author Abdelkarim Andolerzak
*/

package lab4;

import lab4.cards.shuffled.Suits;

import java.util.ArrayList;
import java.util.Collections;

public class Jeu {
    private ArrayList<Carte> cardsDeck = new ArrayList<Carte>(52);
    private boolean shuffled = false;

    public Jeu() {
        for (Suits ens : Suits.values()) {
            for (Rang rng : Rang.values())
                cardsDeck.add(new Carte(ens.getTexte(), rng.getTexte()));
        }
    }
    
    public void battre(){
        shuffled = true ;
        Collections.shuffle(cardsDeck);
    }
    
    public ArrayList<Carte> getJeu(){
        return cardsDeck;
    }
    
    public Carte tirer(){
        if(cardsDeck.isEmpty())
            return null;
        if(!shuffled)
            battre();
        return cardsDeck.remove(0);
    }

}
