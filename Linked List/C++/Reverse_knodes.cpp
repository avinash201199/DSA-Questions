#include <iostream>
using namespace std;

class node{

  public:
  int data;
  node* next;

  node(int data){
    this->data = data;
    next = NULL;
  }
};

void insertathead(node* &head,int data){
  if(head == NULL){
    head = new node(data);
    return;
  }

  node* n = new node(data);
  n->next = head;
  head = n;
}

void print(node * head){
  while(head!=NULL){
    cout<<head->data<<"-->";
    head = head->next;
  }
  cout<<endl;
}

node* kreverse(node* head, int k){

  if(head == NULL){
    return NULL;
  }

  node* prev = NULL;
  node* current = head;
  node* temp;
  int cnt = 1;

  while(current!=NULL and cnt<=k){
    temp=current->next;
    current->next = prev;

    prev=current;
    current = temp;
    cnt++;
  }

  if(temp!=NULL){
   head->next = kreverse(temp, k); 
  }

  return prev;
}

int main(){
  node* head = NULL;
  insertathead(head,4);
  insertathead(head,3);
  insertathead(head,2);
  insertathead(head,1);
  insertathead(head,0);

  print(head);
  head = kreverse(head, 3);
  print(head);

  return 0;
}