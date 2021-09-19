Return an integer array denoting the right view of the binary tree A.






        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 

 Output 1:

 [1, 3, 7, 8]










// METHOD 2 using modified pre_order


void mod_preorder(TreeNode* root,vector<int>& ans,int level)
{  if(!root) return ;
   if(ans.size()==level)
         { ans.push_back(root->val);}
  mod_preorder(root->right,ans,level+1);   // first visit right node
  mod_preorder(root->left,ans,level+1);
}

vector<int> Solution::solve(TreeNode* root)
{ vector<int>ans;
if(!root) return ans;
 
 // using pre order technique, but just changing swquene to visit .... root ->right ->left
 // so that i will visit all the right nodes. 

mod_preorder(root,ans,0);
return ans;
}




// // METHOD 1:
// vector<int> Solution::solve(TreeNode* root)
// {
//   vector<int>ans;
//   // we need to see teh last ele of each level while traversing level wise.
//   queue<TreeNode*>q;
//   if(!root) return ans;
//   q.push(root);

//   while(!q.empty())
//   {
//     int sz=q.size();
    
//     while(sz--)
//     {
//        TreeNode* temp=q.front();
//        q.pop();

// // now we need to check last ele of each level. // so what happned for a level sz is size of level ,when sz==1, means last ele of level 
// /// but due to sz-- it becomes 0
// if(sz==0)   ans.push_back(temp->val);

//        if(temp->left) q.push(temp->left);       
//        if(temp->right) q.push(temp->right);       
       
       
    
//     }


//   }
  
// return ans;

// }















