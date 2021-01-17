#include <iostream>
using namespace std;

//解法一 --- 循环队列
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result(nums.size(), -2);
        for (int i = 0; i < nums.size(); i++)
            result[(i + k) % nums.size()] = nums[i];
        for (int i = 0; i < nums.size(); i++) nums[i] = result[i];
    }
};

//解法二 --- 环状替换
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count = gcd(k, nums.size());
        for (int start = 0; start < count; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                swap(prev, nums[next]);
                current = next;
            } while(current != start);
        }
    }
};

//解法三 --- 数组翻转
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

int main() {

    cout << "旋转数组" << endl;

    return 0;
}