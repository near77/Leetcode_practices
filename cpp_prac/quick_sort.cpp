#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::swap;
using std::vector;

void quick_sort(vector<int>& nums, int start, int end){
    if(start >= end){
        return;
    }
    int pivot = nums[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(nums[j] < pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    i++;
    swap(nums[end], nums[i]);
    quick_sort(nums, start, i-1);
    quick_sort(nums, i + 1, end);
}

int main(void){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    quick_sort(nums, 0, nums.size() - 1);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}