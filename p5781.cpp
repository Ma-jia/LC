//
// Created by m'j'x on 2025/3/15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min_val;
    cin >> min_val;

    for (int i = 1; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp < min_val) {
            min_val = temp;
        }
    }

    cout << min_val << endl;

    return 0;
}