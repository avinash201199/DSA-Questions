public class SelectionSort {
    public static void main(String arg[]) {
        int a[] = { 5, 7, 3, 9, 11, 6, 24, 56, 35 };
        int l = a.length;
        for (int i = 0; i < l; i++) {
            int min = i;
            for (int j = i + 1; j < l; j++) {
                if (a[min] > a[j])
                    min = j;
            }
            int t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
        for (int i = 0; i < l; i++) {
            System.out.print(a[i] + " ");
        }
    }

}
