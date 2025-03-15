//
// Created by m'j'x on 2025/3/7.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;
using namespace std;

const int maxn = 22; // 最大砝码数
const int maxm = 2010; // 最大重量和

int n, m; // 砝码总数和需要去掉的砝码数
int weights[maxn]; // 砝码重量数组
int maxCount, currentCount, totalWeight; // 最大可称量重量数，当前子集的可称量重量数，当前子集的总重量
bool isSelected[maxn]; // 标记砝码是否被选中
bool dpState[maxm]; // 动态规划状态数组，记录是否可以组成某个重量

// 动态规划函数，计算当前子集可以称量的所有重量 01背包
void calculateWeights() {
    memset(dpState, 0, sizeof(dpState));
    dpState[0] = true; // 初始状态，可以称量重量0
    currentCount = 0; // 当前子集的可称量重量数初始化为0
    totalWeight = 0; // 当前子集的总重量初始化为0

    for (int i = 0; i < n; i++) {
        if (isSelected[i]) continue; // 如果砝码被选中跳过

        // 逆向更新动态规划状态
        for (int j = totalWeight; j >= 0; j--) {
            if (dpState[j] && !dpState[j + weights[i]]) {
                dpState[j + weights[i]] = true;
                currentCount++;
            }
        }
        totalWeight += weights[i];
    }

    // 更新最大可称量重量数
    maxCount = max(currentCount, maxCount);
}

// 深度优先搜索函数，生成所有可能的子集
void generateSubsets(int index, int removedCount) {
    if (removedCount > m) return; // 如果已经去掉的砝码数超过m，返回

    if (index == n) {
        if (removedCount == m) {
            calculateWeights(); // 计算当前子集的可称量重量数
        }
        return;
    }

    // 不选当前砝码(不抛弃)
    generateSubsets(index + 1, removedCount);

    // 选当前砝码(抛弃)
    isSelected[index] = true;
    generateSubsets(index + 1, removedCount + 1);
    isSelected[index] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    generateSubsets(0, 0); // 从第一个砝码开始，初始去掉的砝码数为0
    cout << maxCount;
    return 0;
}