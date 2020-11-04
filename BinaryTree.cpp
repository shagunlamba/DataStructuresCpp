#include <bits/stdc++.h> 
using namespace std; 
  
class BinaryTree{
  public:
  int data;
  BinaryTree* left;
  BinaryTree* right;

  public:
  BinaryTree(int data)
  {
    this->data=data;
    left=NULL;
    right=NULL;
  }
  
};

//+ 3 * 1 1 + 2 5 9 1 1 1 1 1 1

void print(BinaryTree* root)
{
    if(root==NULL)
      return;
    if(root->left== NULL && root->right==NULL)
      return;
    cout<<root->data<<" L:";
    if(root->left!=NULL)
    {
      cout<<root->left->data;
    }
    else
    {
      cout<<-1;
    }
    cout<<" R:";
    if(root->right!=NULL)
    {
      cout<<root->right->data;
    }
    else
    {
      cout<<-1;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
  }
BinaryTree* takeInput()
{
  int data;
  cout<<"Enter data of the root node: ";
  cin>>data;
  BinaryTree* root=new BinaryTree(data);
  queue<BinaryTree*> q;
  q.push(root);
  while(!q.empty())
  {
    BinaryTree* front= q.front();
    q.pop();
    int leftChild, rightChild;
    cout<<"Enter the left child: "<<front->data<<endl;
    cin>>leftChild;
    if(leftChild!=-1)
    {
      BinaryTree* l=new BinaryTree(leftChild);
      front->left=l;
      q.push(l);
    }
    cout<<"Enter the right child: "<<front->data<<endl;
    cin>>rightChild;
    if(rightChild!=-1)
    {
      BinaryTree* r=new BinaryTree(rightChild);
      front->right=r;
      q.push(r);
    }
  }
  
  return root;
}

void printInorder(BinaryTree* root)
{
  if(root==NULL)
    return;
  cout<<"(";
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
  cout<<")";
}

int eval(BinaryTree* root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
  {
    return (root->data-'0');
  }
  int ans1= eval(root->left);
  int ans2= eval(root->right);
  if(root->data=='+')
  {
    return ans1+ans2;
  }
  else if(root->data=='-')
  {
    return ans1-ans2;
  }
  else
  {
    return ans1*ans2;
  }
}

int level(BinaryTree* root, BinaryTree* node1)
{
  if(root==NULL)
  {
    return 0;
  }
  if(root==node1)
    return 1;
  else
    {
      int l=level(root->left,node1);
      if(l!=0)
      {
        return 1+l;
      }
      int r= level(root->right,node1);
      return r+1;
    }
}

bool isSibling(BinaryTree* root, BinaryTree* node1, BinaryTree* node2)
{
  if(root==NULL)
    return false;
  else
  {
    bool a= (root->left==node1 && root->right==node2);
    bool b= (root->right==node2 && root->left==node1);
    return a||b||(isSibling(root->left,node1,node2))||(isSibling(root->right,node1,node2));
  }
}


bool checkCousin(BinaryTree* root, BinaryTree* node1, BinaryTree* node2)
{
  cout<<level(root,node1)<<endl;
  cout<<level(root,node2)<<endl;
  if( (level(root,node1)==level(root,node2) && isSibling(root,node1,node2)==false))
  { 
    return true;
  }
  else
    return false;
}
vector<int>* longestPath(BinaryTree* root) {
	if(root==NULL)
    {
        vector<int>* ans= new vector<int>;
        return ans;
    }
  if(root->left==NULL && root->right==NULL)
  {
        vector<int>* ans= new vector<int>;
        ans->push_back(root->data);
        return ans;
  }
  vector<int>* l=longestPath(root->left);
  vector<int>* r=longestPath(root->right);
  if(l->size()>=r->size())
  {
    l->push_back(root->data);
    return l;
  }
  else
  {
    r->push_back(root->data);
    return r;
  }
}


int sum(BinaryTree* root)
{
  if(root==NULL)
    return 0;
  int s=0;
  if( (root->left!=NULL && root->left->data==2) || (root->right!=NULL && root->right->data==2))
    s+=root->data;
  return s + sum(root->left)+ sum(root->right); 
}

int summ(BinaryTree* root)
{
  if(root==NULL)
    return 0;
  int lSum=summ(root->left);
  int rSum=summ(root->right);
  if(lSum>=0 && rSum>=0)
  {
    return lSum+rSum+root->data;
  }
  else if(lSum>=rSum)
  {
    return lSum+root->data;
  }
  else
  {
    return rSum+root->data;
  }
}

void inorderTraversal( BinaryTree* root, vector<int> &arr)
{
  if(root==NULL)
  {
    return;
  }
  inorderTraversal(root->left,arr);
  arr.push_back(root->data);
  inorderTraversal(root->right,arr);
}

class Pair
{
  public:
        int minimum;
        int maximum;
        bool isBSTtill;

};

Pair checkBSTnew(BinaryTree* root) 
{
  if(root==NULL)
  {
    Pair obj;
    obj.minimum=INT_MAX;
    obj.maximum=INT_MIN;
    obj.isBSTtill= true;
    return obj;
  }
  Pair leftOutput= checkBSTnew(root->left);
  Pair rightOutput= checkBSTnew(root->right);
  int mini=min(leftOutput.minimum,rightOutput.minimum);
  if(root->data<mini)
    mini=root->data;
  int maxi=max(leftOutput.minimum,rightOutput.minimum);
  if(root->data>maxi)
    maxi=root->data;
  Pair finalAns;
  finalAns.minimum=mini;
  finalAns.maximum=maxi;
  bool t= leftOutput.isBSTtill && rightOutput.isBSTtill && (root->data>leftOutput.maximum && root->data<rightOutput.minimum);
  finalAns.isBSTtill=t;
  return finalAns;
}


bool checkBST(BinaryTree* root)
{
  Pair obj= checkBSTnew(root);
  return obj.isBSTtill;
}

bool findPath( BinaryTree* root, int node,  vector< pair<int,char> > &ans)
{
    if(root==NULL)
    {
         return false;
    }
    if(root->data==node)
    {
        ans.push_back(make_pair(node,'x'));
        return true;
    }
    bool t=findPath(root->left,node,ans);
    if(t)
      {
        ans.push_back(make_pair(root->data,'l'));
        return t;
      }
   bool r= findPath(root->right,node,ans);   
   if(r)
   {
    ans.push_back(make_pair(root->data,'r'));
   }
   return r;
}

//1 2 3 4 5 -1 -1 -1 -1 -1 6 -1 -1

void printatdepthk(BinaryTree* root, int d)
{
  if(root==NULL || d<0)
  {
    return;
  }
  if(d==0)
  {
    if(root!=NULL)
     cout<<root->data<<endl;
  }
  printatdepthk(root->left,d-1);
  printatdepthk(root->right,d-1);
}


BinaryTree* find(BinaryTree* root,int val)
{
  if(root==NULL)
    return NULL;
  if(root->data==val)
  {
    return root;
  }
  BinaryTree* leftans= find(root->left,val);
  if(leftans!=NULL)
    return leftans;
  return find(root->right,val);
}


 BinaryTree* ConvertToDDL( BinaryTree* root)
 {
   if(root==NULL)
    return NULL;

   if(root->left!=NULL)
   {
     BinaryTree* left= ConvertToDDL(root->left);
     while(left->right != NULL)
      left = left->right;
     left->right = root; 
     root->left=left;
   }
  if (root->right != NULL)  
    {  
        BinaryTree* right = ConvertToDDL(root->right);  
        while(right->left != NULL)
         right = right->left;
        right->left = root; 
        root->right = right;  
    }  
  
    return root;  
}  

  
 



BinaryTree* Merge2Trees(BinaryTree* root1, BinaryTree* root2)
{
  if(root1==NULL && root2==NULL)
    return NULL;
  if(root1==NULL)
    return root2;
  if(root2==NULL)
    return root1;
  if(root1!=NULL && root2!=NULL)
  {
    root1->data+=root2->data;
  }
  root1->left=Merge2Trees(root1->left, root2->left);
  root1->right=Merge2Trees(root1->right, root2->right);
  return root1;
}


int main() 
{ 
    BinaryTree* root1=takeInput();
    BinaryTree* root2=takeInput();
    BinaryTree* root=Merge2Trees(root1,root2);
    return 0; 
} 
