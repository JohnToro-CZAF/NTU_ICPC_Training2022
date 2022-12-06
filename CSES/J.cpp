#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    ll cnt = 1;
    ll ans = 0;
    while (pow(5, cnt) <= n) {ans += n / pow(5, cnt); cnt++;}
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