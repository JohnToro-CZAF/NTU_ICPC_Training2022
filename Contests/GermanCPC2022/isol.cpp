#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> c(n+1, vector<ll> (m+1));
    for (int i = 1; i <= n; i++){
        cin >> c[i][0];
        int limit = min(m, n - i + 1);
        for (int j = 1; j <= limit; j++){
            cin >> c[i][j];
        }
    }

    vector<ll> dp(n+2);
    dp[n+1] = 0;
    for (int i = n; i >= 1; i--){
        int limit = min(m, n - i + 1);
        dp[i] = c[i][0] - c[i][limit] + dp[i + limit];
        for (int j = 1; j <= limit; j++){
            int k = i + j;
            dp[i] = min(dp[i], c[i][0] - c[i][j] + dp[k]);
        }
    }

    // for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    // cout << "\n";

    cout << dp[1];
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