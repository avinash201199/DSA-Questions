#include <bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int n, int m, int &total){

    if(i==n && j==m){
        soln[i][j] = 1;
        for (int k = 0; k <= n; ++k) {
            for (int l = 0; l <= m; ++l) {
                cout<<soln[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        total++;
        return true;
    }

    if(i>n || j>m)
        return false;

    if(maze[i][j] == 'X')
        return false;

    soln[i][j] = 1;
    bool right = ratInMaze(maze,soln,i,j+1,n,m,total);
    bool down = ratInMaze(maze,soln,i+1,j,n,m,total);

    soln[i][j] = 0;

    if(right || down)
        return true;

    return false;

}

int main(){

    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0X00"};

    int n = 4, m = 4;

    int soln[10][10] = {0};
    int total_paths = 0;

    bool ans = ratInMaze(maze,soln,0,0,n-1,m-1,total_paths);

    if(ans == false){
        cout<<"Path doesn't exist"<<endl;
    }else{
        cout<< total_paths;
    }


return 0;
}
