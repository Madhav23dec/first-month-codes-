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

node* BuildTree( node*  root)
{
  cout<<" enter the data"<<endl;
  int data;
  cin>>data;
    if(data==-1)
    return NULL;
  root=new node(data);
  cout<<" enter the data for the left of "<<data<<endl;
  root->left = BuildTree(root->left);
  cout<<" enter the data for the right of "<<data<<endl;
  root->right = BuildTree(root->right);

  return root;
}

void InorderTraversal( node* root)
{
  if(root->left==NULL && root->right==NULL)
  {cout<<root->data<<" ";
  return;}

  InorderTraversal(root->left);
  cout<<root->data<<" ";
  InorderTraversal(root->right);
}

int height( node* root)
{
  if(root==NULL)
    return 0;

  int l= height(root->left);
  int r= height(root->right);

  return max(l,r)+1;
}

class diameter
{
public:

int diameterSlow( node* root)
{
  if(root==NULL)
    return 0;

  int opt1 = diameterSlow(root->left);
  int opt2= diameterSlow(root->right);
  int opt3= height(root->left)+ height(root->right)+1;

  int ans = max(opt1,max(opt2,opt3));
  return ans;
}

pair<int,int> diameterFast( node*root)
{
  //pair (diameter, height(means the max ) )
  if(root==NULL)
  {pair<int,int>p= make_pair(0,0);
    return p;}

  pair<int,int> left = diameterFast(root->left);
  pair<int,int> right = diameterFast(root->right);

  int leftHeight = left.second;
  int rightHeight =right.second;
  int dia_Value = left.second + right.second + 1;

  pair<int,int> ans;
  ans.first= max(leftHeight, max(rightHeight , dia_Value));
   ans.second= max(leftHeight,rightHeight)+1;

  return ans;
}
};
{
bool balanced_tree (node* root)
{
  if(root==NULL)
    return true;

  bool left = balanced_tree(root->left);
  bool right = balanced_tree(root->right);

  if( abs(height(root->left)-height(root->right)) <1 )
    return true;
  else
    return false;
}
bool identical( node*root1 , node* root2)
{
  if(root1==NULL && root2==NULL)
    return true;
  else if(root1==NULL && root2!=NULL) {
    return false;}
  else if (root1!=NULL && root2==NULL){
    return false ;}

  bool left=identical(root1->left , root2->left);
  bool right=identical(root1->right, root2->right);

  if(left&& right && root1->data==root2->data)
  return true;
  else
  return false;
}
class sumTree
{
public:
void ss(pair<int, int> &p, int e, int f)
{
  p.first=e;
  p.second=f;
}

pair<bool,int> sum_tree(node* root)
{
  if(root==NULL)
  {  pair<bool,int> p= make_pair(true,0);
    return p;}

  if(root->left == NULL && root->right == NULL )
  {
    pair<bool,int> p = make_pair(true, root->data);
    return p;
  }


  pair<bool,int> left= sum_tree(root->left);

  pair<bool,int> right= sum_tree(root->right);

  bool isLeftSumTree = left.first;
  bool isRightSumTree = right.first;

  bool condition= (right.second + left.second == root->data);

  int leftSum = left.second;
  int rightSum = right.second;

  pair<bool,int> ans;
  if(isLeftSumTree && isRightSumTree && condition)
  {ans.first= true;
  ans.second= root->data;}
  else
    {ans.first=false;}

  return ans ;

}
};



class boundary_traversal
{

public:

void left_print_noLeaf( node* root)
{
  if(root->left==NULL)
    return;
  cout<<root->data<<" ";
  left_print_noLeaf(root->left);
}

void right_print_noLeaf_reverse( node* root)
{
  if(root->right==NULL)
    return;
  left_print_noLeaf(root->right);
  cout<<root->data<<" ";

}
void print_leaves( node* root)
{
  if(root->left==NULL&&root->right==NULL)
  {  cout<<root->data<<" ";
    return; }
  print_leaves(root->left);
  print_leaves(root->right);
}

void boundaryTraversal( node* root)
{
  left_print_noLeaf(root);
  print_leaves(root);
  right_print_noLeaf_reverse(root);
}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif
  /////////////////////////////////////
  node* root=NULL;
  root= BuildTree(root);
  int l=height(root);
  cout<<l;
  return 0;
}
