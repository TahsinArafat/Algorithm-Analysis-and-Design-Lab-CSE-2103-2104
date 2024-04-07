#include <iostream>
using namespace std;
#define ll long long
ll fact[16];
ll Factorial(ll n)
{
    if (n <= 1)
        return 1;
    if (fact[n])
        return fact[n];
    return fact[n] = n * Factorial(n - 1);
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        ll n;
        cout << "Enter the number: ";
        cin >> n;
        cout << "Factorial of " << n << " is " << Factorial(n) << endl;
    }
    return 0;
}