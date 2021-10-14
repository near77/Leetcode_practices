#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::swap;
using std::vector;

void bubble_sort(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size()-i-1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

int main(void){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    bubble_sort(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}