/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long F;
    if (!(cin >> F)) return 0;

    unordered_map<string, long long> dec = {
        {"Hossomaki", 3},
        {"Futomaki", 5},
        {"Nigirizushi", 7},
        {"Temaki", 10}
    };

    for (int i = 0; i < 3; i++) {
        string s;
        long long q;
        cin >> s >> q;
        F -= dec[s] * q;
    }

    if (F <= 0) {
        cout << "Nossa, o Japao e um otimo lugar para comer, vou dar conta do recado!\n";
    } else if (F <= 10) {
        cout << "Estou satisfeito mas nao sei se darei conta do recado\n";
    } else {
        cout << "Uma feijoada seria bem melhor... Estou me sentindo fraco\n";
    }
    return 0;
}