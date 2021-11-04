// Your interview score of 6.88/10 beats 74% of all users.
// Time Spent: 16 minutes
// Time Allotted: 1 hour
#include <vector>
#include <algorithm>
using namespace std;
//n231 Power of Two
//1108 / 1108 Testcases Passed
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0){
            return false;
        }else{
            int cnt = 0;
            while(n != 0){
                n &= n-1;
                cnt += 1;
            }
            if(cnt == 1){
                return true;
            }else{
                return false;
            }
        }
    }
};
//n448 Find All Numbers Disappeared in an Array
//33 / 33 Testcases Passed
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int tmp;
        for(int i = 0; i < nums.size(); i++){
            tmp = max(-nums[i], nums[i]);
            if(nums[tmp-1] > 0){
                nums[tmp-1] *= -1;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};