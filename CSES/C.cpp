#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int sz = s.size();

    int cnt = 0;
    int ans = 0;
    int i = 0;
    while (i < sz){
        int j = i;
        while (j < sz && s[j] == s[i]){
            j++;
            cnt++;
        }

        ans = max(ans, cnt);

        // cout << j << " " << cnt << "\n";
        cnt = 0;
        i = j;
    }    

    cout << ans;
}