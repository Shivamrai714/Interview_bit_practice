/*method 1.
       
// VERY IMP CONCEPT : INORDER TRAVERSAL USING ITERATIVE APPROCH

vector<int> Solution::inorderTraversal(TreeNode* root) 
{    vector<int>ans;
    // we are moving as left as possible & pusing in stack  and then doing work on root and then go to right root
 
 stack<TreeNode*> s;

 while(!s.empty() || root)  
{
  if(root)
  {   s.push(root);
     root=root->left;
  }

  else 
  {
    TreeNode* temp=s.top();
    s.pop();
    ans.push_back(temp->val);

    // make root as the right node
   root=temp->right;
 
  }
} 

return ans;

}

*/




// method 2.
//   INORDER USING MORIS ALGORITHM : TIME o(N) ,SPACE o(1)


vector<int> Solution::inorderTraversal(TreeNode* root)
{ vector<int>ans;
   while(root)
   {
       if(! root->left ){ans.push_back(root->val);   root =root->right; }
       else 
       {  
           // left exits
        TreeNode* temp=root->left;
         while( temp->right!=NULL  && temp->right !=root  )      // ie back link not exits
         temp=temp->right;

         if(temp->right==NULL)       // rightmost node,link it to root
         {
                //  this was condition for pre order , that add data before visiting left    
                 //     ans.push_back(root->val);         //root is completed go to its left
                temp->right=root;               //back-link
               root=root->left;
         }
         else if(temp->right == root)     // means we got an ele for which we have made aback link, so our left part has been done , just go to root right   
         {     // we have already viited left node,so can push data <inorder:::   left,data ,right>
             ans.push_back(root->val);
             temp->right=NULL;
             root=root->right;
         }



       }


   }

return ans;
}








// // method 3 .
// simply calling recursive statemnets

// void inorder()
// {  inorder(root->left);
//     temp->data;            // work with  root
//     inorder(root->right);
// }