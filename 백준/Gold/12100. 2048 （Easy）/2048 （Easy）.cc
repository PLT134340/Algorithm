#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Board {
    int level;
    vector<vector<int>> board;
};

void printBoard(int n, vector<vector<int>> &board);
bool mergeBoard(int n, vector<vector<int>> &board, int mode);
pair<int, int> axisByMode(int mode, int n, int i, int j);
int getBoardMax(int n, vector<vector<int>> &board);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int result = getBoardMax(n, board);
    stack<Board> s;
    s.push(Board{0, board});
    while (!s.empty()) {
        auto [level, board] = s.top();
        s.pop();

        if (level == 5) {
            int tmp = getBoardMax(n, board);
            if (result < tmp)
                result = tmp;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            auto newBoard = board;
            if (mergeBoard(n, newBoard, i))
                s.push(Board{level + 1, newBoard});
        }
    }
    cout << result << '\n';
    return 0;
}

void printBoard(int n, vector<vector<int>> &board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

bool mergeBoard(int n, vector<vector<int>> &board, int mode) {
    bool isChange = false;
    for (int i = 0; i < n; i++) {
        int y;
        int x;
        stack<int> s;
        vector<int> result;
        for (int j = 0; j < n; j++) {
            auto [y, x] = axisByMode(mode, n, i, j);
            if (board[y][x] == 0)
                continue;
            else if (s.empty())
                s.push(board[y][x]);
            else if (s.top() != board[y][x]) {
                result.push_back(s.top());
                s.pop();
                s.push(board[y][x]);
            } else {
                result.push_back(s.top() * 2);
                s.pop();
            }
        }

        if (!s.empty())
            result.push_back(s.top());
        while (result.size() < n)
            result.push_back(0);

        for (int j = 0; j < n; j++) {
            auto [y, x] = axisByMode(mode, n, i, j);
            if (result[j] != board[y][x]) {
                board[y][x] = result[j];
                if (!isChange)
                    isChange = true;
            }
        }
    }
    return isChange;
}

pair<int, int> axisByMode(int mode, int n, int i, int j) {
    int y, x;
    if (mode == 0) { // up
        y = j;
        x = i;
    } else if (mode == 1) { // down
        y = n - j - 1;
        x = i;
    } else if (mode == 2) { // left
        y = i;
        x = j;
    } else { // right
        y = i;
        x = n - j - 1;
    }
    return {y, x};
}

int getBoardMax(int n, vector<vector<int>> &board) {
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (result < board[i][j])
                result = board[i][j];
    return result;
}