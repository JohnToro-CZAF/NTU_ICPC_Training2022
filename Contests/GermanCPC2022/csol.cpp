#include <bits/stdc++.h> 

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)

struct SegTree{
  int sz;
  vector<int> seg;
  
  SegTree(int s, int lz=0){
    sz = s;
    seg.resize(4 * s);
    forn(i, seg.size()) seg[i] = 0;
  }

  void update(int pos, int val){
    update(1, 1, sz, pos, val);
  }

  void update(int node, int st, int en, int pos, int val){
    if ((st > pos) || (en < pos)) return;
    if ((st == pos) && (en == pos)){
      seg[node] = val;
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
    if ((st > r) || (en < l)) return 0;
    if ((l <= st) && (en <= r)) return seg[node];
    int mid = (st + en) / 2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, en, l, r);
    return (q1+q2);
  }
};

void solve(){
    int n, q; cin >> n >> q;
    SegTree st(2 * n + 2);
    // for (int i = 1; i <= 2 * n; i++) cout << st.query(i, i) << " ";
    // cout << "\n";
    forn(_, q){
        char c; cin >> c;
        if (c == '-'){
            int a; cin >> a;
            st.update(a, 1);
            st.update(a + n, 1);
        }
        else if (c == '+'){
            int a; cin >> a;
            st.update(a, 0);
            st.update(a + n, 0);
        }
        else{
            int a, b; cin >> a >> b;
            if (a > b){
                int tmp = a;
                a = b;
                b = tmp;
            }
            int qr = st.query(a, b);
            int qr2 = st.query(b, n+a);
            if (qr == 0 || qr2 == 0){
                cout << "possible\n";
            }
            else cout << "impossible\n";
        }

        // for (int i = 1; i <= 2 * n; i++){
        //     cout << st.query(i, i) << " ";
        // }
        // cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--){
        solve();
    }
    // cin >> T;

}