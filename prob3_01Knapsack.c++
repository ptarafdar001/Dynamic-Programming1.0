#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define f(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setbits(x) builtin_popcount(x)

const int N = 1e3 + 2, MOD = 1e9 + 7;

/*
// 0/1 knapsack - using Recursion
int prof[N], wt[N];

int knapSack(int n, int w)
{
    if (w <= 0)
        return 0;
    if (n <= 0)
        return 0;
    if (wt[n - 1] > w)
        return knapSack(n - 1, w);

    return max(knapSack(n - 1, w), knapSack(n - 1, w - wt[n - 1]) + prof[n - 1]);
}

signed main()
{
    int n;
    cin >> n;
    f(i, 0, n)
    {
        cin >> wt[i];
    }
    f(i, 0, n)
    {
        cin >> prof[i];
    }
    int w;
    cin >> w;

    cout << knapSack(n, w) << endl;
}
*/

// 0/1 knapsack - using DP
int prof[N], wt[N];
int dp[N][N];

int knapSack(int n, int w)
{
    if (w <= 0)
        return 0;
    if (n <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] > w)
        dp[n][w] = knapSack(n - 1, w);
    else
        dp[n][w] = max(knapSack(n - 1, w), knapSack(n - 1, w - wt[n - 1]) + prof[n - 1]);
    return dp[n][w];
}

signed main()
{
    //iniatialize dp table
    f(i, 0, N)
    {
        f(j, 0, N)
            dp[i][j] = -1;
    }

    int n;
    cin >> n;
    f(i, 0, n)
    {
        cin >> wt[i];
    }
    f(i, 0, n)
    {
        cin >> prof[i];
    }
    int w;
    cin >> w;

    cout << knapSack(n, w) << endl;
}

/*
    input format
    3          -> no. of items
    15 30 45   -> wait of each item
    60 100 150 -> profit of the items
    50         -> capacity of the bag
    output
    160         -> max profit
*/
