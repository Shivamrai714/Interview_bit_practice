#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
    node* left;
    node* right;
};

node* createnode(int data)
{    
	node* obj=new node();
	obj->data=data;
	obj->left= obj->right=NULL;
	return obj;
}

node* insert_node(node* root,int data)
{
   if(root==NULL) root=createnode(data);

   else if( data <= root->data){ root->left= insert_node(root->left,data);}
   else root->right=insert_node(root->right,data);
  return root;
 }

node* findmin(node* root)
{
	if(root==NULL) return NULL;

	while(root->left!= NULL) root=root->left;
       return root;
}
node* find(node* root,int data)
{
	if (root==NULL) return root;
	if( root->data == data) return root;
	else if(data < root->data ) return find(root->left,data);
		else return find(root->right,data);

}

node* get_successor(node* root,int data)
{
	node* current =find(root,data);
if (current ==NULL) return NULL;
	if(current->right !=NULL) //right subtree exits find min from it
		{ 
			return  findmin(current->right);
		}
     else 
     {          // no right sub tree
         node* successor=NULL; node* ancestor=root;
           while(ancestor!=current)
           {
           	if(current->data < ancestor->data) 
           		{ successor= ancestor;
                   ancestor=ancestor->left;
                   }
                   else  { ancestor=ancestor->right; }
                } 

return successor;
      }

     
}
//////////////////////////////////////////////////
int find_height(node* root)
{
   if(root==NULL) return 0;
   return 1+max(find_height(root->left),find_height(root->right));
}





vector<int>ans;


void preorder(node* root,vector<int>& visited, int curr)
{
    if(root==NULL) return ;
    
    if(visited[curr]==0){
             visited[curr]=1;
                 ans.push_back(root->data);
                   }
    preorder(root->left, visited,curr+1);
    preorder(root->right,visited,curr+1);    
}


void leftView(node *root)
{
     int h= find_height(root);                    // to make a visitd array
    vector<int>visited(h,0);
  
cout<<endl<<endl;
     
    preorder(root,visited,0);
    
for(int i=0;i<visited.size();i++)
   cout<<visited[i]<<" ";   
cout<<endl;
for(int i=0;i<ans.size();i++)
   cout<<ans[i]<<" ";   
    
}















int main()
{ node* root=NULL;
	root=insert_node(root,5);
	root=insert_node(root,3);
	root=insert_node(root,1);
    root=insert_node(root,10);
    root=insert_node(root,4);
    root=insert_node(root,11);


node* successor=get_successor(root,1);
if(successor==NULL) cout<<"\n no successor ";
else cout<<"\n"<<"successor is "<<successor->data;

cout<<"\nheight of given tree is:"<<find_height(root);
cout<<"\n left view is: ";
leftView(root);

	return 0;

}       

          /*
                           5
                         /   \
                        3     10
                      /  \     \
                     1    4     11

         */















/*
#include<bits/stdc++.h>
using namespace std;

struct node
{
int data; node* left;
node* right;
};

node* create_node(int data)
{
	node* obj=new node();
	obj->data=data;
	obj->left = obj->right = NULL ; 
	return obj;

}
node* insert_node(node* root,int data)
{    // empty tree
	if(root==NULL) {  root=create_node(data);}
    else if(data > root->data) root->right=insert_node(root->right,data);
    else root->left=insert_node(root->left,data);
return root;
}
node* Findmin(node* root)
{
   if(root==NULL) return NULL;  
   while(root->left!=NULL) root=root->left;
   return root;
}
node* Find(node* root,int data)
{ if(root==NULL) return NULL;
	else if(data==root->data) return root;
	else if(data <root->data) return Find(root->left,data);
	else return Find(root->right,data);
}

node* get_successor(node* root,int data)
{
   if(root==NULL) return root;
  //case 1: right subtree is presnet then search for min val in right sub tree
  
  node* current=Find(root,data);
if(current==NULL) return NULL;

   if(current->right!=NULL) 
   	{ return Findmin(current->right); }
   //case 2 : no right subtree : go with successor and ancestor rule with mycode school
   else
   {
   	 node* ancecstor=root; node* successor=NULL;
     
     while(ancecstor!=current)
     {
     	if(current->data < ancecstor->data)  
     	 {    
     	 	successor=ancecstor;               // keep moving untill u get , given node in left subtree of given deepest successor
              ancecstor=ancecstor->left;
     	 }
     	 else 
     	 	ancecstor=ancecstor->right;

     }

return successor;
   }


}



int main()
{ node* root=NULL;
	root=insert_node(root,5);
	root=insert_node(root,3);
	root=insert_node(root,1);
    root=insert_node(root,10);
    root=insert_node(root,4);
    root=insert_node(root,11);


node* successor=get_successor(root,1);
if(successor==NULL) cout<<"\n no successor";
else cout<<"\n"<<"successor is  "<<successor->data;


	return 0;

}   */