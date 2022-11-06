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
    Node(){}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    res.mx = max(left.mx, right.mx);
    return res;
}

Node seg[4*maxn];
ll lazy[4*maxn];

void build(int node, int st, int en) {
  if (st == en) {
    seg[node] = 0;
    return;
  }
  int mid = (st + en) / 2;
  build(2 * node, st, mid);
  build(2 * node + 1, mid + 1, en);
  seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void update(int node, int st, int en, int l, int r, int val) {
  if (lazy[node] != 0) {
    seg[node].mx += lazy[node];
    if (st != en) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0; // No longer lazy
  }
  if ((en < l) || (st > r)) {
    return;
  }
  if (st >= l && en <= r) {
    seg[node].mx += val;
    if (st != en) {
      lazy[2 * node] += val; // mark its children lazy
      lazy[2 * node + 1] += val;
    }
    return;
  }
  int mid = (st + en) / 2;
  update(2 * node, st, mid, l, r, val);
  update(2 * node + 1, mid + 1, en, l, r, val);
  seg[node] = (seg[2 * node] + seg[2 * node + 1]);
}

Node query(int node, int st, int en, int l, int r) {
  if (lazy[node] != 0) {
    seg[node].mx += lazy[node];
    if (st != en) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (en < l || st > r) {
    return 0;
  }
  if ((l <= st) && (en <= r)) {
    return seg[node].mx;
  }
  int mid = (st + en) / 2;
  Node q1 = query(2 * node, st, mid, l, r);
  Node q2 = query(2 * node + 1, mid + 1, en, l, r);
  return (q1 + q2);
}

void solve(){
    int n;
    cin >> n;
    vector<pii> v;
    map<int, int> cnt_pref, cnt_suf;
    for(int i = 0; i < n; i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        v.push_back({d+shift, b+shift});
    }
    vector<pii> point;
    sort(all(v));
    for(int i = 0; i < n; i++){
        point.push_back({v[i].first, i});
        point.push_back({v[i].second, i});
    }
    sort(all(point));
    map<pii, int> pos;
    for(int i = 0; i < point.size(); i++){
        pos[point[i]] = i + 1;
    }
    build(1, 1, 2*n);
    for(int i = 0; i < n; i++){
        update(1, 1, 2*n, pos[{v[i].first, i}], pos[{v[i].second,i}], 1);
        if(i == 0){
            cnt_pref[i] = max(query(1, 1, 2*n, 1, 2*n).mx, cnt_pref[i]);
        } else {
            cnt_pref[i] = max(query(1, 1, 2*n, 1, 2*n).mx, cnt_pref[i-1]);       
        }
    }

    build(1, 1, 2*n);
    for(int i = n-1; i >= 0; i--){
        update(1, 1, 2*n, pos[{v[i].first, i}], pos[{v[i].second, i}], 1);
        cnt_suf[i] = max(query(1, 1, 2*n, 1, 2*n).mx, cnt_suf[i+1]);
    }
    int mx = 0 + cnt_suf[0];
    for(int i = 0; i < n; i++){
        // cout << i << " " << mx << endl;
        // cout << cnt_pref[i] << " " << cnt_suf[i+1] << endl;
        mx = max(mx, cnt_pref[i] + cnt_suf[i+1]);
    }
    cout << mx << endl;
}

void phuocdeptrai(){
    int n;
    cin >> n;
    vector<pii> v;
    map<int, int> cnt_pref, cnt_suf;
    for(int i = 0; i < n; i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        v.push_back({d, b});
    }

    vector<pair<int, vi>> point;
    map<int, vector<int>> include;
    sort(all(v));

    for (int i = 0; i < n; i++){
        include[v[i].first] = {};
        include[v[i].second] = {};
    }
    for (int i = 0; i < n; i++){
        include[v[i].first].push_back(i);
        include[v[i].second].push_back(i);
    }

    for(auto p: include){
        point.push_back(p);
    }

    int sz = point.size();

    sort(all(point));
    reverse(all(point));
    point.push_back({0, {0}});
    reverse(all(point));

    map<int, int> pos;
    for(int i = 1; i <= sz; i++){
        int x = point[i].first;
        pos[x] = i;
    }

    build(1, 1, sz);
    for(int i = 0; i < n; i++){
        update(1, 1, sz, pos[v[i].first], pos[v[i].second], 1);
    }

    vi alr(sz+1);
    for (int i = 1; i <= sz; i++){
        alr[i] = query(1, 1, sz, i, i).mx;
    }

    int ans = 0;

    pair<int, vi> prev = {0, {0}};
    for (int i = 1; i <= sz; i++){
        auto curr = point[i];
        for (int ori_seg: curr.second){
            if (curr.first == v[ori_seg].first){
                update(1, 1, sz, i, pos[v[ori_seg].second], -1);
            }
        }
        if (i > 1){
            for (int ori_seg: prev.second){
                if (prev.first == v[ori_seg].second){
                    update(1, 1, sz, pos[v[ori_seg].first], i-1, 1);
                }
            }
        }
        prev = curr;

        int ans2 = query(1, 1, sz, 1, sz).mx;
        ans = max(ans, ans2 + alr[i]);
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        // solve();
        phuocdeptrai();
    }
}

