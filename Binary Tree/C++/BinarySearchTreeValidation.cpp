//Intuition ----

//For every Node check if it's value is under the boundaries.
//
//Implementation
//Visit a Node and check if its, value lies between lo and hi. If it does not, then the Tree is Not a BST and return False, else check for its subtrees and update the value of hi with the current's root val for Left subtree and update the value if lo with the current's root val for Right subtree.
//
//If the root becomes NULL at any point return True, as that entire branch satisfies the conditions of BST.
//
//Time Complexity
//Every Node is visited only Once, so T.C. is O(n)
//
//Space Complexity
//space is required for Recursion stack, so S.C. is O(n)


//Solution -----

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool isBST(Tree* root, int lo, int hi) {
    if (root == NULL) return 1;
    if (root->val < lo or root->val > hi) return 0;

    return isBST(root->left, lo, root->val) and isBST(root->right, root->val, hi);
}

bool solve(Tree* root) {
    return isBST(root, INT_MIN, INT_MAX);
}
