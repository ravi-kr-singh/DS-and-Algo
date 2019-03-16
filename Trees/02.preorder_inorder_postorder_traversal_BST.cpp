#include <iostream>
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
void preorder_traversal(t_node* root){
  if(root!=NULL){
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }
}
void postorder_traversal(t_node* root){
  if(root!=NULL){
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
  }
}
void inorder_traversal(t_node* root){
  if(root!=NULL){
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
  }
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
  cout<<"Preorder traversal : ";
  preorder_traversal(ROOT);
  cout<<"\nInorder traversal : ";
  inorder_traversal(ROOT);
  cout<<"\nPostorder traversal : ";
  postorder_traversal(ROOT);
}
