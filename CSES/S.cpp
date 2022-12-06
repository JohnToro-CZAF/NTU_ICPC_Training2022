#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

int ans = 0;
// D, U, L, R
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, -1, 1};

int is_possible(int x, int y) {
    return 0 <= x && x < 7 && 0 <= y && y < 7;
}

void solve(string s, vector<vector<int> >& visited, int x, int y, int idx) {
    // cout << s << "\n";
    if (!is_possible(x, y) or visited[x][y]) return;
    if (x == 7 and y == 0 and idx == 48) {
        ans += 1;
        return;
    }
    visited[x][y] = 1;
    for (int i=idx; i<s.size(); i++) {
        if (s[i] != '?') {
            if (s[i] == 'D') solve(s, visited, x+1, y, i+1);
            else if (s[i] == 'U') solve(s, visited, x-1, y, i+1);
            else if (s[i] == 'L') solve(s, visited, x, y-1, i+1);
            else if (s[i] == 'R') solve(s, visited, x, y+1, i+1);
            continue;
        }
        for (int dir = 0; dir < 4; dir++) {
            if (dir == 0) s[i] = 'D';
            else if (dir == 1) s[i] = 'U';
            else if (dir == 2) s[i] = 'L';
            else if (dir == 3) s[i] = 'R';
            solve(s, visited, x + dir_x[dir], y + dir_y[dir], i+1);
            //     visited[x + dir_x[dir]][y + dir_y[dir]] = 0;
            // }
        }
    }
    visited[x][y] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T=1; 
    // cin >> T;
    while (T--) {
        string s; cin >> s;
        int x = 0, y = 0;
        int tgt_x = 6, tgt_y = 0;
        vector<vector<int> > visited(7, vector<int>(7, 0));
        solve(s, visited, x, y, 0);
        cout << ans << "\n";
    }
}