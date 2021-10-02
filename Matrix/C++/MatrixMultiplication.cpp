#include <iostream>
using namespace std;
 
int main()
{
    //order of matrix A
    int r1 = 2, c1 = 3;
    
    //order of matrix B
    int r2 = 3, c2 = 2;
    
    //matrix A
    int m1[r1][c1] = {{1, 2, 3},
                      {1, 1, 1}};
    
    //matrix B
    int m2[r2][c2] = {{1, 2},
                      {1, 3},
                      {1, 1}};
    
    //Check order of Matrix A and B
    if(c1 != r2){
        cout << "Matrix  multiplaction Not possible for the given matrices";
    } else {
        //define order of the resultant matrix 
        int res[r1][c2];
     
        //Multiply the elements of A and B
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                int sum =0;
                for(int k=0; k<r2; k++){
                    sum += (m1[i][k] * m2[k][j]);
                }
                res[i][j] = sum;
            }
        }
        
        //output the resultant matrix
        cout << "Resultant Matrix: \n";
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                cout << res[i][j] << "\t";
            }
            cout << "\n";
        }
      
    }
    
    return 0;
}