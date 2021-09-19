Problem Description

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.


A = "abadbc"
Output 1:
 "aabbdd"







string Solution::solve(string str) {
    /// we are going to store the count of char in vector so when cnt>1 will pop fontt ele of queue

queue<char>q;
vector<int>v(26,0); 
string ans ="";
// ttraverse along the string
for(char c:str)
{
   q.push(c);
   v[c-'a']++;

   while(!q.empty() and v[q.front()-'a']>1) q.pop();   // remomve teh rep char if count is >1
   if(!q.empty()) ans+=q.front();
   else ans+='#';

}
return ans;


}
