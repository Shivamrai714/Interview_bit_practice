/*Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.

NOTE:

Return the largest B elements in any order you like.
Input 1:

 A = [11, 3, 4]
 B = 2
Input 2:

 A = [11, 3, 4, 6]
 B = 3


Example Output
Output 1:

 [11, 4]
Output 2:

 [4, 6, 11]


Example Explanation
Explanation 1:

 The two largest elements of A are 11 and 4
Explanation 2:

 The three largest elements of A are 11, 4 and 6*/

//////////////////////////////////////////////////////////////////////////////
Approch 1:
BEST APPROCH FOR INTERVIEW IN O(N) for best case using quick select method and random fun


// this method is still O(n^2) but we will optimise it using random function 
// dont take pivot as last ele (int idx=hi; ) take randow val as pivot
// func whick whill cal teh pivot/ idx using quick select method
int getindex(vector<int>&arr,int lo,int hi)
 {     
      int idx=rand()%(hi-lo+1)+lo;                  // randow no is brougth in range ( by dividing with length +lo index)
       swap(arr[idx],arr[hi]);                               // and in main progm , chane value giving by random alternatevily suing srand(time(0)); function
        idx=hi;
                        // we have readjusted the pivot wrt to random ele  

     // before optimisattion
   // int idx=hi;                             // idx is pivot ele only 
   
    int i=lo;
    for(int j=lo;j<hi;j++)                  // quick selectt mthd values swap(i,j) if val i > pivot , and at end of fun swap (i,pivot)
    {
        if(arr[j]>=arr[idx]) {swap(arr[i],arr[j]);
                            i++;
                            }
    }

    swap(arr[i],arr[idx]);
    return i;                // i is ele whick is at good position (ele left to it are =or grter and right to it are smaller)
}








int func(vector<int>&arr,int lo,int hi,int k)
{
    int idx=getindex(arr,lo,hi);                         // this fun will give idx=its index which will contain ele left to it are larger/equal to it and right ele are smaller to it.

if(idx>k ) return func(arr,lo,idx-1,k) ;                 // our need k ele , but idx is > k menas we need to shrink search to left
else if(idx< k) return func(arr,idx+1,hi,k) ;               // need to search in right side        // 5 4 3 2 1 

 return idx;


}



vector<int> Solution::solve(vector<int> &arr, int k) {
srand(time(0));                                  // to take the diifect random val oterhwise ti will give same random val agin.
int idx=func(arr,0,arr.size()-1,k-1);                          // k means no of ele (grt) we need , we need to get index so k-1

vector<int>ans;
for(int i=0;i<=idx;i++)               // till idx index uptill here we get k largest else
{
    ans.push_back(arr[i]);
}
return ans;
}












































//**********************************************************************************

Approch 2: we can use a min priiority queue ,we will push all values and pop out ele when size of pq >k at last we ARE left with only k largest ele so put them in a std::vector<char> v;


vector<int> Solution::solve(vector<int> &a, int k) {
 
priority_queue<int,vector<int>,greater<int>>pq;
 
for(int i=0;i<a.size();i++)
{   pq.push(a[i]);
if(pq.size()>k) pq.pop();              // removes the min ele from the top when size exceeds so we at llast will left with k largest ele
 
}
vector<int>ans;
for(int i=0;i<k;i++)                //*****   i<k not i<pq.szie() as size is cahnging due to pop inside loop
{
ans.push_back(pq.top()); pq.pop();
}
 
return ans;
 
 
 
}






//*********************************************************************************

 Approch 1: O(n * logn )   -- sort using vector and give k largest
// code 
/* vector<int> Solution::solve(vector<int> &a, int k) {
int n=a.size();
vector<int>v;
vector<int >ans;
for(auto it:a)
{
    v.push_back(-1*(it));               // this will store no in -ve at last we will sort so large no will be up and we will take k ele from top
}
sort(v.begin(),v.end());

for(int i=0;i<k;i++)
{
ans.push_back(-1*(v[i]));               // at last we are agin changing that -ve no to +no
}

return ans;
}
*/



