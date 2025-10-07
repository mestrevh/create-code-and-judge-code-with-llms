/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int base = n * 2;
    
    for (int i = 1; i <= n; ++i) {
        int x_count = i * 2;
        int spaces = (base - x_count) / 2;
        cout << string(spaces, ' ') << string(x_count, 'X') << endl;
    }
    
    int trunk_height = n / 2;
    for (int i = 0; i < trunk_height; ++i) {
        cout << string((base - 2) / 2, ' ') << "XX" << endl;
    }
    
    return 0;
}
