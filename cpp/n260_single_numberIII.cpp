#include <vector>
#include <map>
using std::vector;
using std::map;
// Time: O(n) Spavce: O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer;
        map<int, int> cnt;
        for(int i = 0; i < nums.size(); i++){
            if(cnt.find(nums[i]) != cnt.end()){
                cnt[nums[i]]++;
            }else{
                cnt[nums[i]] = 1;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(cnt[nums[i]] == 1){
                answer.push_back(nums[i]);
            }
        }
        return answer;
    }
};
// Time: O(n) Space: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer = {0, 0};
        int a_xr_b = 0;
        for(int i = 0; i < nums.size(); i++){
            a_xr_b ^= nums[i];
        }
        int mask = 1;
        while(!(a_xr_b & mask)){
            mask <<= 1; // Find right most set bit
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & mask){
                answer[0] ^= nums[i]; // Seperate a and b using set bit
            }else{
                answer[1] ^= nums[i];
            }
        }
        return answer;
    }
};