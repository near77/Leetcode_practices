#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int lp = 0;
        int rp = 0;
        int product = 1;
        int count = 0;
        while(rp < nums.size()){
            product *= nums[rp];
            rp++;
            while(product >= k && lp < rp){
                product/=nums[lp];
                lp++;
            }
            count += rp-lp;
        }
        return count;
    }
};
int main(){
    Solution s = Solution();
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);
    int k = 100;
    cout << s.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}