#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                address.replace(i++, 1, "[.]");
            }
        }
        return address;
    }
};