#include <bits/stdc++.h>
using namespace std;

int dp(int index1, int index2, int n, string &s) {
    if (index1 == n or index2 == -1) {
        return 0;
    }

    int ans;
    if (s[index1] == s[index2]) {
        ans = 1 + dp(index1 + 1, index2 - 1, n, s);
    } else {
        ans = max(dp(index1 + 1, index2, n, s), dp(index1, index2 - 1, n, s));
    }

    return ans;
}

int32_t main() {

    string s; cin >> s;
    int n = s.size();

    cout << dp(0, n - 1, n, s);
    return 0;
}