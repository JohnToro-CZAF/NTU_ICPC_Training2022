#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {
    ll k; cin >> k;
    ll digits_num = 1;
    ll nums = 9;
    ll tot = 0;
    while (tot < k){
        if (tot + digits_num * nums >= k) break;
        tot += digits_num * nums;
        nums *= 10;
        digits_num++;
    }

    ll curr = (k - tot - 1) / digits_num + nums / 9;
    ll pos = (k - tot) % digits_num;
    if (pos > 0) pos = digits_num - pos;
    // cout << pos << " " << curr << " ";
    for (int i = 0; i < pos; i++) curr /= 10; 
    cout << curr % 10 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T=1; 
    cin >> T;
    while (T--) {
        solve();
    }
}