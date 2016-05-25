package ads.lab7;

/**
 * A class to handle disjoint sets
 */
public class DisjointSets {

    // FAther or siZE: if faze[i] >= 0, faze[i] is the father of i in the up-tree
    // else i is the root of the up-tree and -father[i] is the size of the up-tree
    private int faze[];

    // the current number of subsets
    private int numSets;

    /**
     * builds a disjoint set system of size n with
     * the n initial single-element sets
     * {0}, {1}, {2}, ..., {n-1}
     */
    public DisjointSets(int n) {
        faze = new int[n];

        for(int i = 0 ; i < n ; i++){
            faze[i] = -1;
        }

    }

    /**
     * returns the current number of
     * subsets in the disjoint set system
     */
    public int numSets() {
        int nb = 0;
        for (int i = 0; i < faze.length; i++) {
            if(faze[i]<0)  {
                nb++;
            }
        }
        return nb;
    }

    /**
     * returns the root of the
     * up-tree containing i doing
     * path compression
     */
    public int find(int i) {
        return faze[i] > 0 ? find(faze[i]) : i;
    }

    /**
     * performs the union of the two subsets
     * of roots root1 and root2
     */
    public void union(int root1, int root2) {
        if (faze[root1] < faze[root2]) {
            faze[root2] += faze[root1];
            faze[root1] = root2;
        } else {
            faze[root1] += faze[root2];
            faze[root2] = root1;
        }

    }

    ////////////// toString function, do not change this code!

    public String toString() {
        String s = "|";
        for (int i = 0; i < faze.length; i++)
            s += format(i) + "|";
        s += "\n+";
        for (int i = 0; i < faze.length; i++)
            s += "---+";
        s += "\n|";
        for (int i = 0; i < faze.length; i++)
            s += format(faze[i]) + "|";
        return s;
    }

    private String format(int n) {
        if (n >= 0 && n < 10)
            return "  " + n;
        if (n >= -9)
            return " " + n;
        return Integer.toString(n);
    }
}