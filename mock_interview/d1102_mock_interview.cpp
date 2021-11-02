#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//n118 Pascal's Triangle
//14 / 14 Testcases Passed
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i = 0; i < numRows; i++){
            vector<int> tmp;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    tmp.push_back(1);
                }else{
                    if(i-1 < answer.size()){
                        tmp.push_back(answer[i-1][j-1]+answer[i-1][j]);
                    }
                }
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};

//n662 Maximum Width of Binary Tree
//65 / 112 Testcases Passed
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct NodeNumber{
    TreeNode* node;
    int number;
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<NodeNumber> tq;
        NodeNumber root_node;
        root_node.node = root;
        root_node.number = 0;
        tq.push(root_node);
        int max_width = 0;
        int low = 3000;
        int high = 0;
        NodeNumber tmp;
        while(!tq.empty()){
            NodeNumber node = tq.front();
            tq.pop();
            low = min(low, node.number);
            high = max(high, node.number);
            if(tq.empty()){
                max_width = max(max_width, high-low+1);
                low = 3000;
                high = 0;
            }
            if(node.node->left != nullptr){
                tmp.node = node.node->left;
                tmp.number = node.number*2;
                tq.push(tmp);
            }
            if(node.node->right != nullptr){
                tmp.node = node.node->right;
                tmp.number = node.number*2+1;
                tq.push(tmp);
            }
            
        }
        return max_width;
    }
};

// Your interview score of 2.27/10 beats 50% of all users.
// Time Spent: 1 hour
// Time Allotted: 1 hour