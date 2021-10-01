/* This program is used to get Prime numbers in a given range with a better time complexity i.e( n log log n)

*/

#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    // Create a boolean array

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
              //change every multiple of a prime no to false
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

// Driver Code
int main()
{
    int n = 30;
    cout << "Follwoing are nos smaller than or equal to  "<< n << endl;
    SieveOfEratosthenes(n);
    return 0;
}
