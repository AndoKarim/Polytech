/**
 * @author Abdelkarim Andolerzak
 */
package lab4;

import java.util.ArrayList;

public class Partie {

    private ArrayList<Joueur> joueurs;

    Partie(int nb) {
        joueurs = new ArrayList<Joueur>();
        if (nb >= 2) {
            for (int i = 0; i < nb; i++) {
                Jeu jeu = new Jeu();
                jeu.battre();
                joueurs.add(new Joueur(jeu));
            }
        }
    }

    // M�thode qui va faire d�rouler les tours ainsi qu'appeller le d�compte
    // final
    public void jouer() {
        ArrayList<Joueur> gagnantTour = new ArrayList<Joueur>();
        Carte meilleureCarte = null, carteTiree;

        // Tant que le paquet du dernier joueur n'est pas vide, on tire encore
        // des cartes
        while (!joueurs.get(0).getPaquet().getJeu().isEmpty()) {
            for (Joueur joueurActuel : joueurs) {
                // Pour ne pas faire comparer meilleur (qui est joueur.get(0))
                // avec lui m�me
                if (gagnantTour.size() == 0) {
                    gagnantTour.add(joueurActuel);
                    meilleureCarte = joueurActuel.tirer();
                } else {
                    if (!joueurActuel.getPaquet().getJeu().isEmpty()) {
                        carteTiree = joueurActuel.tirer();
                        int comparaison = meilleureCarte.comparer(carteTiree);
                        if (comparaison == -1) {
                            gagnantTour.clear();
                            gagnantTour.add(joueurActuel);
                            meilleureCarte = carteTiree;
                        } else if (comparaison == 0) {
                            gagnantTour.add(joueurActuel);
                        }
                    }
                }
            }
            for (Joueur j : gagnantTour)
                j.gagner();

            gagnantTour.clear();
        }
        decompte();
    }

    void decompte() {
        ArrayList<Joueur> gagnants = new ArrayList<Joueur>();

        // Comparaison des points finaux
        for (Joueur j : joueurs) {
            if (gagnants.size() == 0) {
                gagnants.add(j);
            } else {
                int a, b;
                a = j.getNbPoints();
                b = gagnants.get(0).getNbPoints();
                if (a > b) {
                    gagnants.clear();
                    gagnants.add(j);
                } else if (a == b) {
                    gagnants.add(j);
                }
            }
        }
        resultats(gagnants);
    }

    // Methode pour afficher dans la console les gagnants ainsi que les points
    void resultats(ArrayList<Joueur> liste) {
        for (Joueur j : joueurs) {
            System.out.println("Joueur " + j.getId() + ": " + j.getNbPoints()
                    + " points");
        }

        for (Joueur j : liste) {
            System.out.println("Joueur " + j.getId() + " a gagn�");
        }
    }

    public static void main(String[] args) {
        int nbJoueurs = 3;
        Partie partieDeCartes = new Partie(nbJoueurs);
        partieDeCartes.jouer();
    }
}
