#include <iostream>
using namespace std;

//解法一 --- 暴力解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j; //循环变量，且只能在此处初始化
        for (i = 0; i < nums.size() - 1; i++) 
            for (j = i + 1; j < nums.size(); j ++) 
                if (nums[i] + nums[j] == target) return {i, j};
        return {i, j}; //此处的return不能省略
    }
};

int main() {

    cout << "两数之和" << endl;

    return 0;
}