class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (auto cur : s) {
            if (cur == '(' || cur == '[' || cur == '{') {
                st.push(cur);  // Push opening brackets onto the stack
            } 
            else {
                if (st.empty()) {
                    return false;  // Return false if stack is empty when encountering a closing bracket
                }
                
                // Match closing brackets with the top of the stack
                if ((cur == ')' && st.top() == '(') ||
                    (cur == ']' && st.top() == '[') ||
                    (cur == '}' && st.top() == '{')) {
                    st.pop();  // Pop the matched opening bracket
                } else {
                    return false;  // Return false if brackets do not match
                }
            }
        }
        
        return st.empty();  // If stack is empty, all brackets are matched
    }
};
