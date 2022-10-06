#include<iostream>
#include<queue>
using namespace std;

void ksort(int input[], int k, int n){
    priority_queue<int> p;
    int s=0, i=0;

        for(i=0; i<k; i++){
            p.push(input[i]);
        }
        // i=0; bhai i ko bas k tak le ke gya hai
        while(i<n){
        input[s]= p.top();
        p.pop();
        p.push(input[i]);
        i++;
        s++;
        }

        while(k--){
        input[s]= p.top();
        p.pop();
        s++;            
        }
    
}

int main(){
    int input[5] = {10,12, 6, 7,9};
    int k= 3, n =5;

    ksort(input, k, n);

    for(int i=0; i<n; i++) cout<<input[i]<<endl;

    

    return 0;

}