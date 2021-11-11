#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_sum = 99999;
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            cur_sum += nums[i];
            min_sum = min(cur_sum, min_sum);
        }
        if(min_sum > 0){
            return 1;
        }else{
            return(-1*min_sum + 1);
        }
    }
};