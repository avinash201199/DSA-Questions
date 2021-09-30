### Given an array ar of n integers and an element k. Rotate the array by k elements in anti-clockwise direction.
```c++
#include<iostream> 
using namespace std;

int main()
{
  int n,i,k,first_elem,j;  // declaring variables
  cout<<"Enter number of array elements: ";
  cin>>n;
  int a[n];
  cout<<"Enter the array elements:\n";
  for(i=0;i<n;i++){
    cin>>a[i];    //initializing the array values.
  }
  cout<<"Enter k: ";
  cin>>k;   //number of elements by which array is to be rotated.
  
  for(i=0;i<k;i++)  //first loop
  {
    first_elem=a[0];
    for(j=0;j<n-1;j++)  //second loop i.e. nested loop
    {
      a[j]=a[j+1];
    }
    a[j]=first_elem;  
  }

cout<<endl;

//printing array elements after rotation
cout<<"Array after left rotation by k elements:\n "<<endl;  
for(i=0;i<n;i++)
{
  cout<<a[i]<<" ";  
}
}
```
