#include <bits/stdc++.h>
using namespace std;

long long int countPS(string str)
{
    // Your code here
    long long int mod = 1e9 + 7;
    int n = str.size();
    vector<vector<long long int>> dp(n + 2, vector<long long int>(n + 2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }
            if (str[i] == str[j])
            {

                long long int x = 1 + dp[i + 1][j] + dp[i][j - 1];
                dp[i][j] = x % mod;
            }
            else
            {
                long long int x = (dp[i + 1][j] + dp[i][j - 1]) % mod;
                long long int y = x - dp[i + 1][j - 1];
                dp[i][j] = y % mod;
            }
        }
    }

    return (dp[0][n - 1] + mod) % mod;
}

int main()
{
    string s;
    cin >> s;
    cout << countPS(s) << endl;
    
}