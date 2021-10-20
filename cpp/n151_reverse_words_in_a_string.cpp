#include <string>
#include <stack>
#include <iostream>
using std::string;
using std::stack;
using std::cout;
using std::endl;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> reverse_stk;
        string tmp = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                if(tmp != ""){
                    reverse_stk.push(tmp);
                    tmp = "";
                }else{
                    continue;
                }
            }else{
                tmp += s[i];
            }
        }
        if(tmp != ""){
            reverse_stk.push(tmp);
        }
        string answer = "";
        int idx = 0;
        int word_cnt = reverse_stk.size();
        cout << word_cnt << endl;
        while(!reverse_stk.empty()){
            answer += reverse_stk.top();
            reverse_stk.pop();
            if(idx != word_cnt - 1){
                answer += " ";
            }
            idx++;
        }

        return answer;        
    }
};

int main(void){
    string s = "the sky is blue";
    Solution sol = Solution();
    cout << sol.reverseWords(s) << "***" << endl;
    s = "  hello world  ";
    cout << sol.reverseWords(s) << "***" << endl;
    return 0;
}