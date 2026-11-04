class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);

        // int curr 

        for(int i = 0 ; i < temperatures.size();i++){
            int curr = temperatures[i];
            
            while(!st.empty() && curr > temperatures[st.top()]){
                int pre = st.top();
                st.pop();

                ans[pre] = i-pre;
            }
            st.push(i);
        }
        return ans;
    }
};