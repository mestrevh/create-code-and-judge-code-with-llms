/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void drawPyramid(int p, int level) {
    if (level > p) return;
    int spaces = p - level;
    cout << string(spaces, '.') << '*';

    if (level > 1) {
        cout << string(2 * (level - 1) - 1, '-') << '*';
    }

    cout << string(spaces, '.') << endl;
    drawPyramid(p, level + 1);
}

int main() {
    int P;
    cin >> P;
    drawPyramid(P, 1);
    return 0;
}
