/*Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 */

code 
#include<list>
unordered_map<int,list<pair<int,int>>::iterator> mp;                  // map will store the ( key,pointer to val in list )
list<pair<int,int>> dq;    // ( key , value )
int n;
 
LRUCache::LRUCache(int capacity) {
n=capacity;
mp.clear();
dq.clear();
}
 
int LRUCache::get(int key) 
{
    if(mp.count(key)==0)  return -1;      // if map do not  have any count 
 
    // if present just we need to update teh list with most freqwuent list used.
 
   auto it=mp[key];                 // assign pointer it to the entry at key.
       int val=it->second;            // it is pointer : pointing to (key,value);
                                      
                                      // remove it from that position 
      dq.erase(it);                                //O(1) erase as uncontinous memory allocation                                
      dq.push_back({key,val});          // and put it into last pos : most recently used
 
// also need to update it new pointer location in map.
  
  it=dq.end(); // will point to the end (nxt to last ele)
  it--;           // decrement  it to the last ele (-- as it was pointer )
 
                        // update the map value with this new address
mp[key]=it;
 
return val;               // this is ele val which user need to get
}
 
void LRUCache::set(int key, int val) {
 
if(mp.count(key)) 
{                          // if just key is found , remove it from list and it end we will upatte this on the last that is most recently used. 
    auto it=mp[key];
    dq.erase(it);
}
 else if (mp.size()==n)                // if size is full then we need to remove 1 ele of list and then at last we will insert it at last position as most recently used.
 {
int k=dq.front().first;
dq.pop_front();
mp.erase(k);               // this ele will be gone from every where (map and dq)
 
 }
 // now pushing this to last pos for both cases (if // else if )
 
 dq.push_back({key,val});   
 auto it=dq.end(); it--;         // updated pointer posistion in map
 mp[key]=it;
 
 
}


//
Method 1 using O(n) space 


// Method 1 : O(n) space approch

we are using an update function to change the position od ele which i svisistd by user at last position.push_back
/*
// Trick just : run loop till size

while(size--)
{
  if(l.front()!=key) l.push_back(l.front());
} l.pop_front();
@ last 

l.push_back(key);

*/







 code start 

unordered_map<int,int>m;
deque<int>l;
int n;

LRUCache::LRUCache(int capacity) {
n=capacity;
m.clear();
l.clear();
}
void update(deque<int> &l,int key)
{
int sz=l.size();
while(sz--)
{
    if(l.front()!=key) l.push_back(l.front());
    l.pop_front();
}
}

int LRUCache::get(int key) {
    if(m.count(key)==0) return -1;
    update(l,key);
    l.push_back(key);
return m[key];
}

void LRUCache::set(int key, int val) {
    if(m.count(key))
    {
        update(l,key);
    }
    else if(m.size()==n)
    {
        int k=l.front();
        l.pop_front();
        m.erase(k);

    }

    l.push_back(key);
m[key]=val;
}






























































 simpplifed repeated 

 ×  Method 2 
#include<list>
unordered_map<int,list<pair<int,int>>::iterator>m;          // key , pointer to list
list<pair<int,int>>l;
 
int n;
LRUCache::LRUCache(int capacity) 
{   //constructor
   n=capacity;
   m.clear();
   l.clear();
}
 
int LRUCache::get(int key)
{
    if(m.count(key)==0) return -1;
 
    auto it=m[key];
    int val=it->second;
      
      l.erase(it);
 
      l.push_back({key,val});
      it=l.end(); it--;
      m[key]=it;
 
return val;
}
 
void LRUCache::set(int key, int val) 
{  // case 1 
if(m.count(key)) 
{
    auto it=m[key];
    l.erase(it);
    // will update at last commonly for all cases
}
else if(m.size()==n) // size is full ,new will be added after removing the first
 {  // case 2
    // remove front of list
    int key=l.front().first;
    l.pop_front();                    // remove from list
    m.erase(key);                     // rmv form map
// will up[date]/push)back at lasat
}
// common for all 
 
l.push_back({key,val});
//update map address also with this new val
 
auto it =l.end();
it--;
m[key]=it;
 
 
}