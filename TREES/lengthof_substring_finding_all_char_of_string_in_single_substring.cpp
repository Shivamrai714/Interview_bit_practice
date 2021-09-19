/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.
*/

// SUBSTRING CONTAINING ALL CHARACTERS OF MIN LENGTH OF TEH GIVEN STRING.

#include<bits/stdc++.h>
using namespace std ;
int main()
{      unordered_map<int,int>mp;

string s; cin>>s;
int n=s.size();
unordered_map<char,int>m;
set<char>st; 

for(int i=0;i<n;i++)
{ st.insert(s[i]); }

int count=st.size();    //cnt of distinct element 
int cnt=0,i=0,j=1;
m[s[i]]++;                     // if only 1 char string is given then this help
cnt++; 

int mini=INT_MAX;
//if(s.size()==1) mini=1;

while(i<=j  and j<s.length())
{
 	if(cnt<count)
	{ 
		if(m[s[j]]==0) cnt++;
		m[s[j]]++;	
       j++;
	}
else if(cnt==count)
	{
		mini=min(mini,j-i); mp[mini]=i;
		if(m[s[i]]==1) cnt--;
		m[s[i]]--;
      
       i++;
	}

	while(cnt==count)
	{       mini=min(mini,j-i); mp[mini]=i;
		if(m[s[i]]==1) cnt--;
		m[s[i]]--;
		i++;
	}


}

cout<<"MINI LENGTH -> "<<mini<<endl;
cout<<endl<<"the substring is  :->  "; 
 ////////////////////////////////////////////////////////////////////////////////////////

/*trying to give the output of string of that min length using map to store the pos of starting index of min length
*/


int x=mp.at(mini);                       

string str="";
for(int i=x;i<x+mini;i++)
	str+=s[i];

cout<<str;
return 0;
}
/*
queue<char> q;
for(int i=x;i<x+mini;++i)
q.push(s[i]);

int NN=q.size();
char arr[NN];
for(int i=0;i<NN;i++)
{arr[i]=q.front();
	q.pop();
}

for(int i=0;i<NN;i++)
cout<<arr[i];




	return 0;

 }

*/


























/*

                                   // self written code not working


#include<bits/stdc++.h>
using namespace std;
int main()
{

string s; cin>>s;

int n=s.size();

map<char,int>m;
set<char>st;

for(int i=0;i<n;i++) st.insert(s[i]);
int count=st.size();                   // to get distinct characters

int cnt=0;  
m[s[0]]++;  cnt++;            // increase the count of 1 char  , so we can use 2 pointer for sliding window 

int mini=INT_MAX;

int i=0,j=1; int index,o=0;
while(i<j && j<s.size())
{    

 if(cnt<count)
	{     if( m[s[j]] ==0) { cnt++;  m[s[j]]++;  o=1; }    // ie unique char is encountered
      else m[s[j]]++;
  j++;    
    }

 while(cnt==count)
      {   if(o)
          {mini=min(mini,j-i); o=0;}  // as j will be incremented already  

       if(m[s[i]]>1) m[s[i]]--;
       else if( (m[s[i]]==1) and j!=s.size())
        {   m[s[i]]--; 
         cnt--; 
         index=i;
        }
     
  i++; 
      }
if(cnt==count and j==s.size()) 
	mini=min(mini,j-index-1);

}
cout<<mini;
	return 0;
}*/