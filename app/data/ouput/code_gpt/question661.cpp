/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int H1, M1, H2, M2;
    while (true) {
        cin >> H1 >> M1 >> H2 >> M2;
        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) break;
        
        int start = H1 * 60 + M1;
        int end = H2 * 60 + M2;
        
        if (end <= start) end += 24 * 60;
        
        cout << (end - start) << endl;
    }
    return 0;
}
