/* Given a rod of length n inches and an array of 
prices that includes prices of all pieces of size 
smaller than n. Determine the maximum value obtainable 
by cutting up the rod and selling the pieces. */

/* SAMPLE INPUT:
Enter the length of the rod: 5
Enter the prices of:
Length 1: 1
Length 2: 5
Length 3: 8
Length 4: 9
Length 5: 10 */

/* SAMPLE OUTPUT:
Minimum cost to cut the Rod: 13 */

# include <iostream>
using namespace std;

int cutRod(int p[],int n){
  int r[n+1];
  r[0]=0;
  int q;
  for(int i=1; i<=n; i++){
    q=-1;
    for(int j=1; j<=i; j++){
      if(q<p[j]+r[i-j]){
        q=p[j]+r[i-j];
      }
    }
    r[i]=q;
  }
  return r[n];
}

int main(){
  int n;
  cout<<"Enter the length of the rod: ";
  cin>>n;
  int p[n+1];
  p[0]=0;
  cout<<"Enter the prices of: "<<endl;
  for(int i=1; i<=n; i++){
    cout<<"Length "<<i<<": ";
    cin>>p[i];
  }
  int result=cutRod(p, n);
  cout<<"----------------------------------"<<endl;
  cout<<"Minimum cost to cut the Rod: "<<result;
  return 0;
}