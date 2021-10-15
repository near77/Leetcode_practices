#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::max;
class Solution {
public:
    int maxProfit_recur(vector<int>& prices) {
        int answer = 0;
        dfs(0, prices, 0, answer, 0);
        dfs(0, prices, 3, answer, 0);
        return answer;
    }
    void dfs(int idx, vector<int>& prices, int act, int &answer, int tmp){
        // 0: buy
        // 1: sell
        // 2: buy_cooldown
        // 3: sell_cooldown
        if(idx == prices.size()){
            return;
        }
        if(act == 0){
            tmp -= prices[idx];
            dfs(idx+1, prices, 1, answer, tmp);
            dfs(idx+1, prices, 2, answer, tmp);
        }else if(act == 1){
            tmp += prices[idx];
            answer = max(tmp, answer);
            dfs(idx+1, prices, 3, answer, tmp);
        }else if(act == 2){
            dfs(idx+1, prices, 1, answer, tmp);
            dfs(idx+1, prices, 2, answer, tmp);
        }else if(act == 3){
            dfs(idx+1, prices, 0, answer, tmp);
            dfs(idx+1, prices, 3, answer, tmp);
        }
    }
    int maxProfit_dp(vector<int>& prices) {
        int answer = 0;
        int n = prices.size();
        vector<vector<int>> mp(n,vector<int>(4, 0));
        mp[0][0] = -prices[0];
        mp[0][2] = -prices[0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 4; j++){
                if(j == 0){
                    mp[i][j] = mp[i-1][3] - prices[i];
                }else if(j == 1){
                    mp[i][j] = max(mp[i-1][0], mp[i-1][2]) + prices[i];
                }else if(j == 2){
                    mp[i][j] = max(mp[i-1][0], mp[i-1][2]);
                }else if(j == 3){
                    mp[i][j] = max(mp[i-1][1], mp[i-1][3]);
                }
            }
        }
        return *std::max_element(mp[n-1].begin(), mp[n-1].end());
    }
    int maxProfit_dp_opt(vector<int>& prices) {
        int answer = 0;
        int n = prices.size();
        vector<int> mp(4, 0);
        mp[0] = -prices[0];
        mp[2] = -prices[0];
        vector<int> tmp;
        for(int i = 1; i < n; i++){
            tmp = mp;
            for(int j = 0; j < 4; j++){
                if(j == 0){
                    mp[j] = tmp[3] - prices[i];
                }else if(j == 1){
                    mp[j] = max(tmp[0], tmp[2]) + prices[i];
                }else if(j == 2){
                    mp[j] = max(tmp[0], tmp[2]);
                }else if(j == 3){
                    mp[j] = max(tmp[1], tmp[3]);
                }
            }
        }
        return *std::max_element(mp.begin(), mp.end());
    }
};

int main(void){
    vector<int> nums = {1,2,3,0,2};
    Solution s = Solution();
    cout << s.maxProfit_dp_opt(nums) << endl;
    return 0;
}

