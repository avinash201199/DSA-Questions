#include<bits/stdc++.h>
using namespace std;

void heapit(int input[], int n){

    for(int i=1; i<n; i++){
        int child = i;
        
        
        while(child>0){
            int parent = (child-1)/2;
            if(input[parent]>input[child]){
                int temp = input[child];
                input[child]=input[parent];
                input[parent]=temp;
            }else break;
            child= parent;
        }
    }

    // now remove it

    for(int i= n-1; i>=0; i++){
        int parent = 0;
        int temp = input[parent];
        input[parent]= input[i];
        input[i] = temp;
        int left = (2*parent +1);
        int right = (2*parent +2);
        while(left<i){
            int min = parent;
            if(input[min]>input[left]){
                min= left;
            }
            if(right<i && input[left]>input[right]){
                min= right;
            }
            if(min==parent) break;
            int temp = input[parent];
            input[parent]= input[min];
            input[min] = temp; 
            parent = min;
            left = (2*parent +1);
            right = (2*parent +2);          
        }
    }

    
}

int main(){

    int input[5] = {5,1,2,0,8};

    heapit(input, 5);

    for(int i=0; i<5; i++) cout<<input[i]<<" ";
    cout<<endl;




    return 0;

}