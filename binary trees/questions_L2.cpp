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

void level_order_traversal( node* root)
{
  if(root==NULL)
    return;

  queue<node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty())
  {
    node*temp = q.front();
    q.pop();
    if(temp!=NULL)
    {
      cout<<temp->data<<" ";
      if(temp->left)
      {
        q.push(temp->left);
      }
      if(temp->right)
      {
        q.push(temp->right);
      }
    }

    else if(temp==NULL)
    {cout<<endl;

     if(!q.empty())
      {
        q.push(NULL);
      }
    }
  }

}


void pushEnd(queue<int> q , vector<int> &v)
{
  if(q.empty())
    return;
  int temp= q.front();
  q.pop();
  pushEnd(q,v);
  v.push_back(temp);
}
void zig_zag_traversal( node* root)
{
  if(root==NULL)
    return;

  queue<node*> q;
  q.push(root);
  q.push(NULL);

  queue<int> queue2;

  while(!q.empty())
  {
    node*temp = q.front();
    q.pop();
    if(temp!=NULL)
    {
      queue2.push(temp->data);
      if(temp->left)
      {
        q.push(temp->left);
      }
      if(temp->right)
      {
        q.push(temp->right);
      }
    }
    else if(temp==NULL)
    {queue2.push(-1);

     if(!q.empty())
      {
        q.push(NULL);
      }
    }


  }

  vector<int> ans;
  bool flag=true;
  while(!queue2.empty())
  {
    int temp=queue2.front();

  }

}

//do it using queue as well
class vertical_traversal_tc_N_2
{
public:

void vertical_traversal_maker(node* root , map<int,vector<int>> &m ,int i)
{
  if(root==NULL)
    return;
  m[i].push_back(root->data);
  vertical_traversal_maker(root->left , m , i-1 );
  vertical_traversal_maker(root->right , m , i+1 );
}

void vertical_traversal_printing(node*root, map<int,vector<int>> &myMap)
{
  vertical_traversal_maker(root, myMap , 0);
  for(auto &it: myMap)
  {
    for(auto &i: it.second )
          cout<<i<<" ";
  }
}
};

//need to work on it
class vertical_traversal_tc_N_1
{
public:
// use any other data structue
//other than vector so that travesing would take less time
};

// do it using queue again MUST
class topView
{
public:
  void topView_maker(node* root , map<int,int> &m ,int i)
  {
    //base case
    if(root==NULL)
      return;
    //if value is already preent do nothing
    if(!m[i])
      m[i]= root->data ;

    topView_maker(root->left , m , i-1 );
    topView_maker(root->right , m , i+1 );
  }

void topView_printing(node*root, map<int,int> &myMap)
{
    topView_maker(root, myMap , 0);
    for(auto &it: myMap)
    {
      cout<<it.second<<" ";
    }
  }
};

class bottomView
{
public:
  void bottomView_maker(node* root , map<int,int> &m ,int i)
  {
    //base case
    if(root==NULL)
      return;

    //change the value each time so that
    //bottom value would be stored in it
      m[i]= root->data ;

    bottomView_maker(root->left , m , i-1 );
    bottomView_maker(root->right , m , i+1 );
  }

  void bottomView_printing(node*root, map<int,int> &myMap)
  {
    bottomView_maker(root, myMap , 0);
    for(auto &it: myMap)
    {
      cout<<it.second<<" ";
    }
  }
};


void flag_change( bool &flag)
{
  flag=!flag;
}


class leftView_recursive
{
public:
  void left_traversal_maker(node* root, map<int , int> &m , int leftView_level)
  {
    if(root==NULL)
      return;

    left_traversal_maker(root->left , m , leftView_level - 1);

    //push the element only if the place is vacant otherwise let it stay
    if(!m[leftView_level])
      m[leftView_level]= root->data;

    left_traversal_maker(root->right , m , leftView_level-1);
  }


  void left_traversal_printing(node*root, map<int,int> &myMap)
  {
    left_traversal_maker(root, myMap , 0);

    for(auto &it: myMap)
      {cout<<it.second<<" ";}
  }

};

class leftView_iteration
{
public:
  //this code is not printing the last level element from left
  void left_view(node*root)
  {
    if(root==NULL)
      return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    cout<<root->data<<" ";

    //we just need  to print the element which is next to NULL evertime
    while(!q.empty())
    {
      node* temp = q.front();
      q.pop();
      if(temp!=NULL)
      {
        if(temp->left)
          q.push(temp->left);

        else if(temp->right)
          q.push(temp->right);
      }

      else if(temp==NULL)
      {
        node*next=q.front();
        if(next!=NULL)
          cout<<next->data<<" ";
        if(!q.empty())
         {
           q.push(NULL);
         }
      }

    }
  }

};

class diagonalTraversal
{
public:

void diagonal_traversal_maker(node* root, map<int , vector<int>> &m , int diagView_level)
{
  if(root==NULL)
    return;

  diagonal_traversal_maker(root->left , m , diagView_level - 1);
  m[diagView_level].push_back(root->data);
  diagonal_traversal_maker(root->right , m , diagView_level);
}

void diagonal_traversal_printing(node*root, map<int,vector<int>> &myMap)
{
  diagonal_traversal_maker(root, myMap , 0);
  for(auto &it: myMap)
  {
    for(auto &i: it.second )
          cout<<i<<" ";
  }
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


  node* root= NULL;
  root=BuildTree(root);
  leftView_iteration obj1;
  obj1.left_view(root );

return 0;
}
