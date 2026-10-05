class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int gap = s[i] - 'a';
            int tmp = 26 - gap ;
            sum += tmp*(i+1);
        }
        return sum;
    }
};