`#include<bits/stdc++.h>
using namespace std;
int main()
{
  cout<<"Enter Size of array"<<endl;;
  int n;
  cin>>n;
  int a[n];
  cout<<"Enter value of arrays"<<endl;;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  vector <int>b,c;
  cout<<"Enter value of k"<<endl;
  int k;
   cin>>k;
   k=k%n; // if value of k greater then size of array
   for(int i=0;i<k;i++)
   {
     b.push_back(a[i]);
   }
   for(int i=k;i<n;i++)
   {
     c.push_back(a[i]);
   }
   for(int i=0;i<b.size();i++)
   {
     c.push_back(b[i]);
   }
   for(int i=0;i<c.size();i++)
   {
     cout<<c[i]<<" ";
   }
   cout<<endl;
}



## OUTPUT:
```c++
Enter number of array elements: 10
Enter the array elements:
12 23 34 45 56 67 78 89 90 19 
Enter k: 4

Array after left rotation by k elements:
 
56 67 78 89 90 19 12 23 34 45 