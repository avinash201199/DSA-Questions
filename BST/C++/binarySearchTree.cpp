#include <iostream>
using namespace std;

// We are creating a new class named BST.
class BST{
    /* This class includes class data members int data for storing key
       and BST pointer left and right to store left and right subtree resp. */
    int data;
    BST *left, *right;

  public:
    // default constructor
    BST(){}

    // parameterized constructor
    BST(int Data){  
        data = Data; left = NULL; right = NULL;
    };
    
    /* 
    inserting a left node in the BST
       it has parameters - 
           root - root node
           Data - node element to be inserted in the BST
    */
    BST* insert(BST *root, int Data){
        /* if root is equal to NULL
           then we are returning a new BST object with data as Data */
        if (!root)
            return new BST(Data);
        
        /* else if root's key is greater than Data,
           then we are inserting the new node at left subtree */
        else if(root->data > Data)
            root->left = insert(root->left, Data);
        
        /* else if root's key is lesser than Data,
           then we are inserting the new node at right subtree */
        else
            root->right= insert(root->right, Data);
        
        //We are returning the root back to the function call from main
        return root;
    }
    
    /* displaying the BST following inorder traversal
        Inorder Traversal Steps:-
            1. Left Node
            2. Root Node
            3. Right Node
    */
    void displayBST(BST* root){
        if(root!=NULL){
            displayBST(root->left);
            cout<<root->data<<" ";
            displayBST(root->right);
        }
    }
    
    /* 
    searching if the given node is present in the BST
        it has parameters - 
           root - root node
           element - node element to be searched in the BST
    */
    int searchBST(BST* root, int element){
        if(root == NULL) return 0;  // the element is not present
        if(root->data == element)   // the element is present
            return 1;
        
        /* if root's key is greater than element, 
           then element is present in left subtree */
        else if(root->data > element)
            return searchBST(root->left, element);

        /* if root's key is lesser than element, 
           then element is present in right subtree */
        else
            return searchBST(root->right, element);
        
    }
    
    /* 
    deleting the given node from the BST
        it has parameters - 
           root - root node
           element - node element to be deleted from the BST
    */
    BST* deleteBST(BST* root, int element){
        // if element is not present, then return NULL
        if(root == NULL)
            return root;
        
        if (root->data > element)
            root->left = deleteBST(root->left, element);
        else if (root->data < element)
            root->right = deleteBST(root->right, element);
        
        // if the element is found
        else{
            // if there are no child nodes
            if(root->right == NULL && root->left == NULL)
                return NULL;

            // if there is a right child node
            else if (root->left == NULL)
                return root->right;

            // if there is a left child node
            else if (root->right == NULL)
                return root->left;
            
            // if there is both left and right child node
            BST* temp = root->right;
            // using while loop to get minimum node from right subtree
            while(temp->left) temp = temp->left;
            // replacing the minimum node from right subtree with the root node
            root->data = temp->data;
            // deleting the minimum node from the right subtree
            root->right = deleteBST(root->right, temp->data);
        }
        // We are returning the root back to the function call from main
        return root;
    }
};

// driver function code - main()
int main(){
    int size, i, element;
    BST BSTree, *root = NULL;
    
    cout<<"Number of nodes of BST : ";
    cin>>size;
    
    cout<<"Enter the node elements to insert"<<endl;
    for(i=0;i<size;i++){
        cin>>element;
        root = BSTree.insert(root, element);
    }
    
    cout<<"The Binary Tree in inorder traversal is - ";
    BSTree.displayBST(root);
    
    cout<<endl<<"Enter the element to be searched : ";
    int search;
    cin>>search;
    int found = BSTree.searchBST(root, search);
    if(found == 1) cout<<"The element is found"<<endl;
    else cout<<"The element is not found"<<endl;
    
    cout<<endl<<"Enter the element to be deleted : ";
    int del;
    cin>>del;
    root = BSTree.deleteBST(root, del);
    
    cout<<"The Binary Tree in inorder traversal after deletion is - ";
    BSTree.displayBST(root);
    
    return 0;
}