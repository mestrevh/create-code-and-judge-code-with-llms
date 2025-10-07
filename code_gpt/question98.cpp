/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool canFormTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) != 0;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        if (canFormTriangle(x1, y1, x2, y2, x3, y3)) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }

    return 0;
}
