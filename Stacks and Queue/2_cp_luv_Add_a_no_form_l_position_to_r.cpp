                      // Hacker_rank

// Tips : 10^7 instruction can execute in 1 seconds
// global array are initialized to 0 by default
// this precompution technique form a sub part of many problems.

// Ques: to add elem in array from l index to r index in various quries and find max ele.
// Trick: Just add that given no at 'L' position and substract it on 'R+1' postion of that given array ,
// then takes the prefix sum of that given array. 


#include<bits/stdc++.h>
using namespace std ;
const int N=10^7+10;
long long int arr[N];

// need to declare array of 10^7 ,which can be possible on globally. 
// array has mentioned l ll type because it elemnts fall  in rtange of 10^12 and above so that ll can handle upto 10^18 appox

int main()
{
	int n,q;
	cin>>n>>q;

	while(q--)
	{
		int a,b,d;
		cin>>a>>b>>d;
		 arr[a]+=d;             // adding req no at left index
		 arr[b+1]-=d;            // removing req no at right+1 index

	}                                    // done this for q quries
   
 // arr[0]=0; already 0 global array initialized
// now do prefix sum
	for(int i=1;i<=n;i++)
	 arr[i]+= arr[i-1];
// finding max form new modified array.

int max=-1;
for(int i=1; i<=n; i++ )
        {
        	if(arr[i]>max) max=arr[i];
        }

cout<<max<<endl;
	return 0;

       //O(q + N+ N ) ~ O(N) 
}



































                   



                                            // BRUTE FORCE APPROACH




/*

int main()
{    
	int n,q; cin>>n>>q;     // no need of input already {0} perform operations only.


while(q--)
{
   int a,b,d;
   cin>>a>>b>>d;
   for(int i=a;i<=b;i++)
      arr[i]=arr[i]+d;
}

long long maxi=-1;
for(int i=1;i<=n;i++) 
{
	if(arr[i]>maxi) maxi=arr[i];
}

cout<<maxi<<endl;



//O(M * N + N ) = O( 2*10^5 * 10^7 ) =O( 10 ^ 12 )  ~ TLE (1 sec =10^7 only )
// go above code for pre computation .


	return 0;
}*/