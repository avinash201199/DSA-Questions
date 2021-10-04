#include<bits/stdc++.h>
using namespace std;
template<class type>
class BST{
    public:
        type data;
        BST<type> *left_child;
        BST<type> *right_child;
        BST(type data){
            this->data = data;
            this->left_child = NULL;
            this->right_child = NULL;
        }
        ~BST(){
            delete left_child;
            delete right_child;
        }
};
void insert_into_BST(BST<int> **root,int data_to_insert){
    if((*root)==NULL){
        *root = new BST<int>(data_to_insert);
    }
    else{
        if((*root)->data>data_to_insert){
            if((*root)->left_child==NULL){
                (*root)->left_child = new BST<int>(data_to_insert);
            }
            else{
                insert_into_BST(&((*root)->left_child),data_to_insert);
            }
        }
        else{
            if((*root)->right_child==NULL){
                (*root)->right_child = new BST<int>(data_to_insert);
            }
            else{
                insert_into_BST(&((*root)->right_child),data_to_insert);
            }
        }
    }
}
void display_BST(BST<int> *root){
    if(root==NULL)
        return;
    queue<BST<int>*> queue_item;
    queue_item.push(root);
    while(!queue_item.empty()){
        BST<int> *front_node = queue_item.front();
        queue_item.pop();
        cout<<front_node->data<<": ";
        if(front_node->left_child!=NULL){
            cout<<"L->"<<front_node->left_child->data<<" ";
            queue_item.push(front_node->left_child);
        }
        if(front_node->right_child!=NULL){
            cout<<"R->"<<front_node->right_child->data;
            queue_item.push(front_node->right_child);
        }
        cout<<endl;
    }
}
void search_into_BST(BST<int> *root,int data_to_search,BST<int> *prev_node=NULL){
    if(root==NULL){
        cout<<"Element not found!";
        return;
    }
    if(root->data==data_to_search){
        if(prev_node!=NULL){
            cout<<"Element Found, Parent Node: "<<prev_node->data;
        }
        else{
            cout<<"Element Found at Root!";
        }
    }
    if(data_to_search>root->data)
        search_into_BST(root->right_child,data_to_search,root);
    if(data_to_search<root->data)
        search_into_BST(root->left_child,data_to_search,root);
}
int main(){
    BST<int> *root = NULL;
    insert_into_BST(&root,4);
    insert_into_BST(&root,2);
    insert_into_BST(&root,6);
    insert_into_BST(&root,5);
    insert_into_BST(&root,7);
    insert_into_BST(&root,1);
    insert_into_BST(&root,3);
    display_BST(root);
    search_into_BST(root,10);
}
