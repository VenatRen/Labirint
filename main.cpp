#include <iostream>
#include <vector>

using namespace std;

const int k = 1;

// Проверка, существует ли в лабиринте путь от начала до конца
bool dfs(vector<vector<int>>& maze, vector<bool>& visited, int start, int end) {
    if (start == end) {
        return true;
    }
    visited[start] = true;
    for (int i = 0; i < k; i++) {
        if (maze[start][i] == 0 && !visited[i]) {
            if (dfs(maze, visited, i, end)) {
                return true;
            }
        }
    }
    return false;
}

// Проверка, возможно ли провести k человек от входа к выходу
bool can_conduct_k_people(vector<vector<int>>& maze) {
    // Проверка входа и выхода
    for (int i = 0; i < k; i++) {
        if (maze[0][i] == 0 && maze[k-1][i] != 0) {
            return false;
        }
        if (maze[k-1][i] == 0 && maze[0][i] != 0) {
            return false;
        }
    }
    // Проверка, посещается ли каждое свободное место не более одного раза
    vector<bool> visited(k, false);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (maze[i][j] == 0 && !visited[i*k+j]) {
                visited[i*k+j] = true;
                if (!dfs(maze, visited, i*k+j, k*k-1)) {
                    return false;
                }
            }
            else if (maze[i][j] != 0 && visited[i*k+j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Пример лабиринта
    vector<vector<int>> maze = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    };
    bool can_conduct = can_conduct_k_people(maze);
    cout << "Это " << (can_conduct ? "" : "не ") << "возможно что бы k людей дошли до выхода." << endl;
     cout << "Работу выполнил: Ставничий Даниил Сергеевич, ФИТУ РПИб" << endl;
    return 0;
}