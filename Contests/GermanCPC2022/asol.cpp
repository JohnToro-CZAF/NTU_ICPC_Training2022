#include <bits/stdc++.h> 

using namespace std;

#define ll long long

void solve(){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    ll ans = 0;
    if (a != b){
        for (ll x = -a + 1; x <= a; x++){
            ll y_sq = a * a - x * x;
            ll y = sqrt(y_sq);
            // cout << x << " " << y << " " << y_sq << "\n";
            if (y * y == y_sq){
                if ((y * b) % a == 0 && (x * b) % a == 0) ans++;
            }
        }
        cout << ans << "\n";
    }

    if (a == b){
        for (ll x = a; x > 0; x--){
            ll y_sq = a * a - x * x;
            ll y = sqrt(y_sq);
            if (y * y == y_sq){
                if ((y * b) % a == 0 && (x * b) % a == 0) ans++;
            }
        }
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--){
        solve();
    }
    // cin >> T;

}