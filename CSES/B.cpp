#include <bits/stdc++.h> 

using namespace std;

#define ll long long

const int maxn = 1e6 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    int a[maxn];
    for (int i=0; i<n-1; i++) {
        ll x; cin >> x;
        a[x] = 1;
    }
    for (int i=1; i<=n; i++) {
        if (!a[i]) {
            cout << i;
        }
    }
}