#include <map>
#include <queue>
using std::map;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct LevelParent{
    int level;
    int parent_val;
};

struct NodeLevel{
    int level;
    TreeNode* node;
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr){
            return false;
        }
        queue<NodeLevel> node_level_q;
        NodeLevel root_level;
        root_level.level = 0;
        root_level.node = root;
        node_level_q.push(root_level);
        map<int, LevelParent> node_level_parent;
        while(!node_level_q.empty()){
            NodeLevel node_l = node_level_q.front();
            if(node_l.node->left != nullptr){
                NodeLevel left_node_l;
                left_node_l.level = node_l.level + 1;
                left_node_l.node = node_l.node->left;
                node_level_q.push(left_node_l);
                LevelParent left_level_parent;
                left_level_parent.level = node_l.level + 1;
                left_level_parent.parent_val = node_l.node->val;
                node_level_parent[node_l.node->left->val] = left_level_parent;
            }
            if(node_l.node->right != nullptr){
                NodeLevel right_node_l;
                right_node_l.level = node_l.level + 1;
                right_node_l.node = node_l.node->right;
                node_level_q.push(right_node_l);
                LevelParent right_level_parent;
                right_level_parent.level = node_l.level + 1;
                right_level_parent.parent_val = node_l.node->val;
                node_level_parent[node_l.node->right->val] = right_level_parent;
            }
            node_level_q.pop();
        }
        return node_level_parent[x].level == node_level_parent[y].level && node_level_parent[x].parent_val != node_level_parent[y].parent_val;
    }
};