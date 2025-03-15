//
// Created by m'j'x on 2025/3/10.
//
#include <iostream>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    int weeks = n / 7;  // 完整的周数
    int days = n % 7;   // 剩余的天数

    int work_days = weeks * 5;  // 完整周数的工作日天数

    int current_day = x;
    for (int i = 0; i < days; ++i) {
        if (current_day <= 5) {  // 如果是周一到周五，是工作日
            work_days++;
        }
        current_day = (current_day % 7) + 1;  // 计算下一天是周几
    }

    int total_distance = work_days * 250;
    cout << total_distance << endl;

    return 0;
}