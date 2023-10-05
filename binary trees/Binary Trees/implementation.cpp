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

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) {
                //queue still has some child ndoes
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

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

void PreorderTraversal( node* root)
{
  if(root->left==NULL && root->right==NULL)
  {cout<<root->data<<" ";
  return;}
  cout<<root->data<<" ";
  PreorderTraversal(root->left);

  PreorderTraversal(root->right);
}

void PostorderTraversal(node* root)
{
  if(root->left==NULL && root->right==NULL)
  {cout<<root->data<<" ";
  return;}

  PostorderTraversal(root->left);

  PostorderTraversal(root->right);
  cout<<root->data<<" ";

}

void Number_leaf_nodes( node* root ,int &cnt)
{
  if(root->left==NULL && root->right==NULL)
  {cnt++;
  return;}
  Number_leaf_nodes(root->left , cnt);
  Number_leaf_nodes(root->right ,cnt);
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
return 0;
}
