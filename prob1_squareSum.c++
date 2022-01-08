// minimum number of squares whose sum equals to given number 'n'
//example : X = 26 = (4)2 + (3)2+ (1)2 -> 3 numbers
//             or  = (5)2 + (1)2  -> 2 numbers

//          minimum no. required =2

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2, MOD = 1e9 + 7;
int dp[N];

/*
// DP approuch TOP down
int MinSquare(int n)
{

    if (n == 1 || n == 2 || n == 3 || n == 0)
        return n;

    if (dp[n] != MOD)
        return dp[n];

    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], 1 + MinSquare(n - i * i));
    }
    return dp[n];
}

int32_t main()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = MOD;
    }
    int n;
    cin >> n;

    cout << MinSquare(n) << endl;
    return 0;
}
*/

int32_t main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, MOD);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 0; i * i <= n; i++)
    {
        for (int j = 0; i * i + j <= n; j++)
        {
            dp[i * i + j] = min(dp[i * i + j], 1 + dp[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}