class MyQueue {
public:
// amortised 
 stack<int>s1;
 stack<int>s2;
  int peek1=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
     if(s1.empty())
     peek1= x;
    
     s1.push(x);
     x++;
    }
    
    int pop() {
     if(s2.empty())
     {  //t.c -->o(n)
         while(!s1.empty())
         {
             int a= s1.top();
             s1.pop();
             s2.push(a);
         }
     }
     //t.c -->O(1)
     int val = s2.top();
     s2.pop();
     return  val;

        
    }
    
    int peek() {
        //t.c -->o(1)
        if(s2.empty())
        {
            return peek1;
        }
        else
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty
        ())
        return true;
        else
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */