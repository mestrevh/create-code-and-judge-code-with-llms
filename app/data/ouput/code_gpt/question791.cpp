/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

long long superDigit(const string& n, int k) {
    long long sum = 0;
    for (char digit : n) {
        sum += digit - '0';
    }
    sum *= k;

    if (sum < 10) return sum;
    
    return superDigit(to_string(sum), 1);
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    cout << superDigit(n, k) << endl;
    return 0;
}
