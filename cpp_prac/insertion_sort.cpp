#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::swap;
using std::vector;

void insertion_sort(vector<int>& nums){
    int n = nums.size();
    int max_num_idx;
    for(int i = 0; i < n; i++){
        max_num_idx = i;
        for(int j = i; j < n; j++){
            if(nums[j] > nums[max_num_idx]){
                max_num_idx = j;
            }
        }
        swap(nums[i], nums[max_num_idx]);
    }
}

int main(void){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    insertion_sort(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}