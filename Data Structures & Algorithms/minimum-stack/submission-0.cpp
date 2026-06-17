
class MinStack {
    stack<int> s;
    stack<int> m;
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
         if (m.empty() || val <= m.top()) {
            m.push(val);
        } else {
            m.push(m.top());  // repeat current min
        }
        
    }
    
    void pop() {
        s.pop();
        m.pop();
        
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
        return m.top();
    }
};