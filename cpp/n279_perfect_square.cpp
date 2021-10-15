#include <algorithm>
#include <iostream>
using std::fill_n;
using std::min;
using std::cout;
using std::endl;

class Solution {
public:
    int numSquares_DP(int n) {
        //DP TLE
        int* opt_nums = new int[n+1];
        for(int i = 0; i <= n; i++){
            opt_nums[i] = i;
        }
        for(int i = 0; i <= n; i++){
            if(i*i <= n){
                opt_nums[i*i] = 1;
            }else{
                break;
            }
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= i/2; j++){
                opt_nums[i] = min(opt_nums[i], opt_nums[j] + opt_nums[i-j]);
            }
        }
        return opt_nums[n];
    }
    int numSquares(int n) {
        if(n < 4){
            return n;
        }else{
            
        }
    }
};


int main(void){
    Solution s = Solution();
    cout << s.numSquares_DP(69) << endl;
}