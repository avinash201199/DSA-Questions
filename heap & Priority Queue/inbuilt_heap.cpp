#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int> p;
    p.push(16);
    p.push(32);
    p.push(45);
    p.push(7);
    p.push(167);
    p.push(1);


    cout<<"size  :"<<p.size()<<" and top element  : "<<p.top()<<endl;
    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
    return 0;

}