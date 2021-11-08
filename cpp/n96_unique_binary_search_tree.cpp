#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
class Solution {
public:
    int numTrees(int n) {
        vector<int> num_of_distict_tree;
        num_of_distict_tree.push_back(1);
        num_of_distict_tree.push_back(1);
        int cur_distict_tree = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                cur_distict_tree += num_of_distict_tree[j] * num_of_distict_tree[i-j-1];
            }
            num_of_distict_tree.push_back(cur_distict_tree);
            cur_distict_tree = 0;
        }
        return num_of_distict_tree[n];
    }
};

int main(void){
    Solution s = Solution();
    cout << s.numTrees(4) << endl;
    return 0;
}