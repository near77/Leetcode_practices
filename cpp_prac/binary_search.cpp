#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
bool binary_search(vector<int>&nums, int begin, int end, int target){
    if(begin >= end){
        return false;
    }
    int middle = (begin+end)/2;
    if(nums[middle] == target){
        return true;
    }else if(nums[middle] > target){
        return binary_search(nums, begin, middle, target);
    }else{
        return binary_search(nums, middle + 1, end, target);
    }
}

int main(void){
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8};
    int target = 7;
    cout << binary_search(nums, 0, nums.size(), target) << endl;
    return 0;
}