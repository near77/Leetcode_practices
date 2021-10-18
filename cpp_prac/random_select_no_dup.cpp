#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h> 
using std::vector;
using std::map;
using std::cout;
using std::endl;

int random(void){
    vector<int> rand_num_range;
    map<int, int> used_map;
    for(int i = 0; i < 500; i++){
        rand_num_range.push_back(i);
        used_map[i] = 0;
    }
    int num;
    for(int i = 0; i < 500; i++){
        num = rand()%rand_num_range.size();
        if(used_map[rand_num_range[num]] != 0){
            cout << "Duplicated" << endl;
        }
        // cout << rand_num_range[num] << endl;
        used_map[rand_num_range[num]] = 1;
        rand_num_range.erase(rand_num_range.begin() + num);
    }
    return 0;
}
int main(void){
    random();
    return 0;
}