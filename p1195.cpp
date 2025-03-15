//
// Created by m'j'x on 2025/3/6.
//
#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <stdbool.h>
#include<iostream>
#include<algorithm>  //sort嘛......当然要开万能的algorithm

using namespace std;
struct woyaohongming { //不要在意这个结构体的名字......它只是用来存储图的而已
    int s, e, w;    //s-start，e-end，代表边上的两个节点，w就是权值费用了
} a[200005];
int f[200005];  //并查集用的f数组
bool cmp(woyaohongming a, woyaohongming b) {   //sort排序规则，按费用从低到高排序
    return a.w < b.w;
}

int find(int a) {  //并查集的“找祖宗”函数，注意别忘路径压缩
    if (f[a] == a)
        return a;
    else return f[a] = find(f[a]);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;   //输入n、m、k，没啥好讲的
    for (int i = 1; i <= n; i++)
        f[i] = i;  //并查集数组初始化，每个节点的祖宗一开始是它自己
    for (int i = 1; i <= m; i++)
        cin >> a[i].s >> a[i].e >> a[i].w;  //输入图的信息
    sort(a + 1, a + 1 + m, cmp);   //快活的按权值排个序
    int cnt = 0, sum = 0;  //cnt是已经选中的边数，sum是最终要输出的最小权值
    for (int i = 1; i <= m; i++) {   //m条边，循环m次
        if (find(a[i].s) != find(a[i].e)) { //如果俩节点的祖宗不相等（也就是不是回路），就可以加进去
            f[find(a[i].s)] = find(a[i].e); //把它俩合并成一个祖宗
            sum += a[i].w;    //更新最小费用
            cnt++; //边数+1
        }
        if (cnt >= n - k)  //边数到达（n-k）条边，任务完成，break
            break;
    }
    if (cnt >= n - k)   //如果选了n-k条边，可以搞最小生成树
        cout << sum;  //输出最小权值
    else cout << "No Answer";  //要不然选了m条边还都搞不好，不能构成最小生成树
    return 0;  //终于完事了
}