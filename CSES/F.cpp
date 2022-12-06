#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;

void solve() {
    ll y, x; cin >> y >> x;

    if (x == y) {
        cout << x*x - (x-1) << "\n";
    } else if (y < x) {
        if (x & 1) cout << x*x - (y-1) << "\n";
        else cout << (x-1)*(x-1) + y << "\n";
    } else {
        if (!(y & 1)) cout << y*y - (x-1) << "\n";
        else cout << (y-1)*(y-1) + x << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    // int T = 1;
    while (T--) {
        solve();
    }
}