import java.util.Scanner;

/**
 * Write a program that reads an array of ints and outputs the maximum product of two adjacent elements 
 * in the given array.
 * Maximum_Product_Adjacent_Elements
 */
public class Maximum_Product_Adjacent_Elements {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tam = scanner.nextInt();
        int[] numbers = new int[tam];

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = scanner.nextInt();
        }

        int max = getMaxProductAdjacentElements(numbers);

        System.out.println("The maximum product: "  + max);

        scanner.close();
    }

    private static int getMaxProductAdjacentElements(int[] numbers) {

        if (numbers.length == 1) return numbers[0];

        int max = numbers[0] * numbers[1];

        for (int i = 1; i < numbers.length - 1; i++) {
            int temp = numbers[i] * numbers[i + 1];
            if (temp > max) {
                max = temp;
            }
        }

        return max;
    }

    
}