//#include <iostream>
//#include<sstream>
//#include<vector>
//#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    getline(cin, x);

    stringstream ss(x);

    vector<int> v;

    int num;

    while (getline(ss, x, ',')) {
        num = stoi(x);
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            cout << ' ';
        }
        cout << v[i];
    }
}