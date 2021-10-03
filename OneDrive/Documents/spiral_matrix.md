class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int minr = 0;
        int minc = 0;
        int m = matrix.length;
        int n = matrix[0].length;
        int maxr = m-1;
        int maxc = n-1;
        int tne = m * n;
        int cnt = 0;
        ArrayList one = new ArrayList();
        while(cnt<tne){
            //top wall
            for(int i = minr, j = minc; j <= maxc && cnt < tne; j++){
                one.add(matrix[i][j]);
                cnt++;
            }
            minr++;
            //rgt wall
            for(int i = minr, j = maxc; i <= maxr && cnt < tne; i++){
                one.add(matrix[i][j]);
                cnt++;
            }
            maxc--;
            //btm wall
            for(int i = maxr, j = maxc; j >= minc && cnt < tne; j--){
                one.add(matrix[i][j]);
                cnt++;
            }
            maxr--;
            //lft wall
            for(int i = maxr, j = minc; i >= minr && cnt < tne; i--){
                one.add(matrix[i][j]);
                cnt++;
            }
            minc++;
        }
        return one;
    }
}