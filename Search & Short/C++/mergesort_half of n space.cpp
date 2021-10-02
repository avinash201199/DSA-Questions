#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int const left, int const mid, int const right){
    //temp vector, only copy the left part of arr
    vector<int> templeft;
    for(int i = 0 ; i < mid - left + 1; i++){
        templeft.push_back(arr[left + i]);
    }

    int indexleft = 0,
        indexright = mid + 1,
        indexmerge = left;

    //use right part of arr directly
    while(indexleft < (mid - left + 1) && indexright < right + 1){
        if(templeft[indexleft] <= arr[indexright])
            arr[indexmerge++] = templeft[indexleft++];

        else
            arr[indexmerge++] = arr[indexright++];
    }

    while(indexleft < templeft.size()){
        arr[indexmerge++] = templeft[indexleft++];
    }

    while(indexright < arr.size()){
        arr[indexmerge++] = arr[indexright++];
    }
}

void mergesort(vector<int> &arr, int const begin, int const end){
    if(begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergesort(arr, begin, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main(){
    vector<int> numlist = {3,6,4,17,1,13,10,45,777,55,35,3,22,89,5,7,8,4,0,2};
    mergesort(numlist, 0, numlist.size() - 1);

    for(int i = 0; i < numlist.size(); i++){
        cout << numlist[i] << " ";
    }
    cout << endl;
    return 0;

}
