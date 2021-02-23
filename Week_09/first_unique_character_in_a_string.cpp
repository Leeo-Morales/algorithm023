#include <iostream>
using namespace std;

//解法一 --- 哈希表法
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.length() == 0) return -1;
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && s[i] == s[i - 1]) continue;
            if (count[s[i]] == 1) return i;
        }
        return -1;
    }
};

//解法二 --- 桶记法（统计法）
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.length() == 0) return -1;
        int table[26] = {0};
        for (auto c : s) table[c - 'a']++;
        for (int i = 0; i < s.length(); ++i) {
            if (table[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

int main() {

    cout << "字符串中的第一个唯一字符" << endl;

    return 0;
}
