class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // initialize stack with -1
        int maxLen = 0;

        // treverse the whole string.
        for (int i = 0; i < s.size(); i++) {
            // opening bracket occurs the push into the stack.
            if (s[i] == '(')
                st.push(i);
            else {
                // first pop - when closing bracket ocuurs.
                st.pop();

                // if stack is not empty - case when correct order of closing bracket comes
                if (!st.empty()) {
                    int len = i - st.top();
                    maxLen = max(maxLen, len);
                }

                // no opening barcket occurs in the top of the stack but closing barckets comes then after poping the top element which is -1 we have to put the next index from which we have to count the no of valid brackets.
                else {
                    st.push(i);
                }
            }
        }
        return maxLen;
    }
};