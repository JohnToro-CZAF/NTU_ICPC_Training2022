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
map<char, int> m;
int nop = 0;
bool check(vector<char> vc){
    int n = vc.size();
    if(n % 2 == 0){
        // error
        return false;
    }
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(vc[i] - 'a' >= 0 && vc[i] - 'a' <= 26){
                // pass
            } else {
                return false;
            }
        } else {
            if(m[vc[i]] == 1){
                // pass
            } else {
                return false;
            }
        }
    }
    return true;
}

void solve(){
    string t, s = "";
    getline(cin, t);
    forn(i, t.length()){
        if(int(t[i]) == 32) continue;
        s = s + t[i];
    }
    int n = s.length();
    if(n == 1 && m[s[0]] == 0){
        cout << "error" << endl;
        return;
    }
    forn(i, n){
        if(m[s[i]]){
            nop++;
        }
    }
    vector<char> st;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        st.push_back(s[i]);
        if(st.size() != 0){
            while(st.back() == ')'){
                st.pop_back();
                char cur = ')';
                vector<char> vc;
                while(st.size() && cur != '('){
                    cur = st.back();
                    vc.push_back(cur);
                    st.pop_back();
                }
                if(cur == '('){
                    cnt++;
                    vc.pop_back(); // bo ( ra khoi vc
                    //
                    // reverse(all(vc));
                    // for(auto ch : vc){
                    //     cout << ch;
                    // }
                    // cout << endl;
                    // 
                    if(!check(vc)){
                        cout << "error" << endl;
                        return;
                    }
                    if(vc.size() != 3){
                        cout << "improper" << endl;
                        return;
                    }
                    else {
                        st.push_back('a');   
                    }
                } else {
                    // if there is not enough paranthesis
                    cout << "error" << endl;
                    return;
                }
            }
        }
    }
    vector<char> v;
    while(st.size()){
        v.push_back(st.back());
        st.pop_back();
    }
    reverse(all(v));
    // for(char ch : v){
    //     cout << ch;
    // }
    if(!check(v)){
        cout << "error" << endl;
    } else {
        // cout << nop << " " << cnt << endl;
        if(nop - 1 == cnt){
            cout << "proper" << endl;
        } else {
            cout << "improper" << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    m['+'] = 1; m['-'] = 1; m['/'] = 1; m['%'] = 1; m['*'] = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}

