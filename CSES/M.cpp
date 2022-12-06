#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a; a.push_back(0); a.push_back(1);
    for (int i=2; i<=n; i++) {
        for (int i=a.size()-1; i>=0; i--) {
            a.push_back(a[i]*2 + 1);
            a[i] = a[i] * 2;
        }
    }

    for (auto x : a) {
        for (int i=0; i<n; i++) {
            cout << ((x >> i) & 1);
        }
        cout  << "\n";
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