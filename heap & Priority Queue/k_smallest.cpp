#include<iostream>
#include<queue>
using namespace std;

void ksort(int input[], int k, int n){
    priority_queue<int> p;
    int s=0, i=0;

        for(i=0; i<k; i++){
            p.push(input[i]);
        }

    while(i<n){
        if(input[i]<p.top()){
            p.pop();
            p.push(input[i]);
        }
        i++;
    }

    for(int i=0; i<k; i++){
        cout<<p.top()<<endl;
        p.pop();
    }

    
}

int main(){
    int input[7] = {5, 6, 9, 12, 3, 13, 2};
    int k= 3, n =7;
    cout<<"chalia suru kerta hai"<<endl;

    ksort(input, k, n);

    // for(int i=0; i<n; i++) cout<<input[i]<<endl;

    

    return 0;

}