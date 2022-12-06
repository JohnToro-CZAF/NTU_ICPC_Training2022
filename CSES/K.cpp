#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {
    ll a, b; cin >> a >> b;
    if (!((a+b) % 3 == 0) || (a > 2*b) || (2*a < b)) cout << "NO\n";
    else cout <<  "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; 
    cin >> T;
    while (T--) {
        solve();
    }
}