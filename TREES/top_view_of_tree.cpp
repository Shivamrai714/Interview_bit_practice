?///////////////////////////    TOP view & bottom view  ////////////////////////

// in bottom view just keep updating the values in map , independent of level in map , at last we will have all bottom nodes updated in map.
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        map<int,int>m;              //  ( vertical-level , nodes val  )
        queue<pair<Node*,int>>q;   //   (node, vertical-level)
    
    if(root==NULL) return ans;
    q.push({root,0});             //  {root,0}
     while(!q.empty())
     {   
        Node* temp=q.front().first;      //q is (node,level)
  
        int h=q.front().second;           // v-level
              q.pop();
        if(m[h]==0){m[h]=temp->data;}                              //IN BOTTOM VIEW THIS IF CONDITION WILL BE REMOVED ,IT WILL UPDATE ALL TIMES
        
        if(temp->left) q.push({temp->left,h-1});   // on left side of level
        if(temp->right) q.push({temp->right,h+1});  // on right side of vertical level
     }
     
            for(auto i:m)
    {
        ans.push_back(i.second);
    }
      return ans;
    }
    

};

