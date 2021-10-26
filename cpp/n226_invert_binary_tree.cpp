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
    TreeNode* invertTree(TreeNode* root){
        invert_btree(root);
        return root;
    }
    void invert_btree(TreeNode* node){
        if(node == nullptr){
            return;
        }else{
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            invert_btree(node->left);
            invert_btree(node->right);
        }
    }
};