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
    if (n % 4 == 1 or n % 4 == 2) { cout << "NO\n"; return; } 
    
    cout << "YES\n";
    int half = int(n/2);
    cout << half << "\n";
    for (int i=n; i>=1; i-=4) {
        if (i <= 3) break;
        else cout << i << " " << i-3 << " ";
    }
    if (n & 1) cout << "3"; 

    cout << "\n" << n-half << "\n";
    for (int i=n; i>=1; i-=4) {
        if (i <= 3) break;
        else cout << i-1 << " " << i-2 << " ";
    }
    if (n & 1) cout << "1 2\n";
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