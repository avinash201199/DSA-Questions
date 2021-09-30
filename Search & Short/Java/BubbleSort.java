public class BubbleSort {
    public static void main(String arg[]) {
        int a[] = { 5, 7, 3, 9, 11, 6, 24, 56, 35 };
        int l = a.length;
        for (int i = 0; i < l - 1; i++) {
            for (int j = 0; j < l - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    int t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
            }
        }
        for (int i = 0; i < l; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

}
