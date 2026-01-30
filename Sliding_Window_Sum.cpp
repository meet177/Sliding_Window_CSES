/**
 *    author:  Meet
 *    created: 14.12.2025 17:15:55
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

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

vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;

        ll x,a,b,c;
        cin >> x >> a >> b >> c;

        ll ans = 0;
    
        ll sum = 0;

        queue<ll> q;
        q.push(x);
        sum += x;
        if(k == 1) {
            ans ^= sum;
            sum -= q.front();
            q.pop();
        }

        for(ll i=2; i<=n; ++i) {
            ll num = (a*q.back() + b) % c;
            sum += num;
            q.push(num);
            if(i >= k) {
                ans ^= sum;
                sum -= q.front();
                q.pop();
            }
        }

        cout << ans << "\n";
    }
    return 0;
}