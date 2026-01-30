/**
 *    author:  Meet
 *    created: 30.01.2026 16:33:06
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
            for(ll i=0; i<n; ++i) cout << arr[i] << " ";
            cout << "\n";
            continue;
        }

        multiset<ll> left, right;

        auto balance = [&] () -> void {
            if(left.size() > right.size() + 1) {
                right.insert(*left.rbegin());
                left.erase((--left.end()));
            }

            if(right.size() > left.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        };

        auto add = [&] (ll num) -> void {
            if(left.empty() || num <= *left.rbegin()) {
                left.insert(num);
            }else {
                right.insert(num);
            }

            balance();
        };

        auto remove = [&] (ll num) -> void {
            if(left.find(num) != left.end()) {
                left.erase(left.find(num));
            }else {
                right.erase(right.find(num));
            }

            balance();
        };

        for(ll i=0; i<k; ++i) {
            add(arr[i]);
        }

        cout << *left.rbegin() << " ";

        for(ll i=k; i<n; ++i) {
            remove(arr[i-k]);
            add(arr[i]);
            cout << *left.rbegin() << " ";
        }

        cout << "\n";
    }
    return 0;
}