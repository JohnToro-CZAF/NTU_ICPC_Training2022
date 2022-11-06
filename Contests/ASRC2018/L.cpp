#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
void solve(){
    int m, n, w, h; cin >> m >> n; cin >> w >> h;
    priority_queue<pair<int, int>> pq;
    vector<vector<int>> ans(m+1);
    vector<int> avail(m+1);
    vector<int> d(n+1);
    for (int id=1; id<=m; id++) {
        int temp; cin >> temp;
        pq.push({int(temp / w), id});
    }
    for (int i=1; i<=n; i++) cin >> d[i];

    // while (!pq.empty()) {
    //     auto person = pq.top(); pq.pop();
    //     int shifts = person.first, id = person.second;
    //     cout << "shifts = " << shifts << ", id = " << id << "\n";
    // }
    // return;

    for (int day = 1; day <= n; day++) {
        stack<pair<int, int>> st;
        // cout << "day = "<< day << "\n";
        while (d[day] > 0) {
            if (pq.empty()) {
                cout << "-1\n";
                return;
            }
            auto person = pq.top(); pq.pop();
            int shifts = person.first, id = person.second;
            // cout << "shifts = " << shifts << ", id = " << id << "\n";
            if (avail[id] <= day) {
                ans[id].push_back(day);
                avail[id] = day + w + h;
                for (int i=0; i<w; i++) d[day+i]--;
                shifts--;
            }
            if (shifts > 0) st.push({shifts, id});
        }
        while (!st.empty()) {
            pq.push(st.top());
            st.pop();
        }
    }

    cout << "1\n";
    for (int i=1; i<=m; i++) {
        for (auto x : ans[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c=1;
    // cin >> c;
    while(c--){
        solve();
    }
}

