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

const int maxn = 2e5+1;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const int shift = 1e7 + 1;

struct Node{
    int mx;
    Node(int a){mx = a;}
    Node(){mx = 0;}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    res.mx = max(left.mx, right.mx);
    return res;
}

template<typename T>
struct SegTree{
  int sz;
  T seg;
  int lazy;
  
  SegTree(int s, int lz=0){
    sz = s;
    seg.resize(2 * s);
    if (lz) lazy.resize(2 * s);
  }

  void update(int l, int r, int val){
    update(1, 1, sz, l, r, val);
  }

  void update(int node, int st, int en, int l, int r, int val){
    if (lazy[node]){
      // seg[node].update(lazy[node]);
      if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
      lazy[node] = 0;
    }
    if ((st > r) || (en < l)) return;
    if ((st >= l) && (en <= r)){
      // seg[node].update(val);
      if (st != en){lazy[2*node] += val, lazy[2*node+1] += val;}
      return;
    }
    int mid = (st + en) / 2;
    update(2*node, st, mid, l, r, val);
    update(2*node+1, mid+1, en, l, r, val);
    seg[node] = seg[2*node] + seg[2*node+1];
  }

  T query(int l, int r){
    return query(1, 1, sz, l, r);
  }

  T query(int node, int st, int en, int l, int r){
    if (lazy[node]){
      // seg[node].update(lazy[node]);
      if (st < en){lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];}
      lazy[node] = 0;
    }
    if ((st > r) || (en < l)) return T;
    if ((l <= st) && (en <= r)) return seg[node];
    int mid = (st + en) / 2;
    T q1 = query(2*node, st, mid, l, r);
    T q2 = query(2*node+1, mid+1, en, l, r);
    return (q1+q2);
  }

  int find(int val){
    return find(1, 1, sz, val);
  }

  int find(int node, int st, int en, int val){
    if (lazy[node]){
      //seg[node].update(lazy[node])
      if (st < en){
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
        //dump lazy in 2*node and 2*node+1
      }
      lazy[node] = 0;
    }
    if (st == en) return 1;
    int mid = (st + en) / 2;
    if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
    else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
  }
};

void solve(){
    // usage: build(1, 1, n)
    // query(1, 1, n, l, r);
    int n; cin >> n;
    SegTree<int> seg(n);
    forn(i, n){
      int a; cin >> a;
      // seg.update(i+1, a);
    } 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
        // phuocdeptrai();
    }
}

