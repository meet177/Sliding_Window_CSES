/**
 *    author:  Meet
 *    created: 26.01.2026 22:17:54
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

        map<ll,ll> freq;
        map<ll, set<ll>> mpp;
        
        for(ll i=0; i<k; ++i) {
            ++freq[arr[i]];
        }

        for(auto& [ele, fr] : freq) mpp[-fr].insert(ele);

        cout << *(mpp.begin()->second).begin() << " ";

        for(ll i=k; i<n; ++i) {
            mpp[-freq[arr[i-k]]].erase(arr[i-k]);
            if(mpp[-freq[arr[i-k]]].empty()) {
                mpp.erase(-freq[arr[i-k]]);
            }
            --freq[arr[i-k]];
            if(freq[arr[i-k]]) {
                mpp[-freq[arr[i-k]]].insert(arr[i-k]);
            }

            if(freq[arr[i]]) {
                mpp[-freq[arr[i]]].erase(arr[i]);
                if(mpp[-freq[arr[i]]].empty()) {
                    mpp.erase(-freq[arr[i]]);
                }
            }
            ++freq[arr[i]];
            mpp[-freq[arr[i]]].insert(arr[i]);

            cout << *(mpp.begin()->second).begin() << " ";
        }

        cout << "\n";
    }
    return 0;
}