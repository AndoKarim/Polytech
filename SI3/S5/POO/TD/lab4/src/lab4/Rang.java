/**
 * @author Abdelkarim Andolerzak
 */

package lab4;

public enum Rang {
    AS("as"), DEUX("2"), TROIS("3"), QUATRE("4"), CINQ("5"), SIX("6"), SEPT("7"),
    HUIT("8"), NEUF("9"), DIX("10"), VALET("valet"), DAME("dame"), ROI("roi");
    
    private String texte;
    
    Rang(String val){
        texte = val ; 
    }
    
    public String getTexte(){
        return texte;
    }
    
    public static Rang getRang(String txt) {
        if (txt != null) {
            for (Rang rng : Rang.values()) {
                if (txt.toLowerCase().equals(rng.getTexte()))
                    return rng;
            }
        }
        return null;

    }

}