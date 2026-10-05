class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char c : s){
            if(c == '('){
                st.push(0);

            }else{
                int curr = st.top();// check the ending of thte paranthesis is successfull or not if it 0 then succeess if not then we neef to store the value of top of stack because we are poping its top in the next step to have the knowledge tha tupper one is successfully removed we use it
                st.pop();
                int tmp = (curr == 0) ? 1 : 2* curr;// if the () is alone nothing inside it means score = 1 or if the bracket contains any bracket inside it will treated as 2 * the value of current

                st.top() += tmp; 
                
            }
        }

        return st.top();
    }
};