package ads.lab6;

/**
 * A class for the quicksort algorithm
 */
public class QuickSort {

    private static final int CUTOFF = 10;

    /**
     * Sort the array in place using the quicksort algorithm
     */
    public static <AnyType extends Comparable<AnyType>> void sort(AnyType[] array) {
        sort(array, 0, array.length - 1);
    }

    /**
     * Sort the portion array[lo,hi] in place using the quicksort algorithm
     */
    private static <AnyType extends Comparable<AnyType>> void sort(AnyType[] array, int lo, int hi) {
        if (lo > hi)
            return;
        int pivot = partition(array, lo, hi);
        sort(array, lo, pivot - 1);
        sort(array, pivot + 1, hi);
    }

    /**
     * Partition the portion array[lo,hi] and return the index of the pivot
     */
    private static <AnyType extends Comparable<AnyType>> int partition(AnyType[] array, int lo, int hi) {
        int pivot = lo;

        for (int i = lo + 1; i <= hi; i++) {
            if (array[i].compareTo(array[pivot]) < 0) {
                pivot++;
                swap(array, pivot, i);
            }
        }
        swap(array, lo, pivot);
        return pivot;
    }

    /**
     * Return the index of the median of { array[lo], array[mid], array[hi] }
     */
    private static <AnyType extends Comparable<AnyType>> int median(AnyType[] array, int lo, int mid, int hi) {
        return 0;
    }

    /**
     * Sort array[lo, hi] in place using the insertion sort algorithm
     */
    private static <AnyType extends Comparable<AnyType>> void insertion(AnyType[] array, int lo, int hi) {

    }

    /**
     * Swap array[i] and array[j]
     */
    private static <AnyType> void swap(AnyType[] array, int i, int j) {
        AnyType tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}