// #include<bits/stdc++.h>
// using namespace std; 
// int main()
// {                            //#1.   trick to add a no from l to r index in O(n)

//                                    //1. add no at a[l] and substract no at a[r+1]
//                                    //2. take prefix sum to get results.
// 	int n; 
//    cin>>n;
//    int a[n]={0};
//    int num;
//     cin>>num;

// int l,r;     cin>>l>>r;
//    for(auto i:a) cout<<" "<<i;
   
// a[l]+=num;                         // if want to take pos put ( l-1 )
// a[r+1]-=num;

//    int	prefix[n]={0};
//     prefix[0]=a[0]; 


// for(int i=1;i<=n;i++)
//   prefix[i]=prefix[i-1]+a[i];
// cout<<endl;
// for(auto i:prefix) cout<<" "<<i;





// // or can perform the same opreration in smae array

// // for(int i=1;i<=n;i++) a[i]=a[i-1]+a[i];         // prefix sum
// // cout<<endl;
// //  for(auto i:a) 
// //  	cout<<" "<<i;



// 	return 0;}





//         // Trick 2 : finding nearest greatest on left and right  (leet code max prod)

// #include<bits/stdc++.h>
// using namespace std; 
// int main()
// {
// int n; cin>>n;
// vector<int>a(n);
// for(int i=0;i<n;i++) cin>>a[i];
// // for(auto i:a)
// //    cout<<i<<" ";

// stack<pair<int,int>>left,right;         // value and index respectively
// vector<int>L(n),R(n);                 // to store left greatest and right greatest


// // left stack wrk
// for(int i=0;i<n;i++) 
// {
// 	int x=0;        // 0 is stored if no ele is greater to it.

// 	// work on left stack to get left grt val
//    while(!left.empty() and left.top().first<=a[i]) left.pop();
   
//    if(!left.empty()) x=left.top().first;
// // push in array val and get itself into stack
//    L[i]=x;
//    left.push({a[i],i});  
// }
// cout<<"\nLeft Grtst: ";
// for(auto i:L) cout<<i<<" ";
// 	cout<<endl;




// // rigth stack wrk starting from last index
// for(int i=n-1;i>=0;i--) 
// {
// 	int x=0;
// 	// work on left stack to get left grt val
//    while(!right.empty() and right.top().first<=a[i]) right.pop();
   
//    if(!right.empty()) x=right.top().first;
// // push in array val and get itself into stack
//    R[i]=x;
//    right.push({a[i],i});  
// }
// cout<<"\nRight Grtst:";
// for(auto i:R) cout<<i<<" ";
// cout<<endl;


// // for any i ele get max prod of two no on left and right
// int ans=0;
// for(int i=0 ; i<n ; i++ ) { ans=max(ans,L[i]*R[i]); } 
// cout<<endl<<"max prod :"<<ans<<"\n";

// int p1=0,p2=0,q=0;
// for(int i=0;i<n;i++) 
//  {  int val1=0,val2=0;
//   val1=L[i]; val2=R[i];
//   cout<<"max-> for ele  "<<a[i]<<" is "<< " Left max "<<val1<<"--Right max  "<<val2<<"\n";

 // }


// 	return 0;
// }