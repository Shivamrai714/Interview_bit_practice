Question 1.
Merge k sorted linked lists and return it as one sorted list.

Example :
1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20


// code 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comp
{
    bool operator()(ListNode* a,ListNode* b)
    {
 return a->val >b->val;  
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &arr) 
 {
priority_queue<ListNode*,vector<ListNode*>,comp>pq;              // priority_que<type,vecot<>,compartator>                                         // pattern to define a priority_que and to make in min PQ we use comparator fun
// listnode contains teh first index of teh all array stored (a type of 2D array)

int n=arr.size();
for(int i=0;i<n;i++)                              //pushed the 1 ele of every array given ,because Listnode contain staring indez od array and otehr respective ele are connected  via links( 2 d array like)
pq.push(arr[i]);                     // ie pused 1 ele 's of LIstNOde

ListNode* head=NULL;                      // we need to make  list which is all sorted  ele so preparing
ListNode* temp;

while(!pq.empty())
{
  ListNode* ele=pq.top();                    //top od pq gives teh min ele so put it in our linked list created above
  pq.pop();
  if(head==NULL) 
  {
  head=ele;
  temp=ele;                        
  } 
  else {
      temp->next=ele;                     //   if already had node just add new to next of prev/temp
      temp=temp->next;                     // point temp to new ele
  }

if(ele->next) pq.push(ele->next);          // checking if list n

}

return head;                                 // return head of our made list

   }





//////////////////////////////////////////////////////////////////////////////////////////

Question 2.
Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.
Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]

Input Format
First and only argument is an 2D integer matrix A.
Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.
Example Input
Input 1:
 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]
Example Output
Output 1:
 [0, 1, 2, 2, 3, 4, 6, 9, 10]
Example Explanation
Explanation 1:
 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]


// code // when need to merge k sorted array 
//1 we are pushing the 1 ele of each array in priority_queue 
// and we are mainting the row and col of each ele so we can push then int the priority_q 
// make comparator fun that will give the ele in increasing order : and we are grtting the min ele in pq.top(); and if(col+1 <m) so we push that ele in pq.  

class three 
{
    public: 
    int val,row,col;
};
struct comparator{
bool operator () (three a,three b)
{
           return a.val>b.val;
}

};

vector<int> Solution::solve(vector<vector<int> > &arr) {
priority_queue<three,vector<three>,comparator>pq;

int n=arr.size();
int m=arr[0].size();     // count of columns for array

//pushing the first ele of each array
for(int i=0;i<n;i++)
pq.push({arr[i][0],i,0});             // pq top() will give min ele because we have applied compartato on it


vector<int>ans; 

while(!pq.empty())
{  
 //
    three ele=pq.top();
     pq.pop(); 
                          // we are using the top ele to process teh other ele of array 
  int val=ele.val;
   int row=ele.row;            // row and col are mainted so we defined a class to use three variables together.
   int col=ele.col;

ans.push_back(val);              // push the ans in vector (so reeults will be ascending order bec pq gives min ele )

if(col+1<m)                  // taht ele is not out of array col
{ 
    pq.push({arr[row][col+1],row,col+1});         // pushed next ele of ele which was at top  
} 
//
}
return ans;
}








