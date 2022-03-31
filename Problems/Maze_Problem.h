//
// Created by LoveSunny on 16/3/2022.
//

#ifndef AI_LEARNING_MAZE_PROBLEM_H
#define AI_LEARNING_MAZE_PROBLEM_H

#include <queue>
#include "stack"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "cstdio"

using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

typedef struct Location {
    pair<int, int> point;
    pair<int, int> pre;
} Location;

void Find_Path_BFS() {
    pair<int, int> Start, End;
    int m, n;
    cout << "���������ĳ��Ϳ�" << endl;
    cin >> m >> n;
    int map[m][n], map_copy[m][n];
    cout << "���������" << endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            map_copy[i][j] = map[i][j];
        }

    cout << "�����������յ�" << endl;
    cin >> Start.first >> Start.second >> End.first >> End.second;
    queue<Location> Open;
    stack<Location> Closed;
    Location first = {Start, {-1, -1}};
    Open.push(first);

    while (!Open.empty()) {
        Location cur = Open.front();
        Open.pop();
        Closed.push(cur);
        if (cur.point == End) {
            Closed.pop();
            map_copy[cur.point.first][cur.point.second] = 2;
            while (!Closed.empty()) {
                Location pre = Closed.top();
                if (pre.point.first == -1) map[pre.point.first][pre.point.second] = 2;
                if (pre.point == cur.pre) {
                    map_copy[pre.point.first][pre.point.second] = 2;
                    cur = pre;
                }
                Closed.pop();
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << map_copy[i][j] << " ";
                    if (j + 1 == n) cout << endl;
                }
            }
            return;
        }

        for (auto & i : dir) {
            int next_r = cur.point.first + i[0];
            int next_c = cur.point.second + i[1];
            if (map[next_r][next_c] == 0 && next_r < m && next_r >= 0 && next_c >= 0 && next_c < n) {
                pair<int, int> next_pos = {next_r, next_c};
                Location next = {next_pos, cur.point};
                Open.push(next);
                map[next_r][next_c] = 2;
            }
        }
    }

    cout << "die!" << endl;
}

void Find_Path_DFS() {
    int m, n;
    pair<int, int> Start, End;
    cout << "���������ĳ��Ϳ�" << endl;
    cin >> m >> n;
    int map[m][n], visited[m][n];
    memset(visited, 0, sizeof(visited));

    cout << "���������" << endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) cin >> map[i][j];

    cout << "�����������յ�" << endl;
    cin >> Start.first >> Start.second >> End.first >> End.second;

    stack<Location> s;
    Location first;
    first.point = Start;
    s.push(first);

    while (!s.empty()) {
        Location cur = s.top();

        if (cur.point == End) {
            map[cur.point.first][cur.point.second] = 2;
            s.pop();
            while (!s.empty()) {
                Location pre = s.top();
                map[pre.point.first][pre.point.second] = 2;
                s.pop();
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << map[i][j] << " ";
                    if (j + 1 == n) cout << endl;
                }
            }
            return;
        }

        bool flag = false;  // ��־����ǰλ�õ�ǰ��������һ����������ߣ����Ϊtrue������Ϊfalse
        for (auto & i : dir) {
            int next_r = cur.point.first + i[0];
            int next_c = cur.point.second + i[1];
            if (map[next_r][next_c] == 0 && visited[next_r][next_c] == 0 && next_r < m && next_r >= 0 &&
                next_c >= 0 && next_c < n) {
                Location next;
                next.point.first = next_r;
                next.point.second = next_c;
                s.push(next);
                visited[next_r][next_c] = 1;
                flag = true;
                break;  // �ҵ�һ����������߾��˳�ѭ������������������ͬ�ĵ㣬��������������ǲ����˳��ģ����Ǽ������ĸ������ж�һ��
            }
        }
        if (!flag) s.pop();  // ������λ�õ��ĸ����򶼲����ߣ��������ջ��Ҳ���ǻ���
    }
}

#endif //AI_LEARNING_MAZE_PROBLEM_H
