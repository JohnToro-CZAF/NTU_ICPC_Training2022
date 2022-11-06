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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;

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
const double EPS = 1e-9;

struct Node{
    int mn;
    Node():mn(INF) {}
    Node(ll _mn):mn(_mn) {}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    res.mn = min(left.mn,right.mn);
    return res;
}

Node seg[4*maxn];

void build(int id, int l, int r, vi& a){
    if(l == r){
        seg[id].mn = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid, a);
    build(id*2+1, mid+1, r, a);
    seg[id] = seg[id*2] + seg[id*2 + 1];
}

void update(int id, int l, int r, int idx, int new_val){
    if(l == r && l == idx){
        seg[id].mn = new_val;
        return;
    }
    if(l > idx || r < idx){
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, idx, new_val);
    update(id*2+1, mid+1, r, idx, new_val);
    seg[id] = seg[id*2] + seg[id*2+1];
}

Node query(int id, int l, int r, int u, int v){
    if(l >= u && r <= v){
        return seg[id];
    }
    if(l > v || r < u){
        return Node(INF);
    }
    int mid = (l+r)/2;
    Node q1 = query(id*2, l, mid, u, v);
    Node q2 = query(id*2+1, mid+1, r, u, v);
    return q1+q2;
}

void solve(){
    int n, q; cin >> n >> q;
    vi a(n+1);
    forn(i, n){
        cin >> a[i+1];
    }
    build(1, 1, n, a);
    forn(i, q){
        int command, x, y;
        cin >> command >> x >> y;
        if(command == 1){
            // set a[x] = y;
            update(1, 1, n, x+1, y);
        } else {
            // get sum from a[x]->a[y]
            Node res = query(1, 1, n, x+1, y);
            cout << res.mn << endl; 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}

