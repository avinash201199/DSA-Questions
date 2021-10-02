/**
    Question: Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

    A Pascal's Triangle representation:        Indices
                    1                       ---> 0
                1       1                   ---> 1
            1       2       1               ---> 2
        1       3       3       1           ---> 3
    1       4       6       4       1       ---> 4

    Sample Input: 3
    Sample Output: [1, 3, 3, 1]
    Explanation: Here, as you can see from the Pascal's triangle we at 3rd index we have the row as (1, 3, 3, 1)
                And we have to return that as the answer as list.

    Constraints: 0 <= rowIndex <= 33

     */


public class PascalsTriangle{

     /**
     Here, this problem can be solved using recursion but only using recursion would result in 
     TLE -> Time Limit Exceeded. 

     For that we need to use memoization in order to decrease repeated calculations. This is basically 
     a trade off between space and time complexity. 

     The recursive relation can be written as : 

     f(nth-row, nth-index) = f((n-1)th-row, (n-1)th-index) + f((n-1)th-row, nth-index)

     Here the base cases are :
     f(0,0) => 1 , f(n, -1) => 0 and f(n, n+1) => 0

     If we want to store the intermediate results using memoization then we can change this recurrence relation later
     to include the matrix that is used to store the results.
     matrix of size [rowIndex + 1][rowIndex + 1]
     
      */


    // Here the getRow function will return the row of the pascal's triagnle of which index it's asked
    public List<Integer> getRow(int rowIndex) {
        // if row index is 3 so max numbers can be 4 and max index of list is 3
        List<Integer> row = new ArrayList<>();
        
        // The requirement of the for loop is to make the list 
        // individual element calculation will be from recursion

        
        // base case f(0,0) => 1 , f(n, -1) => 0 and f(n, n+1) => 0
        // using memoization to store some results
        int[][] dp = new int[rowIndex+1][rowIndex+1];
        
        for(int i=0; i<=rowIndex; i++){
            row.add(getElement(rowIndex, i, dp));
        }
        
        return row;
        
    }
    
    public int getElement(int row, int index, int[][] dp){
        
        // base cases
        if(row == 0 && index == 0)
            return 1;
        
        if(index == -1)
            return 0;
        
        if(index == row+1)
            return 0;
        
        // if that is present before 
        if(dp[row][index] != 0)
            return dp[row][index];
        
        int element = getElement(row-1, index-1, dp) + getElement(row-1, index, dp);
        
        
        // store the result
        dp[row][index] = element;
        
        return element;
        
    }


    public static void main(String[] args){
        // sample test case to run 
        int rowIndex = 3;

        // making an object of the class
        PascalsTriangle triangle = new PascalsTriangle();
        System.out.println(Arrays.toString(triangle.getRow(rowIndex)));
    }
}