#include <iostream>
#include<cmath>
using namespace std;
class node//make node
{   public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node *createpreordertree() //create tree
{
    int data;
    string s;
    cin>>s;
    if(s=="false")  //if false is entered
    {
        return NULL;
    }
    cin>>data;
    node *root=new node(data);     //make node for every new data entered
    root->left=createpreordertree(); //make left subtree by connecting only left part of each node
    root->right=createpreordertree();//make right subtree by connecting only right part of each node
    return root;                     //return a pointer as the type of function is a node* pointer
}
class HeightBalancedPair  //create a class
{
    public:
    int height;
    bool balance;
};
HeightBalancedPair p;  //p is an object
HeightBalancedPair check(node *root)
{   if(root==NULL)
    {p.height=0;     //for null values,height=0-0=0 which is less than 1
     p.balance=true; // hence the tree is balanced
     return p;
    }
    HeightBalancedPair left=check(root->left);  //left is an object of class that stores value of check for nodes of left subtree
    HeightBalancedPair right=check(root->right);//right is an object of class that stores value of check for nodes of right subtree
    p.height=max(left.height,right.height)+1;   //height=maximum height between right and left subtrees and add 1 for including root
    if(abs(left.height-right.height)<=1 && left.balance && right.balance) //if absolute difference of heights is <=1 and left,right subtrees are balanced
    {
        p.balance=true;                                                   //return true as tree is balanced
    }
    else
    {
        p.balance=false;                                                 //retrun false if condition is not satisfied
    }
    return p;
}
int main()
{     int data;
     cin>>data;
     node *root=new node(data);                           //make nodes for data
     root->left=createpreordertree();                     // make nodes for left subtree
      root->right=createpreordertree();                   // make nodes for right subtree
      if(check(root).balance==true)                       //if function returns true(note:function acts like an object)
      {
          cout<<"true";
      }
      else
      {
          cout<<"false";
      }
    return 0;
}
