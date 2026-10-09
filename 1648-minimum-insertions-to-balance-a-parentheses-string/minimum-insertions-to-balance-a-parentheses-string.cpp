
class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } 
            else {
                // If the next character is also ')',
                // consume the pair together.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    ans++; // Insert a missing ')'
                }

                if (!st.empty()) {
                    st.pop();
                } 
                else {
                    ans++; // Insert a missing '('
                }
            }
        }

        // Each remaining '(' needs two ')'
        ans += 2 * st.size();

        return ans;
    }
};
