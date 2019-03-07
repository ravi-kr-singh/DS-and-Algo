#include <iostream>
#include <queue>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
  node(int);
};
node::node(int x){
  data=x;
  left=NULL;
  right=NULL;
}

void insertion(int data,node*& root){
  if(root==NULL){
    node* new_node=new node(data);
    root=new_node;
  }
  else{
    if(data<=root->data)
      insertion(data,root->left);
    else
      insertion(data,root->right);
  }
}

bool search_element(node* root,int x){
  if(root==NULL)
    return false;
  else if(root->data==x)
    return true;
  else if(x<=root->data)
    search_element(root->left,x);
  else
    search_element(root->right,x);

}

int max_element(node* root){
  while(root->right!=NULL)
    root=root->right;
  return root->data;
}
int min_element(node* root){
  while(root->left!=NULL)
    root=root->left;
  return root->data;
}

int find_height(node* root){
  if(root==NULL)
    return -1;
  else
    return max(find_height(root->left),find_height(root->right))+1;
}

void Level_order_traversal(node* root){
  if(root!=NULL){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
      cout<<(q.front())->data<<" ";
      if(q.front()->left!=NULL)
        q.push(q.front()->left);
      if(q.front()->right!=NULL)
        q.push(q.front()->right);
      q.pop();
    }

  }
}

void Inorder_traversal(node* root) {
  if(root!=NULL){
    Inorder_traversal(root->left);
    cout<<root->data<<" ";
    Inorder_traversal(root->right);
  }
}

int main() {
  node* root=NULL;
  insertion(5,root);
  insertion(12,root);
  insertion(76,root);
  insertion(55,root);
  insertion(23,root);
  insertion(89,root);
  insertion(12,root);
  insertion(15,root);
  insertion(14,root);
  insertion(-1,root);
  insertion(3,root);
  insertion(1,root);
  cout<<"Max Element : "<<max_element(root)<<endl;
  cout<<"Min Element : "<<min_element(root)<<endl;
  cout<<"Height OF tree : "<<find_height(root)<<endl;
  int element;
  cout<<"Level order traversal : ";
  Level_order_traversal(root);
  cout<<endl;
  cout<<"Inorder traversal : ";
  Inorder_traversal(root);
  cout<<endl;
  cout<<"Enter element you want to search : ";
  cin>>element;
  search_element(root,element) ? cout<<"Found :)" : cout<<"Not Found :(" ;

  return 0;
}
