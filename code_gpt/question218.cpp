/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, H, L;
    cin >> A >> B >> C >> H >> L;
    
    int portas[2] = {H, L};
    sort(portas, portas + 2);
    
    if ((A <= portas[0] && B <= portas[1]) || 
        (A <= portas[0] && C <= portas[1]) || 
        (B <= portas[0] && A <= portas[1]) || 
        (B <= portas[0] && C <= portas[1]) || 
        (C <= portas[0] && A <= portas[1]) || 
        (C <= portas[0] && B <= portas[1])) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }
    
    return 0;
}
