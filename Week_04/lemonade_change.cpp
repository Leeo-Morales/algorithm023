#include <iostream>

using namespace std;

//贪心算法
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.size() < 1) return true;
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) five++;
            if (bills[i] == 10) {
                ten++;
                if (five > 0) five--;
                else return false;
            }
            if (bills[i] == 20) {
                if (ten > 0 && five > 0) {
                    five--;
                    ten--;
                } else if (five > 2) {
                    five -= 3;
                } else return false;
            }
        }
        return true;
    }
};

int main() {

    cout << "柠檬水找零" << endl;

    return 0;
}