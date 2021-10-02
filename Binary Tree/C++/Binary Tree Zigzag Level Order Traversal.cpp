//Question Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void calc(vector<vector<int>>&ans, stack<TreeNode*>s,int p){
         vector<int>temp;
         stack<TreeNode*>s2;
         while(s.size()!=0){
             TreeNode *t=s.top();
             s.pop();
             temp.push_back(t->val);
             if(p==1){
                 if(t->left!=NULL) s2.push(t->left);
                 if(t->right!=NULL) s2.push(t->right);
             }
             else{
                 if(t->right!=NULL) s2.push(t->right);
                 if(t->left!=NULL) s2.push(t->left);
             }
             
         }
        if(temp.size()!=0) ans.push_back(temp);
        if(s2.size()!=0) calc(ans,s2,!p);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        stack<TreeNode*>s;
        s.push(root);
        calc(ans,s,1);
        return ans;
    }
};
