class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(char x :s){
            if(x == '('){

                if(!st.empty()){
                    ans += "(";
                }
                st.push(x);
            }else{
                st.pop();
                if(!st.empty()){
                    ans+=")";
                }
            }
        }
        return ans;
    }

};