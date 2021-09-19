#include<bits/stdc++.h>
using namespace std;
int main()
{


// new working simpliifed using auto and range based loops

vector<pair<char,int>> v5={{'a',1},{'b',4}};

for(auto &i : v5) cout<<i.first<<" "<<i.second<<"\n";

	cout<<endl;























  vector<pair<char,int>> v1;             // used vectors as like a pair.
  v1.push_back({'a',1});
  v1.push_back({'b',2});
  v1.push_back({'c',3});  
  v1.push_back({'d',4});



for(auto o:v1) cout<<o.first<<"      "<<o.second<<"\n" ;       // range based loop and auto keyword







vector<int> v(4,6);

// most used to avoid complex code of iterators

 for(auto &i: v1) {  i.first++; i.second++; // cout<<i.first<<" "<<i.second<<"\n";      // to make changes pass value in references, by default it is passed by value(copy)
 }
cout<<endl;

  // passed reference     --> actual values comes to the varible to which & is used.
for(auto i: v1 )  cout<<i.first<<"  "<<i.second<<"\n"; cout<<endl;









//                   printing  using iterator


// vector<pair<char,int>>:: iterator it;
// for(it=v1.begin();it!=v1.end();++it)
// cout<<(*it).first<<"   "<<(*it).second<<"\n";
// cout<<endl;



// for(it=v1.begin();it!=v1.end();++it)            
// cout<<(it)->first<<"   "<<(it)->second<<"\n";
// cout<<endl;
                      
                      // means    (*it).first==it->first;

	return 0;

}