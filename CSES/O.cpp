#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

set<string> ans;

void solve() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    do {
        ans.insert(s);
    } while(next_permutation(s.begin(), s.end()));

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << "\n";
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