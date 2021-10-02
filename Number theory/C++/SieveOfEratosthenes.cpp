// Sieve of Eratosthenes is an efficent way to find all the prime numbers less than or equal to a given integer n

#include <iostream>
#include <cstring>
using namespace std;
 
void SieveOfEratosthenes(int n)
{
    int arr[n + 1];
    // Creating a integer array will all entries 0
    memset(arr, 0, sizeof(arr));
 
    for (int a = 2; a * a <= n; a++)
    {
        if (arr[a] == 0)
        {
            for (int i = a * a; i <= n; i += a)
                arr[i] = 1;
        }
    }
 
    // Print all arr numbers where arr[i] is 0
    for (int a = 2; a <= n; a++)
        if (arr[a] == 0)
            cout << a << " ";
}
 
// Driver Code
int main()
{
    int n = 14;
    cout << "Prime numbers less than or equal to " << n << " : ";
    SieveOfEratosthenes(n);
    return 0;
}