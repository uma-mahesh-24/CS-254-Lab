#include <iostream>
using namespace std;

using i64 = long long;

int main()
{
    cout<<"Enter the number of items (n) and the capacity of the knapsack (W) respectively: ";
    int n, W;
    cin>>n>>W;

    int v[n + 1], w[n + 1];
    for(int i = 1; i < n + 1; ++i)
    {
        cout<<"Enter the value and weight of item "<<i<<"(respectively): ";
        cin>>v[i]>>w[i];
    }

    i64 dp[n + 1][W + 1];
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    
    for(int j = 0; j <= W; ++j)
        dp[0][j] = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= W; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if(j > w[i] - 1)
                dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }

    cout<<"The maximum possible value that can be attained in this knapsack is "<<dp[n][W]<<"\n"; 
}