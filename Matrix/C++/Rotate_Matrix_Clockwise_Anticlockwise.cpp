#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> v){
    int n = v.size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<v[i][j]<<" ";
        }cout<<"\n";
    }
}

void clockwiseRotate(vector<vector<int>> a){
    int n = a.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(a[i][j], a[j][i]);
    for(int i=0;i<n;i++)
    {
        int start = 0, end = n-1;
        while(start < end){
            int t = a[i][start];
            a[i][start]  = a[i][end];
            a[i][end] = t;
            start++,end--;
        }
    }
    cout<<"\nClockwise Rotation:\n";
    display(a);
}

void anticlockwiseRotate(vector<vector<int>> a){
    int n = a.size();
    for(int i=0;i<n;i++)
        {
            int start = 0, end = n-1;
            while(start < end){
                int t = a[i][start];
                a[i][start]  = a[i][end];
                a[i][end] = t;
                start++,end--;
            }
        }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(a[i][j], a[j][i]);
    cout<<"\nAnti - Clockwise Rotation:\n";
    display(a);
    
}

int main()
{
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    
    vector<vector<int>>v(n, vector<int>(n));
    cout<<"Enter the elements of the matrix: ";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
        }
    }
    cout<<"\nMatrix:\n";
    display(v);
    
    clockwiseRotate(v);
    anticlockwiseRotate(v);
    
    return 0;
}
