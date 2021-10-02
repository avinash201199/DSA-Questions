/* Question
  Kattapa, as you all know was one of the greatest warriors of his time. The kingdom of Maahishmati had never lost a battle under him (as army-chief), and the reason
  for that was their really powerful army, also called as Mahasena.
  Kattapa was known to be a very superstitious person. He believed that a soldier is "lucky" if the soldier is holding an even number of weapons, and "unlucky"
  otherwise. He considered the army as "READY FOR BATTLE" if the count of "lucky" soldiers is strictly greater than the count of "unlucky" soldiers, and "NOT READY" otherwise.
  Given the number of weapons each soldier is holding, your task is to determine whether the army formed by all these soldiers is "READY FOR BATTLE" or "NOT READY".
  https://www.codechef.com/problems/AMR15A          */

/* Input
   The first line of input consists of a single integer N denoting the number of soldiers. The second line of input consists of N space separated integers
   A1, A2, ..., AN, where Ai denotes the number of weapons that the ith soldier is holding.          */

/* Output
   Generate one line output saying "READY FOR BATTLE", if the army satisfies the conditions that Kattapa requires or "NOT READY" otherwise (quotes for clarity).    */

#include <iostream>
using namespace std;

int main()
{
    int t;
    int lucky=0,unlucky=0;

    cin>>t;
    for(int i=0;i<t;i++)
    {
        int m;
        cin>>m;
        if(m%2==0)
        lucky++;
        else
        unlucky++;


    }
    if(lucky>unlucky)
    cout<<"READY FOR BATTLE";
    else
    cout<<"NOT READY";
    return 0;
}
