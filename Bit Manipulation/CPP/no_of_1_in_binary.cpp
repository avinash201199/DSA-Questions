#include <iostream>
using namespace std;

int numof1(int n){
    int ans=0;
    while(n != 0){
        n = n & n-1;
        ans++;
    }
    return ans;
}

int main(){
    cout<<numof1(7)<<endl;
    return 0;
}