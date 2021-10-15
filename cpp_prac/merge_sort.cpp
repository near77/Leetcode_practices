#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::swap;
using std::vector;

vector<int> merge_sort(vector<int>& nums, int start, int end){
    if(end - start == 2){
        if(nums[end-1] > nums[start]){
            return {nums[end-1], nums[start]};
        }else{
            return {nums[start], nums[end-1]};
        }
    }else if(end - start == 1){
        return {nums[start]};
    }else if(end - start == 0){
        return {};
    }
    vector<int> front = merge_sort(nums, start, end/2);
    vector<int> back = merge_sort(nums, end/2, end);
    int i = 0;
    int j = 0;
    vector<int> answer;
    while(i < front.size() && j < back.size()){
        if(front[i] > back[j]){
            answer.push_back(front[i]);
            i++;
        }else{
            answer.push_back(back[j]);
            j++;
        }
    }
    while(i < front.size()){
        answer.push_back(front[i]);
        i++;
    }
    while(j < back.size()){
        answer.push_back(back[j]);
        j++;
    }
    return answer;
}

int main(void){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums = merge_sort(nums, 0, 4);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}