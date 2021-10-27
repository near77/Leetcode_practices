#include <vector>
#include <iostream>
using std::vector;
using std::swap;
using std::cout;
using std::endl;
//TLE
class Solution_Qsort {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, nums.size());
        return;
    }
    void quick_sort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }else{
            int pivot = nums[end-1];
            int i = start - 1;
            for(int j = start; j < end - 1; j++){
                if(nums[j] < pivot){
                    i += 1;
                    swap(nums[i], nums[j]);
                }
            }
            i++;
            swap(nums[i], nums[end-1]);
            quick_sort(nums, start, i-1);
            quick_sort(nums, i+1, end);
        }
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color_cnt[3] = {0, 0, 0};
        for(int i = 0; i < nums.size(); i++){
            color_cnt[nums[i]]++;
        }
        for(int i = 0; i < color_cnt[0]; i++){
            nums[i] = 0;
        }
        for(int i = color_cnt[0]; i < color_cnt[0] + color_cnt[1]; i++){
            nums[i] = 1;
        }
        for(int i = color_cnt[0] + color_cnt[1]; i < color_cnt[0] + color_cnt[1] + color_cnt[2]; i++){
            nums[i] = 2;
        }
        return;
    }
};


