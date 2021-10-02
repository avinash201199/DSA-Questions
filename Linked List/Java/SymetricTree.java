class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root==null)
            return true;
        return check(root.left,root.right);
    }
     public boolean check(TreeNode r1,TreeNode r2)
     {
         if(r1==null&&r2==null)
            return true;
         if(r1==null||r2==null)
             return false;
        
         return r1.val==r2.val&&check(r1.left,r2.right)&&check(r1.right,r2.left);
     }
    
}
