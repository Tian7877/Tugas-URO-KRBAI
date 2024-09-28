#include <iostream>
using namespace std;


int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Masukkan orde Fibonacci: ";
    cin >> n;
    cout << "Bilangan Fibonacci ke-" << n << " adalah: " << fibonacci(n - 1) << endl;
    return 0;
}
