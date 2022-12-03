#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < n; i++)

struct SegTree{
  int sz;
  vi seg;
  vi lazy;
  
  SegTree(int s){
    sz = s;
    seg.resize(4 * s + 1);
    for (int i = 1; i < seg.size(); i++) seg[i] = 0;
  }

  void update(int pos, int val){
    update(1, 1, sz, pos, val);
  }

  void update(int node, int st, int en, int pos, int val){
    if ((st > pos) || (en < pos)) return;
    if ((st == pos) && (en == pos)){
      seg[node] = val;
      // cout << "found " << pos << "\n";
      return;
    }
    int mid = (st + en) / 2;
    update(2*node, st, mid, pos, val);
    update(2*node+1, mid+1, en, pos, val);
    seg[node] = seg[2*node] + seg[2*node+1];
  }

  int query(int l, int r){
    return query(1, 1, sz, l, r);
  }

  int query(int node, int st, int en, int l, int r){
    // cout << node << " " << st << " " << en << " " << l << " " << r << " " << seg[node] << "\n";
    if ((st > r) || (en < l)) return 0;
    if ((l <= st) && (en <= r)) return seg[node];
    int mid = (st + en) / 2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, en, l, r);
    return (q1+q2);
  }

  int find(int val){
    return find(1, 1, sz, val);
  }

  int find(int node, int st, int en, int val){
    if (st == en) return 1;
    int mid = (st + en) / 2;
    if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
    else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
  }
};

void solve(){
    int n; cin >> n;
    // int k; cin >> k;
    int k = 1;
    SegTree alive(2 * n);
    for (int i = 1; i <= 2 * n; i++) alive.update(i, 1);

    int killed = 0;
    forn(i, n){
      int k2 = ((k+1) % (n-i) == 0) ? (n-i) : (k + 1) % (n - i);
      int offset = alive.query(1, killed);
      killed = alive.find(offset + k2);
      if (killed > n) killed -= n;
      alive.update(killed, 0);
      alive.update(killed + n, 0);
      cout << killed << " ";
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int T = 1;
    // cin >> T;
    while (T--){
        solve();
    }
}