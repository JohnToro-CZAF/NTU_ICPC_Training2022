#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

void solve() {
    string s; cin >> s;

    vector<int> cnt(28, 0);
    forn(i, s.size()){
        cnt[s[i] - 'A']++;
    }

    int even = 0; 
    forn(i, 26) if(cnt[i] & 1) even++;
    if (even > 1){ cout << "NO SOLUTION"; return;}

    string ans;
    char thuwaf;
    bool flag = false;
    forn(i, 26){
        forn(j, cnt[i] / 2) ans.push_back('A'+i);
        if (cnt[i] & 1) {thuwaf = 'A' + i; flag = true;}
    }

    cout << ans;
    if (flag) cout << thuwaf;
    reverse(ans.begin(), ans.end());
    cout << ans;
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