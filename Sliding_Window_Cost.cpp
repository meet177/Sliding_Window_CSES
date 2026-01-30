/**
 *    author:  Meet
 *    created: 30.01.2026 16:58:58
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
            for(ll i=0; i<n; ++i) cout << 0 << " ";
            cout << "\n";
            continue;
        }
        
        multiset<ll> left, right;
        ll sl = 0, sr = 0;

        auto balance = [&] () -> void {
            if(left.size() > right.size() + 1) {
                ll val = *left.rbegin();
                sl -= val;
                sr += val;
                right.insert(val);
                left.erase(left.find(val));
            }

            if(right.size() > left.size()) {
                ll val = *right.begin();
                sr -= val;
                sl += val;
                left.insert(val);
                right.erase(right.find(val));
            }
        };

        auto add = [&] (ll num) -> void {
            if(left.empty() || num <= *left.rbegin()) {
                sl += num;
                left.insert(num);
            }else {
                sr += num;
                right.insert(num);
            }

            balance();
        };

        auto remove = [&] (ll num) -> void {
            if(left.find(num) != left.end()) {
                sl -= num;
                left.erase(left.find(num));
            }else {
                sr -= num;
                right.erase(right.find(num));
            }

            balance();
        };

        for(ll i=0; i<k; ++i) add(arr[i]);

        ll med = *left.rbegin();
        ll cost = (left.size()*med - sl) + (sr - right.size()*med);
        cout << cost << " ";

        for(ll i=k; i<n; ++i) {
            remove(arr[i-k]);
            add(arr[i]);

            med = *left.rbegin();
            cost = (left.size()*med - sl) + (sr - right.size()*med);
            cout << cost << " ";
        }
        cout << "\n";
    }
    return 0;
}