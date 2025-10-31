/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x, y, c;
    cin >> x >> y >> c;
    
    int destX = 1, destY = 1;
    
    int dx = destX - x; 
    int dy = destY - y; 
    
    if (c == 1 && dx < 0 && dy < 0) {
        cout << "caminhada invalida\n";
    } else if (c == 2 && dx > 0 && dy < 0) {
        cout << "caminhada invalida\n";
    } else if (c == 3 && dx > 0 && dy > 0) {
        cout << "caminhada invalida\n";
    } else if (c == 4 && dx < 0 && dy > 0) {
        cout << "caminhada invalida\n";
    } else if (dy < 0) {
        cout << -dy << " passos em y e " << -dx << " passos em x\n";
    } else {
        cout << dy << " passos em y e " << dx << " passos em x\n";
    }
    
    return 0;
}
