/*
  Problem Statement:
There are NN points on the 2D plane, ii-th of which is located on (xi,yi)(xi,yi). There can be multiple points that share
the same coordinate. What is the maximum possible Manhattan distance between two distinct points?
Here, the Manhattan distance between two points (xi,yi)(xi,yi) and (xj,yj)(xj,yj) is defined by |xi−xj|+|yi−yj||xi−xj|+|yi−yj|.
Constraints
•	2≤N≤2×1052≤N≤2×105
•	1≤xi,yi≤1091≤xi,yi≤109
•	All values in input are integers.
________________________________________
Input
Input is given from Standard Input in the following format:
NN
x1x1 y1y1
x2x2 y2y2
::
xNxN yNyN
Output
Print the answer.
________________________________________
Sample Input 1 
3
1 1
2 4
3 2
Sample Output 1 
4
The Manhattan distance between the first point and the second point is |1−2|+|1−4|=4|1−2|+|1−4|=4, which is maximum possible.
________________________________________
Sample Input 2 
2
1 1
1 1
Sample Output 2 
0
*/
/*
  Solution:
 |xi − xj | + |yi − yj |
 = max(xi − xj , xj − xi) + max(yi − yj , yj − yi)
 = max((xi − xj ) + (yi − yj ),(xi − xj ) + (yj − yi),(xj − xi) + (yi − yj ),(xj − xi) + (yj − yi)) 
= max(xi + yi − (xj + yj ), xi − yi − (xj − yj ), −(xi − yi) + (xj − yj ), −(xi + yi) + xj + yj ) 
= max(|xi + yi − (xj + yj )|, |xi − yi − (xj − yj )|)
 Therefore, let zi = xi + yi and wi = xi − yi , then |xi − xj | + |yi − yj | = max(|zi − zj |, |wi − wj |). This transformation
 is called ”45-degree rotation,” which is commonly used in problems that deal with Manhattan distances. With this formula, the 
 answer can be represented as follows: max 1≤i≤N,1≤j≤N |xi − xj ||yi − yj | 
= max 1≤i≤N,1≤j≤N max(|xi + yi − (xj + yj )|, |xi − yi − (xj − yj )|) 
= max( max 1≤i≤N,1≤j≤N |zi − zj |, max 1≤i≤N,1≤j≤N |wi − wj |) 
= max( max 1≤i≤N zi − min 1≤i≤N zi , max 1≤i≤N wi − min 1≤i≤N wi) 
Since the maximum and minimum values of zi and wi can be obtained in a total of O(N) time, one can derive the answer from them 
too. Sample Code
*/

// My code
1.	#include<bits/stdc++.h>
2.	using namespace std;
3.	 
4.	int main(){
5.	    int n;
6.	    long long zmi=2e9,zma=-2e9,wmi=2e9,wma=-2e9;
7.	    cin>>n;
8.	    while(n--){
9.		    long long x,y;
10.		    cin>>x>>y;
11.		    zmi=min(zmi,x+y);
12.		    zma=max(zma,x+y);
13.		    wmi=min(wmi,x-y);
14.		    wma=max(wma,x-y);
15.	    }
16.	    cout<<max(zma-zmi,wma-wmi)<<"\n";
17.	}
