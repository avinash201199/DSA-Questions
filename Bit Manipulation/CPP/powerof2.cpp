// n   = 6 = (0110)    flip rightmost 1 and after that to get n-1
// n-1 = 5 = (0101)    
// n & n-1 = (0100) difference of one bit i.e. rightmost 1

#include <iostream>
using namespace std;

bool ispowerof2(int n){
    return (n && !(n & n-1));
}

int main(){
    cout<<ispowerof2(16)<<endl;
    return 0;
}