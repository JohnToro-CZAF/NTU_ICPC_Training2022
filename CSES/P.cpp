#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<ll> p(n);
    forn(i, n) cin >> p[i];

    ll tot_all = 0;
    forn(i, n) tot_all += p[i];
    ll ans = tot_all;
    forn(i, (1 << n)){
        ll tot = 0;
        forn(j, n){
            // cout << ((i >> j) & 1);
            if ((i >> j) & 1) tot += p[j];
        }
        // cout << "\n";
        ans = min(ans, llabs(2 * tot - tot_all));
    }
    cout << ans;
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