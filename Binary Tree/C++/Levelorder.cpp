//Print the level order traversal of binary tree and Print the left view of binary tree andPrint right view of binary tree.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//Binary Tree Node
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

//Function for level order traversal og binary tree
void levelordertraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        
        if(node!=NULL)
        {
            // print all node at same level
            cout<<node->data<<" ";
            // Add left node to queue
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            // Add right node to queue
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        }
        
        else if(!q.empty())
        {
            q.push(NULL);
            cout<<endl;
        }
    }
}

// Function to print rightview of binary tree
void rightview(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
         // number of nodes at current level
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr=q.front();
            q.pop();
            // Print the right most element
            if(i==n-1)
            {
                cout<<curr->data<<" ";
            }
             // Add left node to queue
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            // Add right node to queue
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

// Function to print leftview of binary tree
void leftview(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        // number of nodes at current level
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr=q.front();
            q.pop();
            // Print the left most element
            if(i==1)
            {
                cout<<curr->data<<" ";
            }
            // Add left node to queue
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            // Add right node to queue
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

//driver code
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(9);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->left->right=new Node(9);
    root->left->right->left=new Node(5);
    root->right->left->right=new Node(6);
    levelordertraversal(root);
    cout<<endl<<endl<<"right view of Binary Tree "<<endl;
    rightview(root);
    cout<<endl<<endl<<"left view of Binary Tree "<<endl;
    leftview(root);

    return 0;
}
