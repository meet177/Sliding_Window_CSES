/**
 *    author:  Meet
 *    created: 25.01.2026 17:08:53
**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,k;
    cin >> n >> k;

    ll x,a,b,c;
    cin >> x >> a >> b >> c;

    if(k == 1) {
        ll ans = x;
        for(ll i=2; i<=n; ++i) {
            x = (a*x + b) % c;
            ans ^= x;
        }
        cout << ans << "\n";
        return 0;
    }

    ll cor = 0;
    vector<ll> cnt(31, 0);

    //this is running in set bits only as we are getting TLE in 31*n for running in full bits so we have to run only in set bits, we can run from right to left as everytime find the rightmost set bit in the representation of x and remove it for removing it we are doing & with (x-1) it will unset the rightmost set bit of x
    auto add = [&] (ll x) -> void {
        while(x) {
            ll b = __builtin_ctzll(x);
            if(cnt[b] == 0) cor |= (1LL << b);
            ++cnt[b];
            x &= (x - 1);
        }
    };

    auto remove = [&] (ll x) -> void {
        while(x) {
            ll b = __builtin_ctzll(x);
            --cnt[b];
            if(cnt[b] == 0) cor ^= (1LL << b);
            x &= (x - 1);
        }
    };

    vector<ll> window(k);
    ll ptr = 0;
    window[0] = x;
    ++ptr;

    add(x);
 
    for(ll i=2; i<=k; ++i) {
        x = (a*x + b) % c;
        window[ptr++] = x;
        add(x);
    }

    ll ans = cor;

    ptr = 0;
    for(ll i=k+1; i<=n; ++i) {
        remove(window[ptr]);

        x = (a*x + b) % c;
        add(x);
        window[ptr] = x;

        ++ptr;
        if(ptr == k) ptr = 0;
        ans ^= cor;
    }
    
    cout << ans << "\n";
    return 0;
}