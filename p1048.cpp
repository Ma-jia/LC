//
// Created by m'j'x on 2025/3/6.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// 一维dp数组实现
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 读取 M 和 N
    int T, M;
    cin >> T >> M;

    vector<int> costs(M);
    vector<int> values(M);
    for (int i = 0; i < M; ++i) {
        cin >> costs[i] >> values[i];
    }


    // 创建一个动态规划数组dp，初始值为0
    vector<int> dp(T + 1, 0);

    // 外层循环遍历每个类型的研究材料
    for (int i = 0; i < M; ++i) {
        // 内层循环从 N 空间逐渐减少到当前研究材料所占空间
        for (int j = T; j >= costs[i]; --j) {
            // 考虑当前研究材料选择和不选择的情况，选择最大值
            dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
        }
    }

    // 输出dp[N]，即在给定 N 行李空间可以携带的研究材料最大价值
    cout << dp[T] << endl;
    return 0;
}