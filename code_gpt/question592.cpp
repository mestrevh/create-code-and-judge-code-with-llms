/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    long long A, B;
    string s;
    cin >> A >> B >> s;
    
    long long potions = A;
    for (char c : s) {
        potions = (potions * potions) % B;
        if (c == '1') {
            potions = (potions + A) % B;
        }
    }
    
    cout << potions << endl;
    return 0;
}
