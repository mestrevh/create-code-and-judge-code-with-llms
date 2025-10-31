/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dominós(n);
    
    for (int i = 0; i < n; i++) {
        cin >> dominós[i];
    }

    int ponta1, ponta2;
    cin >> ponta1 >> ponta2;

    string ação;
    cin >> ação;

    int num1 = stoi(ação.substr(5, 3));
    int num2 = stoi(ação.substr(2, 3));
    int x = num1 / num2;

    bool possível = false;
    for (int i = 0; i < n; i++) {
        if (dominós[i] == x) {
            possível = true;
            break;
        }
    }

    if (possível || (ponta1 == x || ponta2 == x)) {
        cout << "ai maezinha\n";
    } else {
        cout << "cade o douze\n";
    }

    return 0;
}
