#include <iostream>
#include <vector>
#include <map>
using std::cout;
using std::endl;
using std::vector;
using std::map;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> remainder_map;
        remainder_map[0] = 1;
        int count = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(remainder_map.find(sum - k) != remainder_map.end()){
                count += remainder_map[sum-k];
            }
            if(remainder_map.find(sum) != remainder_map.end()){
                remainder_map[sum] += 1;
            }else{
                remainder_map[sum] = 1;
            }
        }
        return count;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    int k = 2;
    Solution s = Solution();
    cout << s.subarraySum(nums, k) << endl;
    return 0;
}