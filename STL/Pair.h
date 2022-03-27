//
// Created by LoveSunny on 26/3/2022.
//

#ifndef AI_LEARNING_PAIR_H
#define AI_LEARNING_PAIR_H

#include <iostream>
#include "algorithm"
#include "cstdio"

using namespace std;

void Pair() {
    pair<int, int> pair1, pair2;
    cin >> pair1.first >> pair1.second >> pair2.first >> pair2.second;
    if (pair1 == pair2) cout << "ПаµИ" << endl;
}

#endif //AI_LEARNING_PAIR_H
