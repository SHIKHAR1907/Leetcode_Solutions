class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(char x : s){
            if(x == '('){
                st.push(x);
            }else{
                if(!st.empty() && st.top() == '('){// the coindition will chaeck that the openind and closing are going well and removing the pair of the stack meaning that the bracket is completed
                    st.pop();
                }else{// it will push the elemnt if it not closing  the size of the stack will become the  required no. of paranthesis
                    st.push(x);
                }

            }
        }
        return st.size();
    }
};