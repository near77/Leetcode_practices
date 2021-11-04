// Your interview score of 8.19/10 beats 82% of all users.
// Time Spent: 12 minutes 46 seconds
// Time Allotted: 1 hour
#include <string>
#include <vector>
#include <map>
using namespace std;

// n1528 Shuffle String
// 399 / 399 Testcases Passed
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int, char> char_idx;
        string answer = "";
        for(int i = 0; i < indices.size(); i++){
            char_idx[indices[i]] = s[i];
        }
        for(int i = 0; i <indices.size(); i++){
            answer += char_idx[i];
        }
        return answer;
    }
};
// n1226 Minimum Time Visiting All Points
// 122 / 122 Testcases Passed
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size() < 2){
            return 0;
        }
        int answer = 0;
        int horizontal = 0;
        int vertical = 0;
        int diagonal = 0;
        for(int i = 1; i < points.size(); i++){
            horizontal = 0;
            vertical = 0;
            diagonal = 0;
            horizontal = points[i][0] - points[i-1][0];
            horizontal = max(horizontal, -horizontal);
            vertical = points[i][1] - points[i-1][1];
            vertical = max(vertical, -vertical);
            diagonal = min(horizontal, vertical);
            answer += diagonal;
            answer += max(horizontal - diagonal, vertical - diagonal);
        }
        return answer;
    }
};