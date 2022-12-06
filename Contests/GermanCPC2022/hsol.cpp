#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

void solve(){
    vector<char> ch;
    ch.push_back('0');
    forn(i, 26) ch.push_back('a' + i);

    vector<vector<int>> q(5);
    q[0] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    q[1] = {1, 2, 3, 4, 5, 6, 7, 8, 17, 18, 19, 20, 21, 22, 23, 24};
    q[2] = {1, 2, 3, 4, 9, 10, 11, 12, 17, 18, 19, 20, 25, 26};
    q[3] = {1, 2, 5, 6, 9, 10, 13, 14, 17, 18, 21, 22, 25, 26};
    q[4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};

    vector<vector<int>> Q(5, vector<int>(27, 0));
    forn(i, 5){
        for (int c: q[i]){
            Q[i][c] = 1;
        }
    }


    vector<vector<int>> is_id(27, vector<int> (1e4 + 4, 1));

    forn(i, 5){
        string s;
        for (int x: q[i]) s.push_back(ch[x]);
        cout << "? " << s << "\n";
        cout.flush();

        int n; cin >> n;
        vector<int> cnt(1e4 + 5, 0);
        forn(j, n){
            int id; cin >> id;
            // cout << id << " ";
            cnt[id] = 1;
        }
        // cout << "\n";
        // cout.flush();

        // for (int j = 1; j <= 10; j++) cout << cnt[j] << " ";
        // cout << "\n";
        // for (int j = 1; j <= 26; j++) if (Q[i][j] == 1) cout << j << " ";
        // cout << "\n";
        // cout.flush();

        for (int j = 1; j <= 1e4; j++){
            if (cnt[j] == 0){
                // cout << 0 << "\n";
                for (int c = 1; c <= 26; c++){
                    if (Q[i][c] == 1){
                        // cout << c << " ";
                        is_id[c][j] = 0;
                    }
                }
            }
            else{
                // cout << 1 << "\n";
                for (int c = 1; c <= 26; c++){
                    if (Q[i][c] == 0){
                        // cout << c << " ";
                        is_id[c][j] = 0;
                    }
                }
            }
            // cout << "\n";
        }
        // cout << "\n";
        // cout.flush();

        // for (int j = 1; j <= 10; j++) cout << is_id[26][j] << " ";
        // cout << "\n";
        // cout.flush();
    }

    cout << "? ";
    for (int i = 0; i < 26; i++){
        cout << (char)('a' + i);
    }
    cout << "\n";
    cout.flush();

    int n; cin >> n;
    forn(i, n){
        int aa; cin >> aa;
    }

    vector<char> ans(1e4+1, '!');
    for (int i = 1; i <= 26; i++){
        for (int j = 1; j <= 1e4; j++){
            if (is_id[i][j]) ans[j] = ch[i];
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++){
        if (ans[i] != '!') cout << ans[i];
    }
    cout.flush();
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--){
        solve();
    }
    // cin >> T;

}