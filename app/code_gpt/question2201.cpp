/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int L, C;
    cin >> L >> C;

    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < L; ++i) {
        for(int j = 0; j < C; ++j) {
            // Cheio (tipo 1): se todos os vértices do losango estiverem dentro do chão
            if(i > 0 && i < L-1 && j > 0 && j < C-1) cnt1++;
            // Meia (tipo 2): se estiver na borda mas não nos cantos
            else if((i == 0 || i == L-1 || j == 0 || j == C-1) && !( (i == 0 && j == 0) || (i == 0 && j == C-1) || (i == L-1 && j == 0) || (i == L-1 && j == C-1) )) cnt2++;
        }
    }

    // Ajuste: quantidade total de tipo 2 são os que ficam nas bordas, exceto os cantos (onde ficam as 4 tipo 3)
    cnt2 = 2*(L-2) + 2*(C-2);

    // cnt1 são todas as "cheias" internas
    cnt1 = (L-1)*(C-1);

    cout << cnt1 << endl << cnt2 << endl;
    return 0;
}
