// Q. Given an array of integers A .

// A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

// Find the area of the largest rectangle formed by the histogram.


// Example Input
// Input 1:

//  A = [2, 1, 5, 6, 2, 3]
//  Explanation 1:

// The largest rectangle has area = 10 unit. Formed by A[3] to A[4].






// Only code 
int Solution::largestRectangleArea(vector<int> &a) {
int n=a.size();
vector<int>L(n),R(n);
stack<pair<int,int>>left,right;

// prepare teh left and right min ele for each index

// left min array
for(int i=0;i<n;i++)
{     int x=-1;                //var to store min to eaCh corres index
    while(!left.empty() and left.top().first>=a[i]) left.pop();
    if(!left.empty())  x=left.top().second;
    L[i]=x;
    left.push({a[i],i});
}
// right min array
for(int i=n-1;i>=0;i--) 
{
    int x=n; 
    while(!right.empty() and right.top().first>=a[i]) right.pop();
    if(!right.empty()) x=right.top().second;       /// we are interested in index only
    R[i]=x;
    right.push({a[i],i});

}
int ans=INT_MIN;
for(int i=0;i<n;i++)
{
    L[i]++; R[i]--; // increment and decrement each index because we have searched min on both side ,but we need contributionfrom maxs in max areaa of largestRectangleArea
 
  ans=max(ans, a[i]* (R[i]-L[i]+1) );      // lenght * breadth 

}


return ans;

}





// explanattion how to work on stack for nearest max/ min on left and right side on index and store them in arrays








int Solution::largestRectangleArea(vector<int> &a) {
  
  // approch is to cal teh left and right smalledt repectively and then increment and decremnt then because then onkly they can contribute in rectangle formation.
 // wee are keeping track of teh radius
 int n=a.size();
 vector<int>L(n),R(n);
 stack<pair<int,int>>left,right;        ///to store teh val and index 
 
  // to get left and right min just pop teh greater ele
// first left traversal
for(int i=0;i<n;i++) 
{
    int x=-1;    // to start from left and at last we will increment ++ so it will come to 0 index
    while(!left.empty() and left.top().first>=a[i]) left.pop();
    if(!left.empty()) x=left.top().second;    // stooring the index of teh smaller ele
     L[i]=x;
      left.push({a[i],i});        // pushed to help other ,i many become min for other
 
}
 
//right traversal from last ele of array to get min for each index on right side
for(int i=n-1;i>=0;i--) 
{
    int x=n;    // to start from right we are going to decrement val at last because this we are clacu. min and we need max to from rectangle so we decremnt val and ultimately reach to bpounding index only at n-1;
    while(!right.empty() and right.top().first>=a[i]) right.pop();    // keepp poping the gret values and store min in array for each index
    if(!right.empty()) x=right.top().second;    // stooring the index of teh smaller ele
     R[i]=x;                     // storing inarray
  right.push({a[i],i});        // pushed to help other ,i many become min for other
 
}
 
// now we have left and right array respectively storing the left min val( L array ) and rightmin val (R array ) for each respective elements 
// so we are going to iteratie all over the loop and finding the ans for each ele.
 
int ans=INT_MIN;
 
for(int i=0;i<n;i++)
{
     L[i]++; R[i]--;                 // increment and decrement val as we need max area of rectangle  // because we have searched for the min 
 
     ans=max(ans,(R[i]-L[i]+1)*a[i]);
 
}
 
return ans;
}