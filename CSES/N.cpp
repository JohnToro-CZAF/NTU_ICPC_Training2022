#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve(int a1, int a2, int a3, int n) {
    if (n == 0) return;
    solve(a1, a3, a2, n-1);
    cout << a1 << " " << a3 << "\n";
    solve(a2, a1, a3, n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T=1; 
    // cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << ((1 << n) - 1) << "\n";
        solve(1, 2, 3, n);
    }
}