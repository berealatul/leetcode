#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = isBulky(length, width, height);
        bool heavy = isHeavy(mass);
        if (bulky && heavy) return "Both";
        if (!bulky && !heavy) return "Neither";
        if (bulky && !heavy) return "Bulky";
        return "Heavy";
    }
private:
    bool isBulky(const int& length, const int& width, const int& height) {
        return (length >= pow(10, 4) || width >= pow(10, 4) || height >= pow(10, 4) ||
                volume(length, width, height) >= pow(10, 9));
    }

    bool isHeavy(const int& mass) {
        return mass >= 100;
    }

    long volume(const int& length, const int& width, const int& height) {
        return (static_cast<long>(length) * width * height);
    }
};