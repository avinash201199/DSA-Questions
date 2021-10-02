/*FIND MEDIAN IN A STREAM*/

/*Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.
EG.-
Input- N=4
           X[ ] ={5,15,1,3}
Output-      5
             10
             5
	         4 */

/*The above question can be approached using maxheap and minheap concept .
The time complexity for the below solution is O(NLogN).
The space complexity for the below solution is O(N). */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    priority_queue<int> left;  //MAXHEAP to store the elements smaller than "x"
    priority_queue<int, vector<int> , greater<int>> right; //MINHEAP to store elements greater than "x"
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(left.empty() || x<left.top()){
            left.push(x);
        }
        else{
            right.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int l=left.size();
        int r= right.size();
        
        if(l-r>1){
            right.push(left.top());
            left.pop();
        }
        else if( r-l >1){
            left.push(right.top());
            right.pop();
        }
    }
     //Function to calculate and return Median.
    double getMedian()
   {
        int l=left.size();
        int r= right.size();
        
        if(l-r>1){
            right.push(left.top());
            left.pop();
        }
        else if( r-l >1){
            left.push(right.top());
            right.pop();
        }
   }
}; 
int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}

 



