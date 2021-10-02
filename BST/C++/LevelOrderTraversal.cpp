#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void LevelOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    queue<Node*>que;
    que.push(root);
    que.push(NULL);
    
    while(!que.empty())
    {
        Node*node = que.front();
        que.pop();

        if(node != NULL)
        {
            cout<<node->data<<" ";
            if(node->left != NULL)
            {
                que.push(node->left);
            }
            if(node->right != NULL)
            {
                que.push(node->right);
            }
        }
        else if(!que.empty())
        {
            que.push(NULL);
        }
    }
}
