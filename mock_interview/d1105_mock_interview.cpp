// Your interview score of 2.59/10 beats 47% of all users.
// Time Spent: 1 hour
// Time Allotted: 1 hour
#include <vector>
#include <string>
#include <math.h>
using namespace std;
// n75 Sort Colors
// 87 / 87 Testcases Passed
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color_cnt[3] = {0, 0, 0};
        for(int i = 0; i < nums.size(); i++){
            color_cnt[nums[i]] += 1;
        }
        for(int i = 0; i < color_cnt[0]; i++){
            nums[i] = 0;
        }
        for(int i = color_cnt[0]; i < color_cnt[0] + color_cnt[1]; i++){
            nums[i] = 1;
        }
        for(int i = color_cnt[0]+color_cnt[1]; i < color_cnt[0]+color_cnt[1]+color_cnt[2]; i++){
            nums[i] = 2;
        }
        return;
    }
};
// n402 Remove K Digits
// 23 / 40 Testcases Passed
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.length()){
            return "0";
        }
        int smallest = pow(10, num.length() - k);
        dfs(num, num.length() - k, 0, smallest, 0);
        return to_string(smallest);
    }
    void dfs(string&num, int rest, int idx, int & smallest, int cur){
        if(rest == 0 || idx >= num.length()){
            return;
        }else{
            dfs(num, rest, idx+1, smallest, cur);
            if(rest - 1 == 0){
                int tmp = num[idx]-'0';
                cur = cur*10 + tmp;
                smallest = min(smallest, cur);
            }else{
                int tmp = num[idx]-'0';
                cur = cur*10 + tmp;
                dfs(num, rest-1, idx + 1, smallest, cur);
            }
        }
    }
};

// Sol
class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer = "";
        for(int i = 0; i < num.length(); i++){
            while(answer.back() > num[i] && answer.length() && k){
                answer.pop_back();
                k--;
            }
            if(answer.length() || num[i] != '0'){
                answer.push_back(num[i]);
            }
        }
        while(answer.length() && k--){
            answer.pop_back();
        }
        if(answer.length()){
            return answer;
        }else{
            return "0";
        }
    }
};