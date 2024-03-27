#include <iostream>
using namespace std;

int main()
{
    int coins[] = { 1, 3, 4 };
    int target = 6;
    int dp[target + 1];
    for (auto& step : dp)
        step = 1e9;
    dp[0] = 0;
    for (auto& it : coins) {
        for (int i = it; i <= target; i++) {
            dp[i] = min(dp[i], dp[i - it] + 1);
        }
    }
    cout << dp[target] << "\n";
}