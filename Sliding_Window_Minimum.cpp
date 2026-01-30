/**
 *    author:  Meet
 *    created: 22.01.2026 16:10:39
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,k;
    cin >> n >> k;

    ll x,a,b,c;
    cin >> x >> a >> b >> c;

    if(k == 1) {
        ll ans = 0;
        ll prev = x;
        ans = x;
        for(ll i=2; i<=n; ++i) {
            ll curr = (prev*a + b) % c;
            ans ^= curr;
            prev = curr;
        }
        cout << ans << "\n";
        return 0;
    }

    //increasing queue
    deque<ll> q;

    ll prev = x;
    q.push_back(x);

    for(ll i=2; i<=k; ++i) {
        ll curr = (prev*a + b) % c;
        while(!q.empty() && q.back() > curr) q.pop_back();
        q.push_back(curr);
        prev = curr;
    }

    ll k_prev = x;

    ll ans = q.front();

    for(ll i=k+1; i<=n; ++i) {
        if(q.front() == k_prev) {
            q.pop_front();
        }
        
        ll curr = (prev*a + b) % c;
        while(!q.empty() && q.back() > curr) q.pop_back();
        q.push_back(curr);
        
        prev = curr;
        ll k_curr = (k_prev*a + b) % c;
        k_prev = k_curr;

        ans ^= q.front();
    }

    cout << ans << "\n";
    return 0;
}