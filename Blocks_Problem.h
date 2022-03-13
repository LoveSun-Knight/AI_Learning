//
// Created by LoveSunny on 12/3/2022.
//

#ifndef AI_LEARNING_BLOCKS_PROBLEM_H
#define AI_LEARNING_BLOCKS_PROBLEM_H

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int Max = 30;
int n;  // n个木块
vector<int> pile[Max];


// 找到木块a所在的pile和height
void find_block(int a, int &p, int &h) {
    for (p = 0; p < n; ++p)
        for (h = 0; h < pile[p].size(); ++h)
            if (pile[p][h] == a) return;
}


// 把第p堆高度为h的木块上方所有木块移回原位
void reset_above(int p, int h) {
    for (int i = h + 1; i < pile[p].size(); ++i) {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}


// 把第p堆高度为h的木块以及上方所有木块移到第p2堆
void pile_onto(int p, int h, int p2) {
    for (int i = h; i < pile[p].size(); ++i) pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}


void print() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j : pile[i]) printf(" %d", j);
        printf("\n");
    }
}


void Blocks_Problem() {
    int a, b;
    string s1, s2;
    cin >> n;

    // 初始化每个堆一个木块，编号与数组下标相同
    for (int i = 0; i < n; ++i) pile[i].push_back(i);

    print();
    while (cin >> s1 >> a >> s2 >> b) {
        int pa, pb;
        int ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb) continue;
        if (s2 == "onto") reset_above(pb, hb);  // 只要是onto指令，都要把b上面的木块放回原位
        if (s1 == "move") reset_above(pa, ha);  // 只要是move指令，都要把a上的木块放回原位
        pile_onto(pa, ha, pb);
    }
    print();
}

#endif //AI_LEARNING_BLOCKS_PROBLEM_H
