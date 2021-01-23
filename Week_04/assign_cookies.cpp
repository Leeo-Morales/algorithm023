#include <iostream>

using namespace std;

//贪心算法
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() < 1 || s.size() < 1) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, contentedChildNum = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                contentedChildNum++;
                i++;
                j++;
            } else j++;
        }
        return contentedChildNum;
    }
};

int main() {

    cout << "分发饼干" << endl;

    return 0;
}