#include <bits/stdc++.h>
using namespace std;

void permutation(char *in,int i){
    if(in[i]=='\0'){
        cout<<in<<endl;
        return;
    }

    for (int j = i; in[j]!='\0'; ++j) {
        swap(in[i],in[j]);
        permutation(in,i+1);
        swap(in[i],in[j]);
    }

}

int main(){

    char in[10];
    cin>>in;
    permutation(in,0);

return 0;
}
