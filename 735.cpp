//
// Created by m'j'x on 2023/12/14.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> vet;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0) {
                vet.push_back(asteroids[i]);
            } else {
                int star = -asteroids[i];
                if (vet.empty() || vet.back() < 0) {
                    vet.push_back(asteroids[i]);
                } else {
                    while (!vet.empty() && vet.back() > 0 && vet.back() < star) {
                        vet.pop_back();
                    }
                    if (vet.empty() || vet.back() < 0) {
                        vet.push_back(asteroids[i]);
                    } else if (vet.back() == star) {
                        vet.pop_back();
                    }
                }
            }
        }
        return vet;
    }
};