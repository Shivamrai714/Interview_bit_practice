Given two integers arrays A and B of size N each.

Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.
Input 1:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]


Output 1:

 [10, 9, 9, 8]
 Explanation 1:

 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
//code

class three{
    public: int val,idx,jdx;
};
struct comp {
 bool operator()(three a,three b)
 { return a.val < b.val;                   // as we need max pq 
 }

};


vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
int n=a.size();
vector<int >ans;
set<pair<int,int>>s;           // to keep track of visisted index
priority_queue<three,vector<three>,comp>pq;
sort(a.begin(),a.end());
sort(b.begin(),b.end());


pq.push({a[n-1]+b[n-1],n-1,n-1});           // pushed in class val,i,j
s.insert({n-1,n-1});                  // we are starting form last position so pre initialising them

while(ans.size()!=n)                    // as we need sum of max N ele 
{  
    three obj=pq.top(); pq.pop();
    int val=obj.val;
    int i=obj.idx;
    int j=obj.jdx;

    ans.push_back(val);
    
    

     // for i-1,j  
   if(s.count({i-1,j})==0)             // checing if such a value due to same i,j pair is not present before
   {
       pq.push({a[i-1]+b[j],i-1,j});
       s.insert({i-1,j});
   }
   // for i,j-1
   if(s.count({i,j-1})==0)
   {
       pq.push({a[i]+b[j-1],i,j-1});
       s.insert({i,j-1});
   }




}
return ans;

}
