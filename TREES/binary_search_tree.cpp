#include<bits/stdc++.h>
using namespace std; 
// make binary tree
struct bstnode
{ 
    int data;
    bstnode* left;
    bstnode* right;
};

bstnode* createnode(int data)
{
    bstnode* object = new bstnode();
    object->data=data;
    object->left=NULL;
    object->right=NULL;
}

bstnode* insertnode(bstnode* root, int data)
{
 if(root==NULL)  {root=createnode(data);}
 else if(data <= root->data)  root->left = insertnode(root->left,data); 
 else if(data > root->data  )  root->right = insertnode(root->right,data);

return root;
}

bool search(bstnode* root,int data)
{
    if( root==NULL)  return false;  // empty tree
    else if( data == root->data) return true;
    else if( data < root->data) return search(root->left,data);
    else  return search(root->right,data);
}
/////////////////////////////////////////////////////////////////

bstnode* findmin_r(bstnode* root)
{    // root is local varible here so using it to cal teh min val ,as it will not affect the root in the main function 
    while(root->left!=NULL)
        root=root->left;
    return root;
}
// delete a node 
bstnode* deletenode(bstnode* root,int data)
{
    if(root== NULL) return root;
    else if(  data <  root->data )  root->left= deletenode(root->left,data);
else if(data > root->data)  root->right = deletenode(root->right,data);
 else  // we have fouhd teh data now deletet it
 {
    // case 1 no child
if( root->left==NULL && root->right==NULL )
               {
                  delete(root);
                  root=NULL;
                  return root;
               }
//case 2: 1 child 
 // ie left child
else if(root->right==NULL)
           {
              bstnode* temp=root; 
              root=root->left;
              delete(temp);
              return root;
           }              
// ie right child exits
else if(root->left==NULL)
           {
              bstnode* temp=root; 
              root=root->right;
              delete(temp);
              return root;
           }              
// case 3 : when 2 child
else{ 
bstnode* temp=findmin_r(root->right);
root->data=temp->data;
// rmeove teh duplicates
      root->right=deletenode(root->right,temp->data);
return root;
}
 } 
}
//////////////////////////////////////////////////////////////////////////
int Findmin(bstnode* root)
{  if(root==NULL) {cout<<"\n Tree is empty"; return -1;}
       // iterating with root as it is local vairble here
// we need to go as left as possible
    while(root->left!=NULL) 
         root=root->left;
  return root->data;  
}
int Findmax(bstnode* root)
{  if(root==NULL) {cout<<"\n Tree is empty"; return -1;}
  
  if(root ->right ==NULL )         // base cond. for recursion
      { return root->data;}
  else return Findmax(root->right);  
}
//////////////////////////////////////////////////////////////////////

// depth : no of edges form root to specific node
// height : no of edges from specific node to leaf node
 
 //height of tree

int height_tree(bstnode* root)
{   // updated this func
if (root==NULL) return 0;
return  1 + max(left_height,right_height);
}

// find height of the tree : height of root node
////////////////////////////////////////////////////////////////
// Tree Traversals :
// 1.  BFS breath first traversal /level order traversal
// use queue:

void BFS_traversal(bstnode* root)
{      if(root ==NULL) return;

queue<bstnode*>q;
    q.push(root);

    while(!q.empty())
    {  
     bstnode* temp=q.front();
    cout<<temp->data<<" ";
     if(temp->left !=NULL) q.push(temp->left );
     if(temp->right !=NULL) q.push(temp->right );
     q.pop();
    }

}

void DFS_preorder(bstnode* root)
{    
    if(root==NULL) return;
     cout<<root->data<<" ";
     DFS_preorder(root->left);
     DFS_preorder(root->right);

}

void DFS_postorder(bstnode* root)
{      if(root==NULL) return;
     DFS_postorder(root->left);
     DFS_postorder(root->right);
        cout<<root->data<<" ";
    
}
void DFS_inorder(bstnode* root)
{       if(root==NULL) return;
     DFS_inorder(root->left);
    cout<<root->data<<" ";
     DFS_inorder(root->right);

}
/////////////////////////////////////////////////////////////////
// TO CHECK GIVEN TREE IS BINARY SEARCH TREE OR NOT
/* 
bool islesser(bstnode* root,int data)
  {
        if(root==NULL) return true;
        if(root->data <= data  and islesser(root->left,data) and islesser(root->right,data)) return true;
        else return false; 
  }
  bool isgreater(bstnode* root,int data)
  {
          if(root==NULL) return true;
        if(root->data > data  and isgreater(root->left,data) and isgreater(root->right,data)) return true;
        else return false; 
  }

  bool is_binary_search_tree(bstnode* root)
  {
    // using recursive approch
 if(root==NULL) return true;
 else if(islesser(root->left,root->data) and isgreater(root->right,root->data) and is_binary_search_tree(root->left) and is_binary_search_tree(root->right) ) return true;
 else return false;   
  }

*/


//efficeint approch O(n) n=nodes

bool isbin_util(bstnode* root,int min_val,int max_val)
{
    if(root==NULL) return true;

    if(root->data < min_val && root->data >max_val &&
                          isbin_util(root->left,min_val,root->data)
                        && isbin_util(root->right,root->data,max_val))
        return true;                                                        
                                               // we are checking the range , -& to +& ,then on left node we update it (-& to root->data ) and so on for right node (root->data to +&)
    else return false;
}

bool is_binary_search_tree(bstnode* root)
{
    return isbin_util(root,INT_MIN,INT_MAX);
}
////////////////////////////////////////////////////////////////////

int main()
{
   bstnode* root=NULL;

   root=insertnode(root,12);
   root=insertnode(root,5);
   root=insertnode(root,15);
   root=insertnode(root,3);
   root=insertnode(root,7);
   root=insertnode(root,1); 
   root=insertnode(root,13);
   root=insertnode(root,9); 
   root=insertnode(root,17);
   root=insertnode(root,8);
   root=insertnode(root,11);

cout<<"\n max ele is : "<<Findmax(root);
cout<<"\n min ele is : "<<Findmin(root);

cout<<"\n Height of tree is: "<<height_tree(root);

cout<<"\n BFS_traversal is: ";
BFS_traversal(root);

cout<<"\n DFS TRAversal are : PRE-Order,In-Order, Post-Order ";
cout<<"\n DFS - pre order: ";
DFS_preorder(root);

cout<<"\n DFS - in order: ";        // will give sorted 
DFS_inorder(root);

cout<<"\n DFS - Post-Orderr : ";
DFS_postorder(root);





int a=11;
 if(search(root,a)) cout<<"\nfound";
 else cout<<"\nNot found";

root= deletenode(root,a);
 if(search(root,a)) cout<<"\nfound";
 else cout<<"\nNot found";

cout<<"\n";
if(is_binary_search_tree(root)) cout<<"tree is BST";
else cout<<"NOT BST";

cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

cout<<"\n done";


 return 0;
}
//5
//6 3 1 8 9 























//////////////////////////////////////////////////////////////////////

// //FIND INORDER SUCCESSOR
// cout<<"\n inorder successor ";
// case 1: node has right subtree , so find min in right subtree (go deepest to leftmost node) 

// case 2: no right subtree, go to nearest ancestor(parent) for which this node would be in left subtree
        
        // so to go back to ancestor we need addtion pointer to go back;
 
// refer next Q for tthis





























/*//create binary search tree
#include<bits/stdc++.h>
using namespace std;

struct Bstnode {
    int data;
    Bstnode* left;
    Bstnode* right;
};

Bstnode* createnode (int data)
{
    Bstnode* object= new Bstnode();
    object->data=data;
    object->left = object->right = NULL;
}

Bstnode* insert (Bstnode* rootptr,int data)
{
    if(rootptr==NULL) 
    {
        rootptr=createnode(data);
    }
  else if(data <= rootptr->data)
           rootptr->left= insert(rootptr->left,data);
       else  rootptr->right = insert(rootptr->right,data);
return rootptr;
}
//////////////////////////////////////////////////////////

bool search(Bstnode* root,int data)
{
    if(root==NULL) return false;
    else if(data==root->data) return true;
    else if(data < root->data) return search(root->left, data);
    else return search(root->right,data);

} 

////////////////////////////////////////////////////

Bstnode* Findmin(Bstnode* root)
{
    while(root->left !=NULL) root=root->left;
    return root;
}

// deleting the node case 1,case 2,case 3
Bstnode* Delete(Bstnode* root,int data)
   {
       if(root== NULL) return root;  // Empty binary tree :return NULL is same over here
      else if(data < root->data) 
    root->left = Delete(root->left,data);
     else if (data > root->data)
    root->right=Delete(root->right,data);
else {  // (data= root->data) we have found ele which need to be deleted
// No child 
// case 1:
 if(root->left==NULL && root->right ==NULL)
         {
                  delete root; // -dangling pointer: memory delocated only not is existance removed so put its val as NULL
               root=NULL; 
               return root;
          }

    // case 2: One Child : on right side
else if(root->left ==NULL)
{
    Bstnode* temp=root;
    root=root->right;
    delete temp;
    return root;
}
               // child in lef t side
else if(root->right ==NULL)
{
    Bstnode* temp=root;
    root=root->left;
    delete temp;
    return root;
}

// case 3: two children

else {
    Bstnode* temp=Findmin(root->right);
    root->data=temp->data;
    root->right=Delete(root->right,temp->data);
    return root;
}



}
    
}

////////////////////////////////////////


int main()
{
   // make a binnary search tree (BST)

   Bstnode* root=NULL;
   root=insert(root,12);
   root=insert(root,5);
   root=insert(root,15);
   root=insert(root,3);
   root=insert(root,7);
   root=insert(root,1); 
   root=insert(root,13);
   root=insert(root,9); 
   root=insert(root,17);
   root=insert(root,8);
   root=insert(root,11);


int a=13;
if(search(root,a)) cout<<"Found\n";
else cout<<"Not Found\n";

   root=Delete(root,15);

if(search(root,a)) cout<<"Found\n";
else cout<<"Not Found\n";


    return 0;
}


















*/