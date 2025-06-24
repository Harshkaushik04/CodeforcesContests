#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 505;
int t, n, m, k;
char grid[MAX][MAX], afterBomb[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1, 1, 0, 0}; // Up, Down
int dy[] = {0, 0, -1, 1}; // Left, Right

// Explore connected empty/gold cells and count gold
int explore(int x, int y) {
    visited[x][y] = true;
    int count = (afterBomb[x][y] == 'g') ? 1 : 0;

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            !visited[nx][ny] && afterBomb[nx][ny] != '#') {
            count += explore(nx, ny);
        }
    }
    return count;
}

// Simulate bomb explosion at (x, y) and calculate gold collected
int simulateBomb(int x, int y) {
    memcpy(afterBomb, grid, sizeof(grid));
    int collected = 0;

    // Define bomb-affected square
    int r1 = max(0, x - k);
    int r2 = min(n - 1, x + k);
    int c1 = max(0, y - k);
    int c2 = min(m - 1, y + k);

    // Clear the bomb area
    for (int i = r1; i <= r2; ++i)
        for (int j = c1; j <= c2; ++j)
            afterBomb[i][j] = '.';

    // Collect gold from perimeter of the bomb area
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            if (grid[i][j] == 'g' && (i == r1 || i == r2 || j == c1 || j == c2)) {
                collected++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    // Explore remaining areas for additional gold
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!visited[i][j] && afterBomb[i][j] != '#')
                collected += explore(i, j);

    return collected;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
            cin >> grid[i];

        int maxGold = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == '.')
                    maxGold = max(maxGold, simulateBomb(i, j));

        cout << maxGold << '\n';
    }

    return 0;
}
