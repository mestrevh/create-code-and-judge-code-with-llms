/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long digits = 0;
    long long length = 1;
    long long count = 9;
    long long start = 1;

    while (n >= start) {
        long long end = min(n, start * 10 - 1);
        digits += (end - start + 1) * length;
        start *= 10;
        length++;
    }

    cout << digits << endl;
    return 0;
}
