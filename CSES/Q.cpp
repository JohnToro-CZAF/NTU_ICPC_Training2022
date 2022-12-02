#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

int is_possible(int x, int y) {
    return 0 <= x && x < 8 && 0 <= y && y < 8;
}

int is_valid(vector<vector<char> >& board, int y, int x ) {
    if (board[y][x] == '*') return 0;
    
    // check horizon and vertical
    for (int i=0; i<8; i++) {
        if (board[y][i] == 'Q' || board[i][x] == 'Q') return 0;
    }

    // check diag
    for (int i=-8; i<=8; i++) {
        if (is_possible(y+i, x+i) && board[y+i][x+i] == 'Q') return 0;
        if (is_possible(y+i, x-i) && board[y+i][x-i] == 'Q') return 0;
    }

    return 1;
}

void solve() {
    int ans = 0;
    vector<vector<char> > board(8, vector<char>(8, '.'));
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> locs(8, 0);
    for (int i=0; i<8; i++) locs[i] = i;
    
    vector<vector<char> > temp = board;
    do {
        int flag = 0;
        for (int i=0; i<8; i++) {
            if (is_valid(temp, i, locs[i])) {
                temp[i][locs[i]] = 'Q';
            } else {
                flag = 1;
                break;
            }
        }

        if (!flag) ans++;
        for (int j=0; j<8; j++) 
            temp[j][locs[j]] = board[j][locs[j]];
    } while(next_permutation(locs.begin(), locs.end()));

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T=1; 
    // cin >> T;
    while (T--) {
        solve();
    }
}