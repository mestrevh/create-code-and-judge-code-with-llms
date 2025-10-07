/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long digitCount(long long n) {
    long long count = 0;
    while (n > 0) {
        count += (n % 10);
        n /= 10;
    }
    return count;
}

long long findNextNumber(long long n, long long s) {
    while (digitCount(n) > s) {
        n++;
    }
    return n;
}

int main() {
    int t;
    cin >> t;
    vector<long long> results;
    
    while (t--) {
        long long n, s;
        cin >> n >> s;
        long long nextNum = findNextNumber(n, s);
        results.push_back(nextNum - n);
    }
    
    for (auto res : results) {
        cout << res << endl;
    }
    
    return 0;
}
