#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define f(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setbits(x) builtin_popcount(x)

const int N = 1e5 + 2, MOD = 1e9 + 7;

// LIS using Dp -> tabulation
signed main()
{
    int n;
    cin >> n;
    vi a(n);
    f(i, 0, n)
            cin >>
        a[i];
    vi dp(n, 1);
    int ans = 0;
    f(i, 1, n)
    {
        f(j, 0, i)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

/*
// LIS using dp -> memorization
int dp[N];
int lis(vi &a, int n)
{
    if (dp[n] != -1)
        return dp[n];
    dp[n] = 1; //single element is also an list
    f(i, 0, n)
    {
        if (a[n] > a[i])
            dp[n] = max(dp[n], 1 + lis(a, i));
    }
    return dp[n];
}
signed main()
{
    f(i, 0, N)
        dp[i] = -1;
    int n;
    cin >> n;
    vi a(n);
    f(i, 0, n)
    {
        cin >> a[i];
    }
    cout << lis(a, n - 1) << endl;
    return 0;
}
*/