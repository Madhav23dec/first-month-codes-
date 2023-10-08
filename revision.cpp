#include <bits/stdc++.h>
#include <vector>
using namespace std;

class node
{
public:
  int data ;
  node* left;
  node* right;

  //constructor
  node(int data)
  {
    this->data=data;
    left=NULL;
    right=NULL;
  }
};
node* BuildTree( node* root)
{
  cout<<"enter the data"<<endl;
  int data;
  cin>>data;
  root= new node(data);

  if(data==-1)
  {
    return NULL;
  }

  cout<<"enter the data for left node of "<<data<<endl;
  // recursion for buiding left nodes
  root->left= BuildTree(root->left);

  cout<<"enter the data for right node of "<<data<<endl;
  //recursive call
  root->right= BuildTree(root->right);

  return root;
}
void InorderTraversal( node* root)
{
  if(root==NULL)
  { return;}
// left most call
  InorderTraversal(root->left);
  //printing the root data after returning from left
  cout<<root->data<<" ";
  //goint to the right tree
  InorderTraversal(root->right);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif

  node* root=NULL;
  root=BuildTree(root);
  // int cnt=0;
  // Number_leaf_nodes(root , cnt);
  // cout<<endl;
  // cout<<cnt<<endl;

InorderTraversal(root);
return 0;
}
