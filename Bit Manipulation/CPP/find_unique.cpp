#include <iostream>
using namespace std;
// one number is unique rest is present twice
int unique1(int a[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^a[i];
    }
    return xorsum;
}

// get bit in n at position pos
int getBit(int n,int pos){
    return ((n&(1<<pos))!=0);
}

//set bit in n at position pos 
int setBit(int n,int pos){
    return (n|(1<<pos));
}
// two numbers are unique 
void unique2(int a[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum^a[i];
    }  
    int tempxor=xorsum;
    int setbit=0;
    int pos=0;
    while (setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum>>1;
        
    }
    int newxor=0;
    for(int i=0;i<n;i++){
        if(getBit(a[i],(pos-1))){
            newxor=newxor^a[i];
        }
    }
    cout << newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}

//one is unique rest are present thrice 
int unique3(int arr[],int n){
    int ans = 0;
    for (int i=0;i<64 ;i++){
        int sum =0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)!=0){
                sum++;
            }
        }
        if(sum%3!=0){
            ans = setBit(ans,i);
        }
    }
    return ans;

}

int main(){
    int arr[7]={1,2,3,4,1,2,3};
    cout<<unique1(arr,7)<<endl;
    int a[10]={1,1,2,2,3,4,5,5,6,6};
    unique2(a,10);
    int A[10]={1,2,3,4,1,2,2,3,1,3};
    cout<<unique3(A,10)<<endl;
    return 0;
}