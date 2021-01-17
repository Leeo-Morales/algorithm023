#include <iostream>
using namespace std;

//解法一 --- 两遍哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        vector<int> b (2, -1);
        for (int i = 0; i < nums.size(); i++)
            a.insert(map<int, int>::value_type(nums[i], i));
        for (int i = 0; i < nums.size(); i++)
            if (a.count(target - nums[i]) > 0 && a[target - nums[i]] != i) {
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
        return b;
    }
};

//解法二 --- 一遍哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        vector<int> b(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i]) > 0) {
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
            a[nums[i]] = i;
        }
        return b;
    }
};

int main() {

    cout << "两数之和" << endl;

    return 0;
}