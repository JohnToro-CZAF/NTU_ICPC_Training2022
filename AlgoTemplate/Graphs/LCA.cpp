vi tin, tout;
vvi adj;
vvi up;
int timer;
int n, l;

void dfs(int s, int p){
    tin[s] = ++timer;
    up[s][0] = p;
    for(int i = 1; i <= l; i++){
        up[s][i] = up[up[s][i-1]][i-1];
    }
    for(int v : adj[s]){
        if(v == p) continue;
        dfs(v, s);
    }
    tout[s] = ++timer;
}

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
    if(is_ancestor(u, v)){
        return u;
    }
    if(is_ancestor(v, u)){
        return v;
    }
    for(int i = l; i >= 0; i--){
        if(!is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

void solve(){
    int q;
    cin >> n;
    l = ceil(log2(n));
    tin.assign(n, 0);
    tout.assign(n, 0);
    up.assign(n, vi(l+1));
    adj = vvi(n, vi());
    forn(i, n - 1){
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, 0);
}