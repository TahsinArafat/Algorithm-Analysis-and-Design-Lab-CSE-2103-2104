#include <iostream>
using namespace std;
#define ll long long

ll Factorial(ll n)
{
    if (n == 0) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main()
{
    ll n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << Factorial(n) << endl;
    return 0;
}