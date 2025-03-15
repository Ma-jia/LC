//
// Created by m'j'x on 2025/3/4.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int f5 = 0, f10 = 0;
        for (const auto &item: bills) {
            if (item == 5)f5++;
            else if (item == 10) {
                if (f5 == 0)return false;
                f10++;
                f5--;
            } else {
                if (f10 > 0 && f5 > 0) {
                    f10--;
                    f5--;
                } else if (f10 == 0 && f5 >= 3) {
                    f5 = f5 - 3;
                } else {
                    return false;
                }
            }

        }
        return true;
    }
};