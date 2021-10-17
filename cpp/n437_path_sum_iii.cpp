#include <map>
#include <unordered_map>
using std::map;
using std::unordered_map;

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
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        map<int, int> sum_map;
        sum_map[0] = 1;
        dfs(root, 0, count, targetSum, sum_map);
        return count;
    }
    void dfs(TreeNode* node, int cur_sum, int &count, int targetSum, map<int, int> sum_map){
        if(node == nullptr){
            return;
        }
        cur_sum += node->val;
        if(sum_map.find(cur_sum - targetSum) != sum_map.end()){
            count += sum_map[cur_sum - targetSum];
        }
        if(sum_map.find(cur_sum) != sum_map.end()){
            sum_map[cur_sum] += 1;
        }else{
            sum_map[cur_sum] = 1;
        }
        dfs(node->left, cur_sum, count, targetSum, sum_map);
        dfs(node->right, cur_sum, count, targetSum, sum_map);
    }
};

class Solution_sol {
    unordered_map<long, int> hashMap;
    int count;
    int target;
    void find(TreeNode* root, long sum) {
        if (root == 0) return;
        sum += root->val;
        int prefixSum = sum - target;
        if (hashMap.count(prefixSum)) {
            count += hashMap[prefixSum];
        }
        hashMap[sum]++;
        find(root->left, sum);
        find(root->right, sum);
        hashMap[sum]--;//Remove after travered left and right subtree to avoid reused
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        target = targetSum;
        hashMap[0] = 1;
        find(root, 0);
        return count;
    }
};