/**
 *    author:  Meet
 *    created: 30.01.2026 23:06:11
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

#define ll long long int
const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

class BIT {
    ll n;
    vector<ll> bit;
    public :
    BIT(ll _n) {
        n = _n;
        bit.assign(n+1, 0);
    }

    void add(ll i, ll x) {
        for(; i<=n; i += (i & (-i))) {
            bit[i] += x;
        }
    }

    ll query(ll i) {
        ll ans = 0;
        for(; i>0; i -= (i & (-i))) {
            ans += bit[i];
        }
        return ans;
    }
};

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        arr.assign(n,0);
        for(ll i=0; i<n; ++i) cin >> arr[i];

        if(k == 1) {
            for(ll i=0; i<n; ++i) cout << 0 << " ";
            cout << "\n";
            continue;
        }
        
        map<ll,ll> mpp;
        for(auto& a : arr) mpp[a];

        ll idx = 1;
        for(auto& mp : mpp) mp.second = idx++;

        for(ll i=0; i<n; ++i) arr[i] = mpp[arr[i]];

        --idx;
        ll sz = idx;
        BIT bit(sz);

        ll inv = 0;
        for(ll i=0; i<k; ++i) {
            inv += (bit.query(sz) - bit.query(arr[i]));
            bit.add(arr[i], 1);
        }

        cout << inv << " ";

        for(ll i=k; i<n; ++i) {
            inv -= bit.query(arr[i-k]-1);
            bit.add(arr[i-k], -1);

            inv += (bit.query(sz) - bit.query(arr[i]));
            bit.add(arr[i], 1);

            cout << inv << " ";
        }
        cout << "\n";
    }
    return 0;
}