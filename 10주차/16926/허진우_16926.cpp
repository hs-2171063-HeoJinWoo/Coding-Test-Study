/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/16926
*/

/*
 * 풀이
 * 사용 알고리즘 : 구현
 * 입력받은 배열을 [0][0] > [1][1] > [2][2]... 의 순서로 시작하여 배열을 반시계 방향으로 한번씩 돌린다.
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, r;
vector<vector<int>> board;

void input() {
    cin >> n >> m >> r;
    board.resize(n);
    fill(board.begin(), board.end(), vector<int>(m));
    for(auto& row : board) for(auto& x : row) cin >> x;
}

void sol() {
    while(r--) {
        for (int start = 0; start < min(n, m) / 2; start++) {
            int x = start, y = start;
            int prev = board[y][x];
            int next;
            
            // 좌상 -> 좌하
            while(y < n - start - 1) {
                next = board[y + 1][x];
                board[++y][x] = prev;
                prev = next;
            }
            // 좌하 -> 우하
            while(x < m - start - 1) {
                next = board[y][x + 1];
                board[y][++x] = prev;
                prev = next;
            }
            // 우하 -> 우상
            while(y >= start + 1) {
                next = board[y - 1][x];
                board[--y][x] = prev;
                prev = next;
            }
            // 우상 -> 좌상
            while(x >= start + 1) {
                next = board[y][x - 1];
                board[y][--x] = prev;
                prev = next;
            }
        }
    }
    for(auto& row : board) {
        for(auto& x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}