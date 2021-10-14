#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

int maxProduct(vector<int>& nums) {
    int result = nums[0];
    int max_p = nums[0];
    int min_p = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < 0){
            int temp = max_p;
            max_p = max(min_p*nums[i], nums[i]);
            min_p = min(temp*nums[i], nums[i]);
        }else{
            max_p = max(max_p*nums[i], nums[i]);
            min_p = min(min_p*nums[i], nums[i]);
        }
        result = max(result, max_p);
    }
    return result;        
}


int main(){
    vector<int> nums;
    nums.push_back(8);
    nums.push_back(0);
    nums.push_back(1);
    cout << maxProduct(nums) << endl;
    return 0;
}