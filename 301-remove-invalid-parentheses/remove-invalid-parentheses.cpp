class Solution {
public:

    void dfs(string s, int start, int leftRemove, int rightRemove,
             unordered_set<string>& ans) {

        // We have removed all required brackets
        if (leftRemove == 0 && rightRemove == 0) {

            if (isValid(s)) {
                ans.insert(s);
            }

            return;
        }

        for (int i = start; i < s.length(); i++) {

            // Avoid generating duplicate strings
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (leftRemove > 0 && s[i] == '(') {

                string next = s.substr(0, i) + s.substr(i + 1);

                dfs(next, i, leftRemove - 1,
                    rightRemove, ans);
            }

            // Remove ')'
            if (rightRemove > 0 && s[i] == ')') {

                string next = s.substr(0, i) + s.substr(i + 1);

                dfs(next, i, leftRemove,
                    rightRemove - 1, ans);
            }
        }
    }

    bool isValid(string s) {

        int balance = 0;

        for (char c : s) {

            if (c == '(')
                balance++;

            else if (c == ')')
                balance--;

            // More ')' than '('
            if (balance < 0)
                return false;
        }

        // Equal number of '(' and ')'
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum brackets that must be removed
        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            }

            else if (c == ')') {

                if (leftRemove > 0)
                    leftRemove--;

                else
                    rightRemove++;
            }
        }

        unordered_set<string> ans;

        dfs(s, 0, leftRemove, rightRemove, ans);

        return vector<string>(ans.begin(), ans.end());
    }
};