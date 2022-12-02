#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    ll ans = 1;
    forn(i, n){
        (ans *= 2) %= mod;
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