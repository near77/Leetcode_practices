#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::max_element;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //buy1, buy2, sell_1, sell_2, buy1_cooldown, buy2_cooldown, sell1_cooldown, sell2_cooldown, cooldown
        vector<int> mp(9, -100001);
        mp[0] = -prices[0];
        mp[8] = 0; 
        int n = prices.size();
        vector<int> tmp;
        for(int i = 1; i < n; i++){
            tmp = mp;
            for(int j = 0; j < 8; j++){
                if(j == 0){
                    mp[j] = tmp[8] - prices[i];
                }else if(j == 1){
                    mp[j] = max(tmp[2] - prices[i], tmp[6] - prices[i]);
                }else if(j == 2){
                    mp[j] = max(tmp[0] + prices[i], tmp[4] + prices[i]);
                }else if(j == 3){
                    mp[j] = max(tmp[1] + prices[i], tmp[5] + prices[i]);
                }else if(j == 4){
                    mp[j] = max(tmp[0], tmp[4]);
                }else if(j == 5){
                    mp[j] = max(tmp[1], tmp[5]);
                }else if(j == 6){
                    mp[j] = max(tmp[2], tmp[6]);
                }else if(j == 7){
                    mp[j] = max(tmp[3], tmp[7]);
                }
            }
            cout << "[";
            for(int j = 0; j < 8; j++){
                cout << mp[j] << " ,";
            }
            cout << mp[8] << "]" << endl;
        }
        return *max_element(mp.begin(), mp.end());   
    }
};

int main(void){
    vector<int> nums = {3,2,6,5,0,3};
    Solution s = Solution();
    cout << s.maxProfit(nums) << endl;
    return 0;
}