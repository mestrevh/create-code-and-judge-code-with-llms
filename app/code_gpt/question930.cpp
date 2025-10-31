/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cin >> K;
    cin.ignore();
    
    unordered_map<char, int> freq;
    string linha;

    for (int i = 0; i < K; ++i) {
        getline(cin, linha);
        for (char c : linha) {
            freq[c]++;
        }
    }

    char caractereMaisRepetido = 0;
    int maxFreq = 0;

    for (auto& par : freq) {
        if (par.second > maxFreq || (par.second == maxFreq && par.first < caractereMaisRepetido)) {
            maxFreq = par.second;
            caractereMaisRepetido = par.first;
        }
    }

    char X;
    cin >> X;

    cout << caractereMaisRepetido << " " << maxFreq << " " << freq[X] << endl;

    return 0;
}
