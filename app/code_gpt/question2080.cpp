/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<char, int> holes = {
    {'0', 1}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 1},
    {'5', 0}, {'6', 1}, {'7', 0}, {'8', 2}, {'9', 1}
};

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int count_holes(long long n) {
    int count = 0;
    while (n > 0) {
        count += holes[n % 10 + '0'];
        n /= 10;
    }
    return count;
}

int main() {
    long long n;
    cin >> n;
    int hole_count = count_holes(n);
    cout << (is_prime(hole_count) ? 'S' : 'N') << endl;
    return 0;
}
