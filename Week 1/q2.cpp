#include <iostream>
using namespace std;

using i64 = long long;
i64 dp[2001][2001]; // Assuming that they are within 2000 limit

int main()
{
    // taking user input
    freopen("input2.txt", "r", stdin);
    int n, MAX_WEIGHT;
    cin>>n>>MAX_WEIGHT;

    int val[n + 1], weight[n + 1], i = 1;
    for(i = 1; i < n + 1; ++i)
    {
        cin>>val[i]>>weight[i];
    }

    for(int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    
    for(int j = 0; j <= MAX_WEIGHT; ++j)
        dp[0][j] = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= MAX_WEIGHT; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if(j > weight[i] - 1)
                dp[i][j] = max(dp[i][j], val[i] + dp[i - 1][j - weight[i]]);
        }
    }

    cout<<"The maximum possible value that can be attained in this knapsack is "<<dp[n][MAX_WEIGHT]<<"\n"; 
}