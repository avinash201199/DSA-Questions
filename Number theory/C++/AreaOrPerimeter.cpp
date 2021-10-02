/* Question
   Write a program to obtain length (L) and breadth (B) of a rectangle and check whether its area is greater or perimeter is greater or both are equal.
   https://www.codechef.com/submit/AREAPERI             */

/* Input
   First line will contain the length (L) of the rectangle.
   Second line will contain the breadth (B) of the rectangle.       */

/* Output
   Output 2 lines.
   In the first line print "Area" if area is greater otherwise print "Peri" and if they are equal print "Eq".(Without quotes).
   In the second line print the calculated area or perimeter (whichever is greater or anyone if it is equal).
   Constraints
   1≤L≤1000
   1≤B≤1000        */

#include <iostream>
using namespace std;

int main() {
	int length, breadth;
	cin>>length>>breadth;
	int area, peri, sum;
	area=length*breadth;
	sum=length+breadth;
	peri=2*sum;
	if(area>peri)
	{
	    cout<<"Are\n";
	    cout<<area;
	}
	else if(peri>area)
	{
	    cout<<"Peri\n";
	    cout<<peri;
	}
	else if(peri==area)
	{
	    cout<<"Eq\n";
	    cout<<area;
	}
	return 0;
}
