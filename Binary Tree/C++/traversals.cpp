#include<bits/stdc++.h>

using namespace std;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;

    Tree(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

// preorder
void preorder(Tree* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);

}

// inorder
void inorder(Tree* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

// postorder
void postorder(Tree* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

// level order traversal
void printLOT(Tree* root){
    if(root==NULL){
        return;
    }

    queue<Tree*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Tree* node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->val<<" ";

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

// zig-zag traversal
vector<int> ZigZagTrav(Tree* root) {
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    stack<Tree*> currLevel;
    stack<Tree*> nextLevel;

    bool LeftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty()){
        Tree* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            ans.push_back(temp->val);

            if(LeftToRight){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }
            else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }

        }

        if(currLevel.empty()){
            LeftToRight = !LeftToRight;
            swap(currLevel,nextLevel);
        }
    }


    return ans;
}

int main(){
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->right = new Tree(6);

    printLOT(root);
    cout<<endl;
    
    return 0;
}