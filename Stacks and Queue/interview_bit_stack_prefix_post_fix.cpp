//  Q.Evaluate the value of an arithmetic expression in Reverse Polish Notation.(Post fx)

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Input 1:
//     A =   ["2", "1", "+", "3", "*"]
//     Output 1:
//     9






#include<bits/stdc++.h>
using namespace std;




int Solpost_fix(vector<string> &a) {
int n=a.size();int i;
stack<int> s;
// need to cal post fix over here
for(i=0;i<n;i++)                 // traverse the vector string given from #front 
{                                 
      if(a[i]=="+"||a[i]=="-"||a[i]=="*"||a[i]=="/")           // if operator found then pop to operands
       {
           int op2=s.top();                                      //abc+e*-  ... then c is op2 and b is op1
           s.pop();                                               // 1 st top give operand 2 
           int op1=s.top();
           s.pop();
             if(a[i]=="+") s.push(op1+op2);                      // after operation push res baCk to staCk
             if(a[i]=="-") s.push(op1-op2);
             if(a[i]=="*") s.push(op1*op2);
             if(a[i]=="/") s.push(op1/op2);

       }
     else s.push(stoi(a[i]));          // no converted to int from string form given

}
return s.top();                      // final ans will be at top pos


}



// tried myself the prefix one

int Solpre_fix(vector<string> &a) {
int n=a.size();int i;
stack<int> s;                                      // eg : -*bb*4*ac
// need to cal post fix over here
for(i=n-1;i>=0;i--)                 // traverse the vector string given from #back
{                                 
      if(a[i]=="+"||a[i]=="-"||a[i]=="*"||a[i]=="/")           // if operator found then pop to operands
       {
           int op1=s.top();
           s.pop();
          
           int op2=s.top();                                      //-*bb*4*ac  ... a is op1 and  then c is op2
           s.pop();                                               // 1 st top give operand 1 (normal only) 
             if(a[i]=="+") s.push(op1+op2);                      // after operation push res baCk to staCk
             if(a[i]=="-") s.push(op1-op2);
             if(a[i]=="*") s.push(op1*op2);
             if(a[i]=="/") s.push(op1/op2);

       }
     else s.push(stoi(a[i]));          // no converted to int from string form given

}
return s.top();                      // final ans will be at top pos


}























int main()
{
 vector<string>v={"2", "1", "+", "3", "*"};
                                  // traverse fomr front
                                 // post fix= (2+1)*3=9
int ans=Solpost_fix(v);
cout<<ans<<"\n";
                           
                           // traverse fomr baCk   
                        //   prefix     (6+4) *(3-2) =10
 vector<string>v2={"*","+","6", "4", "-", "3", "2"};

int ans1=Solpre_fix(v2);
cout<<ans1;

}