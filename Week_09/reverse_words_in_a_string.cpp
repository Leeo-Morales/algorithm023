#include <iostream>
using namespace std;

//解法一 --- 暴力解法
class Solution {
public:
    void reverse(string & str, int start, int end) {
        while (start < end) {
            swap(str[start], str[end]);
            start += 1;
            end -= 1;
        }
    }
    string reverseWords(string s) {
        string temp, result;
        bool wordTag = false; //true == begin; false == end
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ' ' && wordTag == false) continue;
            wordTag = true;
            while (i >= 0 && wordTag == true) {
                temp += s[i--];
                if (i < 0) break;
                if (s[i] == ' ') wordTag = false;
            }
            reverse(temp, 0, temp.length() - 1);
            result += (temp + ' ');
            temp.clear();
        }
        result.pop_back();
        return result;
    }
};

//解法二 --- 数组翻转 + 快慢指针
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int index = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                if (index != 0) s[index++] = ' ';
                int end = start;
                while (end < n && s[end] != ' ') s[index++] = s[end++];
                reverse(s.begin() + index - (end - start), s.begin() + index);
                start = end;
            }
        }
        s.erase(s.begin() + index, s.end());
        return s;
    }
};

int main() {

    cout << "翻转字符串里的单词" << endl;

    return 0;
}