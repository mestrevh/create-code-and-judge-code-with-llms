/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r1, d1, r2, d2, r3, d3;
    cin >> r1 >> d1 >> r2 >> d2 >> r3 >> d3;

    int x = 0;
    while (true) {
        if (x % d1 == r1 && x % d2 == r2 && x % d3 == r3) {
            cout << x << endl;
            break;
        }
        x++;
    }
    
    return 0;
}
