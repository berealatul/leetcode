#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cal(string s, char a, char b, char c, int v, int& i, int l) {
        if (i + 1 < l) {
            if (s[i + 1] == a) return v;
            else if (s[i + 1] == b) {
                i++;
                return (4 * v);
            }
            else if (s[i + 1] == c) {
                i++;
                return (9 * v);
            }
            else return v;
        }
        else return v;
    }

    int romanToInt(string s) {
        int num = 0;
        for (int i = 0, n = s.length(); i < n; i++) {
            if (s[i] == 'I') {
                num += cal(s, 'I', 'V', 'X', 1, i, n);
            }
            else if (s[i] == 'V') num += 5;
            else if (s[i] == 'X') {
                num += cal(s, 'X', 'L', 'C', 10, i, n);
            }
            else if (s[i] == 'L') num += 50;
            else if (s[i] == 'C') {
                num += cal(s, 'C', 'D', 'M', 100, i, n);
            }
            else if (s[i] == 'D') num += 500;
            else num += 1000;
        }
        return num;

    }
};

int main() {
    string s;
    Solution atul;
    for (int i = 0; i < 100; i++) {
        cin >> s;
        cout << atul.romanToInt(s) << endl;
    }
}
