/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;
    vector<long long> powers;
    
    for (long long i = 1; i <= A; i *= 2) {
        if (i <= A) powers.push_back(i);
    }
    
    vector<long long> result;
    for (auto it = powers.rbegin(); it != powers.rend(); ++it) {
        if (A > B && A >= *it) {
            A -= *it;
            result.push_back(*it);
        }
    }

    for (auto val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
