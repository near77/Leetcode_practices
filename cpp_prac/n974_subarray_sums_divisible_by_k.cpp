#include <vector>
#include <map>
#include <iostream>
using std::vector;
using std::map;
using std::cout;
using std::endl;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> sum_map;
        sum_map[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum_map.find((sum%k + k)%k) == sum_map.end()){
                sum_map[(sum%k + k)%k] = 1; 
            }else{
                sum_map[(sum%k + k)%k] += 1;
            }
        }
        map<int, int>::iterator iter = sum_map.begin();
        while(iter != sum_map.end()){
            count += iter->second * (iter->second - 1)/2;
            iter++;
        }
        return count;
    }
};

int main(){
    vector<int> nums;
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(0);
    // nums.push_back(-2);
    // nums.push_back(-3);
    // nums.push_back(1);
    // int k = 5;
    nums.push_back(7);
    nums.push_back(-5);
    nums.push_back(5);
    nums.push_back(-8);
    nums.push_back(-6);
    nums.push_back(6);
    nums.push_back(-4);
    nums.push_back(7);
    nums.push_back(-8);
    nums.push_back(-7);
    int k = 7;
    Solution s = Solution();
    cout << s.subarraysDivByK(nums, k) << endl;
    return 0;
}