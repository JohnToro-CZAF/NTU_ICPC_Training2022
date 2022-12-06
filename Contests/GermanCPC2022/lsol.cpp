#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

void solve(){
    int l, w, n;
    cin >> l >> w >> n;
    if ((l * w) % n != 0){
        cout << "IMPOSSIBLE";
        return;
    }

    vector<char> ch;
    forn(i, 26){
        ch.push_back('A' + i);
    }

    vector<vector<char>> ans(l, vector<char>(w));

    for (int i = 1; i <= n; i++){
        if (n % i != 0) continue;
        int j = n / i;
        if (l % i == 0 && w % j == 0){
            int ii = l / i, jj = w / j;
            for (int k = 0; k < i; k++){
                for (int q = 0; q < j; q++){
                    char x = ch[k * j + q];
                    for (int kk = k * ii; kk < (k+1) * ii; kk++){
                        for (int qq = q * jj; qq < (q+1) * jj; qq++){
                            ans[kk][qq] = x;
                        }
                    }
                }
            }
            break;
        }
    }

    forn(i, l){
        forn(j, w){
            cout << ans[i][j];
        }
        cout << "\n";
    }
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