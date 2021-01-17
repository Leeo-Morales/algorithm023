#include <iostream>
using namespace std;

//解法一 --- 排序解法
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//解法二 --- 哈希解法
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> table(26, 0);
        for (auto& ch : s) table[ch - 'a']++;
        for (auto& ch : t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) return false;
        }
        return true;
    }
};
 
int main() {
    
    cout << "有效的字母异位词" << endl;

    return 0;
}