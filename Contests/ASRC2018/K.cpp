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
    int n, k;
    cin >> k >> n;
    vector<vector<int>> B(k+1, vi()), R(k+1, vi()), guess(n, vi(k+1)), L(n, vi());

    forn(i, n){
        forn(j, 3){
            int l;
            char c;
            cin >> l >> c;
            L[i].push_back(l);
            if (c == 'B'){
                B[l].push_back(i);
                guess[i][l] = 0;
            }
            else{
                R[l].push_back(i);
                guess[i][l] = 1;
            }
        }
    }

    vi ans(k+1, -1);
    vi vis(k+1, 0);
    vi vis2(k+1, 0);

    for (int i = 1; i <= k; i++){
        if (vis[i]){
            continue;
        }

        set<int> viss;
        stack<pii> st;
        st.push({i, 0});
        bool flag = true;
        while (!st.empty()){
            pii curr = st.top(); st.pop();
            int l = curr.first, c = curr.second;
            // cout << "node " << l << " " << c << "\n";
            //check if column l is already visited and clash
            if (vis[l] || vis2[l]){
                if (ans[l] != c){
                    flag = false;
                    break;
                }
                continue;
            }

            //set color of column l to c
            ans[l] = c;
            vis2[l] = 1;
            viss.insert(l);

            if (c == 0){
                for (int x : R[l]){
                    for (int l2 : L[x]){
                        if (vis[l2]) continue;
                        if (l2 == l) continue;
                        // cout << l2 << " ";
                        st.push({l2, guess[x][l2]});
                    }
                }
            }
            else{
                for (int x : B[l]){
                    for (int l2 : L[x]){
                        if (vis[l2]) continue;
                        if (l2 == l) continue;
                        // cout << l2 << " ";
                        st.push({l2, guess[x][l2]});
                    }
                }
            }
            // cout << "\n";
        }

        if (!flag){
            for (int l: viss){
                ans[l] = -1;
                vis2[l] = 0;
            }
        }

        else{
            for (int l: viss){
                vis[l] = 1;
                vis2[l] = 0;
            }
            continue;
        }

        viss.clear();
        while (!st.empty()) st.pop();
        st.push({i, 1});
        flag = true;
        while (!st.empty()){
            pii curr = st.top(); st.pop();
            int l = curr.first, c = curr.second;
            // cout << "node " << l << " " << c << "\n";
            //check if column l is already visited and clash
            if (vis[l] || vis2[l]){
                if (ans[l] != c){
                    flag = false;
                    break;
                }
                continue;
            }

            //set color of column l to c
            ans[l] = c;
            vis2[l] = 1;
            viss.insert(l);
            if (c == 0){
                for (int x: R[l]){
                    for (int l2: L[x]){
                        if (vis[l2]) continue;
                        if (l2 == l) continue;
                        // cout << l2 << " ";
                        st.push({l2, guess[x][l2]});
                    }
                }
            }
            else{
                for (int x: B[l]){
                    for (int l2: L[x]){
                        if (vis[l2]) continue;
                        if (l2 == l) continue;
                        // cout << l2 << " ";
                        st.push({l2, guess[x][l2]});
                    }
                }
            }
        }

        if (!flag){
            cout << -1;
            return;
        }
        else{
            for (int l: viss){
                vis[l] = 1;
                vis2[l] = 0;
            }
        }
    }

    for (int i = 1; i <= k; i++){
        if (ans[i]) cout << "R";
        else cout << "B";
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

