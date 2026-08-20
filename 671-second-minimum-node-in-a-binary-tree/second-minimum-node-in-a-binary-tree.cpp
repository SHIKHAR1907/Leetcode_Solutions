/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void secondMin(TreeNode* root , int minimum ,  long long& ans){
        if(root == nullptr) return ;

        if(root->val > minimum) ans = min(ans,(long long)root->val);

        secondMin(root->left,minimum,ans);
        secondMin(root->right,minimum,ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int minimum = root->val;
        long long ans = LLONG_MAX;

        secondMin(root,minimum,ans);
        return ans == LLONG_MAX ? -1 :ans;

    }
};