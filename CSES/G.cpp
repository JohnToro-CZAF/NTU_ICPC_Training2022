#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;

bool valid(int x, int y, int z){
    return (1 <= x && x <= z && 1 <= y && y <= z);
}

void solve() {
    ll n; cin >> n;
    int ans[8] = {0, 6, 28, 96, 252, 550, 1056, 1848};

    for (ll i = 1; i <= n; i++){
        if (i <= 7) {cout << ans[i-1] << "\n"; continue;}
        ll tot = ((i * i) * (i * i - 1)) / 2;
        ll crn = 4;
        ll nr_crn = 8;
        ll eg = 4 * (i - 4);
        ll nr_crn2 = 4;
        ll nr_eg = 4 * (i - 4);
        ll rem = i * i - crn - nr_crn - eg - nr_crn2 - nr_eg;

        ll anss = tot - (crn * 2 + nr_crn * 3 + eg * 4 + nr_crn2 * 4 + nr_eg * 6 + rem * 8) / 2;
        cout << anss << "\n";
    }
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