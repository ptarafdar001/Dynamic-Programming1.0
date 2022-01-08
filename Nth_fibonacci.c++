#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 2;
int DP[N];

/*
// using DP (memoraization)
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (DP[n] != -1)
        return DP[n];

    DP[n] = fib(n - 1) + fib(n - 2);

    return DP[n];
}

int32_t main()
{
    int n;
    cin >> n;

    
    for (int i = 0; i <= n; i++)
        DP[i] = -1;

    cout << fib(n) << endl;
}
*/

// fibonacci using tabulation method
int32_t main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}