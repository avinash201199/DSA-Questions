//soultion to Find the pair which gives the sum same as assigned number by Amitlpu-840
#include <iostream>
using namespace std;

void pCount(int arr[], int n, int sum)
{
    int count = 0; // Initialize result

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                cout << "(" << arr[i] << "," << arr[j] << ")";
}

int main()
{
    int x;
    cout << "enter size of array :";
    cin >> x;
    int arr[x];
    cout << "enter elements of array :";
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    int sum;
    cout << "enter number of whose pair sum you want to find :";
    cin >> sum;
    pCount(arr, n, sum);
    return 0;
}
