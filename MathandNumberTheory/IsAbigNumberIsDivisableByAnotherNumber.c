#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    ll x;

    cin >> s >> x;

    ll mod = 0;
    for (char c : s) {
        mod = (mod * 10 + (c - '0')) % x;

    }

    if (mod == 0) {
        cout << "YES" <<endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
