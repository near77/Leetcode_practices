#include <vector>
#include <map>
#include <iostream>
using std::vector;
using std::map;
using std::cout;
using std::endl;

//TLE
class Solution0 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int> used_num_idx;
        int max_sum = 0;
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(used_num_idx.find(nums[i]) != used_num_idx.end()){
                cur_sum = 0;
                int j = used_num_idx[nums[i]]+1;
                used_num_idx.clear();
                for(j; j <= i; j++){
                    used_num_idx[nums[j]] = j;
                    cur_sum += nums[j];
                }
            }else{
                cur_sum += nums[i];
                used_num_idx[nums[i]] = i;
            }
            if(cur_sum > max_sum){
                max_sum = cur_sum;
            }
        }
        return max_sum;
    }
};

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0;
        int cur_sum = 0;
        int start_idx = 0;
        map<int, int> used_num_idx;
        vector<int> prefix_sum;
        prefix_sum.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            prefix_sum.push_back(prefix_sum[i-1] + nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(used_num_idx.find(nums[i]) != used_num_idx.end()){
                if(used_num_idx[nums[i]] < start_idx){
                    cur_sum += nums[i];
                }else{
                    cur_sum = prefix_sum[i] - prefix_sum[used_num_idx[nums[i]]];
                    start_idx = used_num_idx[nums[i]] + 1;
                }
            }else{
                cur_sum += nums[i];
            }
            used_num_idx[nums[i]] = i;
            if(cur_sum > max_sum){
                max_sum = cur_sum;
            }
        }
        return max_sum;
    }
};

int main(void){
    vector<int> nums = {5,2,1,2,5,2,1,2,5,8,7,2,3,9,2,6};
    Solution s = Solution();
    cout << s.maximumUniqueSubarray(nums) << endl;
    return 0;
}


// [4,2,4,5,6]
// [5,2,1,2,5,2,1,2,5,8,7,2,3,9,2,6]
// [10000,1,10000,1,1,1,1,1,1]
// [1,1,1,1,1,1]