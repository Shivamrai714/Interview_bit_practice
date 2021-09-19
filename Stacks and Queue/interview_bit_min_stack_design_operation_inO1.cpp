// Q.Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) – Push element x onto stack.
// pop() – Removes the element on top of the stack.
// top() – Get the top element.
// getMin() – Retrieve the minimum element in the stack.
// Note that all the operations have to be constant time operations.

// Questions to ask the interviewer :

// Q: What should getMin() do on empty stack? 
// A: In this case, return -1.

// Q: What should pop do on empty stack? 
// A: In this case, nothing. 

// Q: What should top() do on empty stack?
// A: In this case, return -1













/*
//DEvelop min stack to do operation in O(1)

// we need one stack to store min ele
// to make in O(1)  we are going to use it 1 trick, we are going to hava a track of min ele and that case we are pushing the (2*x-min) ele in stack 

//  keep one mini =to store min of ele
// if(x<mini) we are pushing 2*x-mini in stack and store that ele in mini




stack<int> s;
int mini;
MinStack::MinStack() {
    while(!s.empty()) s.pop();      // to remove previous ele
}

void MinStack::push(int x) {
if(s.empty()) {s.push(x); mini=x; }
else if(x<mini) {
                 // we push an auxillary ele in stack ans storing ori in mini  (push_2*x-min) update mini=x;
  s.push(2*x-mini) ; mini=x;
}
else s.push(x);               // we need to wory sbount the grt no
}

void MinStack::pop() 
{
if(s.empty()) return;
if(s.top()<mini)                     // we are checking wheter out auxillary ele is present at top or not
{
   int prev_min=2*mini-s.top();             // we have pushed on top=2*x-mini; & stored x in mini--> now to get back mini=2*x-top();
                                            // top is having auxillay ele ,mini is having the min ele track
   mini=prev_min;                        // we have tracked prev min before pop
   s.pop();
}
else s.pop();
}

int MinStack::top() {                     // mini is storing x, s.top() is storing auxi ele
if(s.empty()) return -1;
if(s.top()<mini) return mini ;            // we are storing min in only min; and stack is having auxillay ele for(x<mini) and  mini= x                 
else return s.top();
}

int MinStack::getMin() {
if(s.empty()) return -1;
return mini;            // as we are storing min of all in 'mini '

}
*/
