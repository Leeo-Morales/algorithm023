#include <iostream>
using namespace std;

//解法一 --- 暴力解法
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int temp = 0;
        for (int i = 0; i < arr2.size(); ++i)
            for (int j = temp; j < arr1.size(); ++j)
                if (arr1[j] == arr2[i])
                    swap(arr1[j], arr1[temp++]);
        sort(arr1.begin() + temp, arr1.end());
        return arr1;
    }
};

//解法二 --- 哈希解法
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        map<int, int> count;
        for (auto nums : arr1) count[nums]++;
        for (auto nums : arr2) {
            while (count[nums]--) result.push_back(nums);
            count.erase(nums);
        }
        for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
            while ((it->second)--) result.push_back(it->first);
        return result;
    }
};

//解法三 --- 桶排序法
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int freq[1001] = {0};
        for (auto nums : arr1) freq[nums]++;
        for (auto nums : arr2)
            while (freq[nums]) {
                result.push_back(nums);
                freq[nums]--;
            }
        for (int i = 0; i < 1001; ++i)
            while (freq[i]) {
                result.push_back(i);
                freq[i]--;
            }
        return result;
    }
};

int main() {

    cout << "数组的相对排序" << endl;

    return 0;
}

