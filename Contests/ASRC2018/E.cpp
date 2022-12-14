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

const int maxn = 3e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 20;
const char min_char = 'a';

vvi st1(LOG+1, vi(maxn)), st2(LOG+1, vi(maxn));
vi lg(maxn);

int max_query(int a, int b){
    int best = lg[b-a+1];
    return max(st2[best][a], st2[best][b-(1 << best)+1]);
}

int min_query(int a, int b){
    int best = lg[b-a+1];
    return min(st1[best][a], st1[best][b-(1 << best)+1]);
}

int f(int a, int b){
    if (a > b) return 0;
    return max_query(a, b) - min_query(a, b);
}

void solve(){
    int n;
    cin >> n;

    lg[1] = 0;
    for (int i = 2; i <= n; i++){
        lg[i] = lg[i/2] + 1;
    }

    vi V(n+1);
    vector<pii> inp;
    for (int i = 1; i <= n ; i++){
        int v, l;
        cin >> v >> l;
        inp.push_back({v, l});
    }
    sort(all(inp));

    for (int j = 1; j <= n; j++) st1[0][j] = inp[j-1].second;
    int rg = 1;
    for (int i = 1; i <= LOG; i++){
        for (int j = 1; j + rg <= n; j++) st1[i][j] = min(st1[i-1][j], st1[i-1][j+rg]);
        rg *= 2;
    }

    for (int j = 1; j <= n; j++) st2[0][j] = inp[j-1].second;
    rg = 1;
    for (int i = 1; i <= LOG; i++){
        for (int j = 1; j + rg <= n; j++) st2[i][j] = max(st2[i-1][j], st2[i-1][j+rg]);
        rg *= 2;
    }

    int ans = f(1, n);
    if (n <= 2){
        ans = 0;
        cout << ans;
        return;
    }


    for (int i = 0; i <= n; i++){
        int er1 = 0;
        if (i > 0) er1 = max_query(1, i);
        // cout << i << " " << er1 << "\n";

        if (i == n){
            ans = min(ans, er1);        
            break;
        }

        int l = i+1, r = n, m = n;
        while (l < r){
            int mid = (l + r) / 2;
            // cout << "l r " << l << " " << r << " " << mid << "\n";
            if (mid == n){
                m = mid;
                int cost = max(2 * er1, f(i+1, mid));
                ans = min(ans, cost);
                continue;
            }
            int qr1 = max(f(i+1, mid), f(mid+1, n));
            if (qr1 <= max(f(i+1, mid+1), f(mid+2, n))){
                m = mid;
                int cost = max(2 * er1, qr1);
                ans = min(ans, cost);
                r = mid-1;
            }
            else l = mid+1;
            // cout << m << " ";
        }
        // cout << "\n";
    }


    double tmp = (double) ans/2;
    cout << fixed;
    cout << setprecision(1) << tmp << endl;
    // cout << (double) ans/2;
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

