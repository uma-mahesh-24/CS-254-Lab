#include <iostream>
using namespace std;

// there are five nodes in example graph (graph is 1-based)
const int n = 5;
const int INF = 1e8;

// dist[i][j] represents shortest distance to go from i to j 
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 310, 185, 210 },
	{ 0, 120, 0, 250, 250 }, { 0, 155, 205, 0, 30 },
	{ 0, 120, 125, 130, 0 },
};

// memoization for top down recursion
int dp[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	
	if (dp[i][mask] != 0)
		return dp[i][mask];

	int res = INF; // result of this sub-problem

	for (int end = 1; end <= n; end++)
		if ((mask & (1 << end)) && end != i && end != 1)
			res = min(res, fun(end, mask & (~(1 << i))) + dist[end][i]);
        
    
	return dp[i][mask] = res;
}

int main()
{
	int ans = INF;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);

    cout<<"The cost of the most efficient cycle = "<<ans<<"\n";

	return 0;
}

