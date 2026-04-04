/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string product, pool;
    while (cin >> product >> pool) {
        if (pool.find(product) != string::npos) {
            cout << "I'm on the empire business." << "\n";
        } else {
            cout << "HE CAN'T KEEP GETTING AWAY WITH IT!" << "\n";
        }
    }

    return 0;
}