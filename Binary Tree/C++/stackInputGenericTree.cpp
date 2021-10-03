#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    vector<TreeNode*> children;
    TreeNode(int data){
        this->data=data;
    }
      ~TreeNode(){
        for(int i=0;i<children.size();i++){
        delete children[i]; //this will call the destructor of its children and go on deleting the children
        }
    }
};

// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1

TreeNode* constructTree(vector<int> &v){
    if(v.size()==0){
        return NULL;
    }
    stack<TreeNode*> s;
    TreeNode* root;
    for(int i=0;i<v.size();i++){
        if(v[i] == -1){
            s.pop();
        }else{
            TreeNode* temp = new TreeNode(v[i]);
            // cout<<temp->data<<endl;
            if(s.size()!=0){
                TreeNode* ptr = s.top();
                ptr->children.push_back(temp);                
            }else{
                root=temp;
            }
            s.push(temp);
        } 
    }
    
    return root;
} 

void printTree(TreeNode* root){
    if(root==NULL){
        cout<<"Empty"<<endl;
        return ;
    }
    cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    TreeNode* root = constructTree(v);
    cout<<"Input Taken"<<endl;
    printTree(root);
}