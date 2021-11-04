
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int answer = 0;
        dfs(root, answer, false);
        return answer;
    }
    void dfs(TreeNode*node, int &cnt, bool is_left){
        if(node->left == nullptr && node->right == nullptr){
            if(is_left){
                cnt += node->val;
            }else{
                return;
            }
        }
        if(node->left != nullptr){
            dfs(node->left, cnt, true);
        }
        if(node->right != nullptr){
            dfs(node->right, cnt, false);
        }
        return;
    }
};