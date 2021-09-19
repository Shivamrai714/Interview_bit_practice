#include<bits/stdc++.h>
using namespace std;

int main()
{


	int t;  cin>>t;
	while(t--)
	{
      string s;
      cin>>s;

unordered_map<char,int> m;                                     // to store count of char.
set<char> st;                                // to find distinct char present (as it will not store duplicates.)

for(int i=0;i<s.length();i++) 
	st.insert(s[i]);
    
    int n=st.size();           // know the count of distinct char.                        

int i=0,j=1; int c=0;
 m[s[i]]++;                   //mapping 1 ele to inc its count.
 c++;                         //marking cnt=1 

  // we need to traverse such that untill cnt = no of distint char. and then find min by shrinking the count form forward  

int mi=INT_MAX;

while(i<=j and j<s.length())
{
	if(c<n)
	 {
           if(m[s[j]]==0) c++;  // if new char has been encountered , inc count and add it in map
           m[s[j]]++;
           j++;
	}
else if(c==n)
{
	mi=min(mi,j-i);
if(m[s[i]]==1) c--;             // now decresing the char from start.if only 1 char is present then we need to dec it scount in map and dec out cnt & need to search in forward array until that same char is encounted again to make cnt = no size of char.
m[s[i]]--;
i++;

}
   // i is front counter and j is moving counter
}

// if else if condition is not faced in while loop that it has , meet all distinct char at last then to minimise it we are following this loop to get the space minimised.
while(c==n)
{
	mi=min(mi,j-i);     // j-i will give the size of array. 

if(m[s[i]]==1) c--;
m[s[i]]--;
i++; 
}
cout<<mi<<endl;



	}



	return 0;
}