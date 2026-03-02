#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> mat(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        mat[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b], c);
        mat[b][a] = min(mat[b][a], c); // remove if directed
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[i][k] < INF && mat[k][j] < INF) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (mat[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << mat[a][b] << '\n';
    }

    return 0;
}