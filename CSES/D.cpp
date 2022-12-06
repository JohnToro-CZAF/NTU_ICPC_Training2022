#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll a[n];
    for (int i=0; i<n; i++) cin >> a[i];

    ll ans = 0;
    for (int i=1; i<n; i++) {
        if (a[i] < a[i-1]) {
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    
    cout << ans;
}