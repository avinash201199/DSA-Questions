
#include <bits/stdc++.h>
using namespace std;

int findMinOps(int arr[], int n)
{
    int ans = 0;

    for (int i = 0, j = n - 1; i <= j;)
    {

        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }

        else if (arr[i] > arr[j])
        {

            j--;
            arr[j] += arr[j + 1];
            ans++;
        }

        else
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of minimum operations is "
         << findMinOps(arr, n) << endl;
    return 0;
}
