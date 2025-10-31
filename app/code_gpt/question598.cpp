/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % 100000007;
    }
    return result;
}

long long mod_inverse(long long a, long long p) {
    long long result = 1, exp = p - 2;
    while (exp) {
        if (exp % 2) result = (result * a) % p;
        a = (a * a) % p;
        exp /= 2;
    }
    return result;
}

long long anagrams_count(const string &s) {
    map<char, int> freq;
    for (char c : s) freq[c]++;
    
    long long total_permutations = factorial(s.length());
    for (const auto &pair : freq) {
        total_permutations = (total_permutations * mod_inverse(factorial(pair.second), 100000007)) % 100000007;
    }
    return total_permutations;
}

int main() {
    string s;
    while (cin >> s && s != "0") {
        cout << anagrams_count(s) << endl;
    }
    return 0;
}
