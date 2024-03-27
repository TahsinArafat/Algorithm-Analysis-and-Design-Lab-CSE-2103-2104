#include <iostream>
using namespace std;

int fibo(int n) {
    if (n <= 1)
        return n;
    // return fibo(n - 1) + fibo(n - 2);
    return (n - 1) + 2 * fibo(n - 2); // More Optimized
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << '\n';
}