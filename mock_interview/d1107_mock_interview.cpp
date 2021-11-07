// Your interview score of 5.56/10 beats 50% of all users.
// Time Spent: 18 minutes
// Time Allotted: 1 hour
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
// n7 Reverse Integer
// 1032 / 1032 Testcases Passed
class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        int answer = 0;
        if(x < 0){
            negative = true;
            if(x == -2147483648){
                return 0;
            }
            x *= -1;
        }
        queue<int> numbers;
        while(x != 0){
            numbers.push(x%10);
            x /= 10;
        }
        int tmp;
        while(!numbers.empty()){
            tmp = numbers.front();
            numbers.pop();
            if(answer > 214748364){
                return 0;
            }
            answer*=10;
            answer += tmp;
        }
        if(negative){
            answer *= -1;
        }
        return answer;
    }
};
// n561 Array Partition I
// 83 / 83 Testcases Passed
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                ans += min(nums[i], nums[i+1]);
            }
        }
        return ans;
    }
};