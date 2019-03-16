#include <iostream>
#include <queue>
using namespace std;

struct t_node{
    int data;
    t_node* left;
    t_node* right;
    t_node(int item){
      data=item;
      left=NULL;
      right=NULL;
    }
};

t_node* insert_data(t_node* root,int item){
  if(root==NULL)
    root=new t_node(item);
  else if(item<=root->data)
    root->left=insert_data(root->left,item);
  else
    root->right=insert_data(root->right,item);
  return root;
}

void level_order(t_node* root){
  if(root!=NULL){
    queue<t_node*> store;
    store.push(root);
    while(!store.empty()){
      t_node* temp=store.front();
      cout<<temp->data<<" ";
      if(temp->left!=NULL)
        store.push(temp->left);
      if(temp->right!=NULL)
        store.push(temp->right);
      store.pop();
    }
  }
  else
    cout<<"\nTree is empty!";
}



int main() {

  t_node* ROOT=NULL;
  ROOT=insert_data(ROOT,45);
  ROOT=insert_data(ROOT,20);
  ROOT=insert_data(ROOT,50);
  ROOT=insert_data(ROOT,15);
  ROOT=insert_data(ROOT,55);
  ROOT=insert_data(ROOT,48);
  ROOT=insert_data(ROOT,10);
  ROOT=insert_data(ROOT,18);
  cout<<"Level order traversal : ";
  level_order(ROOT);
}
