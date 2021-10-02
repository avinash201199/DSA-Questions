#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10],int i, int j, int n){
    //checking in column above queen is placed
    for (int row = 0; row < i; ++row) {
        if(board[row][j] == 1){
            return false;
        }
    }

    //checking for left-upper diagonal
    int x = i;
    int y = j;

    while (x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    //checking for right-upper diagonal
    x = i;
    y = j;
    while (x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    //position is safe and we can place queen
    return true;
}

bool solveNQueen(int board[][10], int i, int n){
    if(i==n){
        //successfully placed queens in n rows
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if(board[j][k]==1)
                    cout<<"Q"<<" ";
                else
                    cout<<"_"<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    for (int j = 0; j < n; j++) {
        if(isSafe(board,i,j,n)){

            board[i][j] = 1;

            bool nextQueen = solveNQueen(board,i+1,n);
            if(nextQueen){
                return true;
            }
            board[i][j] = 0;
        }
    }

    //tried for all position in current row and queen couldn't be placed
    return false;

}

int main(){
    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNQueen(board,0,n);
return 0;
}
