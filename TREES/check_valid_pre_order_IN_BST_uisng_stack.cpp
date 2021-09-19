#include<bits/stdc++.h>
using namespace std; 
    

       // TRICK O(n) using stack
       // we  pop all ele from stack as soon as we get right ele ,
       // else we simpley push all else
       // after pop means right ele is enocuntered ,so we check that whether ant small ele than root is found or not, if found then we return 0
       // use  ( root > a[i] ) ie small ele is found return 0;


stack<int>s; int root=INT_MIN;
int check_valid_preorder(vector<int>&a)  // TAKEN reference so copy will not be created
{
	for(int i=0;i<a.size();i++)
	{  
		// we are poping all the element  as soon as we get ele greter then root 
		while(!s.empty() and a[i]>s.top() )
	   {
		root=s.top();            // as ele are remved root will be updated
		 s.pop();
     	}
     	// now we are checking if right subtree is not containg any val which is less then root val : 
if(root>a[i]) return 0;

     	s.push(a[i]);
    }

return 1;
}


int main()
{

int n,i,val; 
cin>>n;
vector<int>a;
for(i=0;i<n;i++) {cin>>val; a.push_back(val);}


int a1=check_valid_preorder(a);

if(a1==1) cout<<"\nvalid preorder";
if(a1==0) cout<<"\nIn valid preorder";
}











/*
O(n^2) approch 

// As we know preorder of BST-> (root)(left tree ele< root)(right tree ele > root)
/// O(n^2) recursive approuch
// we are checing the first where we get ele greater then root , hence right subtree will start 
// and then we check if any smaller ele to root is found otr not ,if found then it will be invalid  preorder


bool check(vector<int>&a , int l ,int r)
{
    if(l>=r) return true;                 // a{L} will be as root ele
    int i=l+1;                            // check from next ele of root ,  for left ele , loop will stop when we get ele greter then (a[l])root (a[l]<a[i]) 
     for( ; i<r && a[l]>=a[i];i++) ;       //a[l] --> root
   for(int j=i; j<r; j++)                  // then we next start the loop for j and search for right nodes of tree ,this loop will stpo we if we get anty ele less tehn root and ginve false;
    {
if(a[l]>a[j])return false;
    }

bool left=check(a,l+1,i-1);                    // recursively checked for both subtrees.
bool right=check(a,i,r);
return left&&right;
}

int Solution::solve(vector<int> &a) 
{
return check(a,0,a.size()-1);
}
*/





