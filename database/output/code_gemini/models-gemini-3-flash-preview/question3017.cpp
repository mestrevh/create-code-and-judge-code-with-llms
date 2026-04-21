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

    string name;
    int age;
    while (cin >> name >> age) {
        cout << name << ", você já viveu " << (1LL * age * 365) << " dias!\n";
    }

    return 0;
}