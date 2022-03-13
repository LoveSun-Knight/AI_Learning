//
// Created by LoveSunny on 12/3/2022.
//

#ifndef AI_LEARNING_VECTOR_H
#define AI_LEARNING_VECTOR_H

#include "iostream"
#include "vector"

using namespace std;

void Show(vector<int> v);


void Learn_Vector() {
    vector<int> v(5, 1);
    Show(v);
    getchar();

    v.push_back(10);
    Show(v);
    getchar();

    v.insert(v.begin(), 8);
    Show(v);
}


void Show(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) cout << "Element " << i << " is " << v[i] << endl;
    cout << "Size = " << v.size() << endl;
    cout << endl;
}

#endif //AI_LEARNING_VECTOR_H
