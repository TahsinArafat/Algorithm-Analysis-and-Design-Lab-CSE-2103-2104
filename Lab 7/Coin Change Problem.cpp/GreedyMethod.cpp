#include <iostream>
using namespace std;

int main()
{
    int coins[] = { 1, 5, 10, 25 }; // Must Be Sorted in Ascending Order, Or Sort It Later
    int target = 63, steps = 0;
    for (int i = sizeof(coins) / sizeof(coins[0]) - 1; i >= 0; i--) {
        steps += target / coins[i];
        target %= coins[i];
    }
    cout << steps << "\n";
}