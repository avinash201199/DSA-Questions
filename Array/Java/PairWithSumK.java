import java.util.HashSet;
import java.util.Scanner;

public class PairsWithSumK
{
    public static void findPairByNestedLoop(int[] arr, int sum)
    {
        for (int i = 0;i<arr.length;i++)
        {
            for (int j = i+1;j<arr.length;j++)
            {
                if (arr[i] + arr[j] == sum)
                {
                    System.out.print(" (" + arr[i] + "," + arr[j] + ") ");
                }
            }
        }
    }

    public static void findPairsUsingHashset(int [] arr,int sum)
    {
        HashSet<Integer> hashSet = new HashSet<>();
        for (int j : arr)
        {
            int temp_val = sum - j;
            if (hashSet.contains(temp_val))
            {
                System.out.print(" (" + j + "," + temp_val + ") ");
            }
            else
            {
                hashSet.add(j);
            }
        }
    }


    public static void main(String[] args)
    {
        System.out.print("Enter the Size of Array : ");
        Scanner scanner = new Scanner(System.in);
        int size_array = scanner.nextInt();

        int[] arr = new int[size_array];
        System.out.println("Enter the  Array : ");

        for(int i = 0;i<size_array;i++)
        {
            arr[i] = scanner.nextInt();
        }

        System.out.println("Entered array is : ");
        for (Integer s : arr)
        {
            System.out.print(s);
        }

        System.out.println("Enter sum for which you want to find pair : ");
        int sum = scanner.nextInt();

        //findPairByNestedLoop(arr,sum);
        findPairsUsingHashset(arr,sum);

    }
}

