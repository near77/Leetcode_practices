#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target2sum;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int left;
        int right;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0){
                if(nums[i] == nums[i-1]){
                    continue;
                }
            }
            target2sum = -nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] == target2sum){
                    vector<int> vec = {nums[i], nums[left], nums[right]};
                    if(left - 1 > i && nums[left] == nums[left - 1]){
                        left++;
                        right--;
                    }else{
                        answer.push_back(vec);
                        left++;
                        right--;
                    }
                }else if(nums[left] + nums[right] > target2sum){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return answer;
    }
};