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
#include <vector>
#include <stack>
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
    int m, n;
    cin >> m >> n;
    vi eval(m);
    vvi d(m, vi(m, 0));
    forn(i, n){
        forn(j, m) cin >> eval[j];
        forn(j, m){
            if (eval[j] == 0) continue;
            forn(k, m){
                if (j == k) continue;
                if (eval[j] < eval[k] || eval[k] == 0) d[j][k]++;
            }
        }
    }

    // if (m == 1){
    //     cout << 1;
    //     return;
    // }

    vvi adj(m, vi());
    forn(i, m){
        forn(j, m){
            if (i == j) continue;
            if (d[i][j] > d[j][i]) adj[i].push_back(j);
            if (d[i][j] < d[j][i]) adj[j].push_back(i);
        }
    }

    forn(i, m){
        forn(j, m){
            if (d[i][j] == d[j][i]){
                d[i][j] = 0;
                d[j][i] = 0;
            }
            else if (d[i][j] > d[j][i]) d[j][i] = 0;
            else d[i][j] = 0;
        }
    } 
    // forn(i, m){
    //     queue<pii> st;
    //     st.push({i, INF});
    //     while (!st.empty()){
    //         pii curr = st.front(); st.pop();
    //         // if (curr.second <= S[i][curr.first]) continue;
    //         for (int j: adj[curr.first]){
    //             int new_cost = min(curr.second, d[curr.first][j]);
    //             S[i][j] = max(S[i][j], new_cost);
    //             st.push({j, new_cost});
    //         }
    //     }
    // }

    // forn(i, m){
    //     forn(j, m) cout << d[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // forn(i, m){
    //     forn(j, m) cout << S[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    forn(k, m){
        forn(i, m){
            forn(j, m){
                d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));
            }
        }
    }

    forn(i, m){
        bool flag = true;
        forn(j, m){
            if (i == j) continue;
            if (d[i][j] < d[j][i]) flag = false;
        }
        if (flag) cout << i+1 << " ";
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

