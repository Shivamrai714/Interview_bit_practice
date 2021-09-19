// left view using the level order traversal

// METHOD 1.
vector<int> leftView(Node *root)
{
 
vector<int>ans; 
 queue<Node*>q;
    // following with level order traversal
if(!root ) return ans;
q.push(root);

while(!q.empty())
{
    
    int sz=q.size();
  
    ans.push_back(q.front()->data);
    
    
  
       
    while(sz--)        //rmeoves access ele of level ,after pushing their childs
    {
        Node* temp=q.front() ;
   
         q.pop();
            if(temp->left) q.push(temp->left);
         if(temp->right) q.push(temp->right);
        
    }
    
}
 
 

    return ans;
}

/////////////////////////////////////

METHOD 2: STRIVER  ::::::::::::::::::::::::: RIGHT VIEW OF TREE

class Solution
{                    
               // FOR LEFT : ROOT, LEFT,RIGHT
               // FOR RIGHT : ROOT, RIGHt,LEFT

    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
     vector<int>ans;
     rev_preorder(root,0,ans);
        return ans;
    }
    
    void rev_preorder(Node* root,int level ,vector<int>& ans)
    {
        // here use root,right ,left
        if(root==NULL) return; 
        
        // this cond ensures that from level we get first node form right side only
        if(ans.size()==level) ans.push_back(root->data);
        
        rev_preorder(root->right,level+1,ans);                 
        rev_preorder(root->left,level+1,ans);
                                                    // in left view this will be reversed
    }
    
    
};










 //         MEthod 3 :  uisng preorder traversal         ,, didn't work for multiple inputs


int find_height(Node* root)
{
   if(root==NULL) return 0;
   return 1+max(find_height(root->left),find_height(root->right));
}





vector<int>ans;


void preorder(Node* root,vector<bool>& visited, int curr)
{
    if(root==NULL) return ;
    
    if(visited[curr]==false)
    {
             visited[curr]=true;
                 ans.push_back(root->data);
                   }
    preorder(root->left, visited,curr+1);
    preorder(root->right,visited,curr+1);    
}



vector<int> leftView(Node *root)
{
     int h= find_height(root);                    // to make a visitd array
    vector<bool>visited(h,false);
  

    preorder(root,visited,0);

    return ans;
}
