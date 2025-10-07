/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int total, x, y, z;
    cin >> total >> x >> y >> z;

    int a = total * x / 100;
    int b = total * y / 100;
    int c = total * z / 100;
    
    if (a + b + c == total) {
        cout << "Cada homem ficou com " << a << ", " << b << " e " << c << " reais, respectivamente\n";
        
        int rebeka = 0;
        char l1, l2, l3;
        cin >> l1 >> l2 >> l3;
        rebeka += (l1 - 'a' + 1) + (l2 - 'a' + 1) + (l3 - 'a' + 1);
        
        cout << rebeka << endl;

        int id1, id2, id3;
        cin >> id1 >> id2 >> id3;
        if (id1 % 3 == 0 || id2 % 3 == 0 || id3 % 3 == 0) {
            int parcels = (id1 / 3) + (id2 / 3) + (id3 / 3);
            cout << parcels << endl;
            
            int total_money = rebeka + 3; // 3 reais de Rebeka
            if (total_money >= 7) {
                cout << "Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n";
            } else {
                cout << "E parece que Rebeka vai ter que voltar andando...\n";
            }
        } else {
            cout << "E parece que Rebeka vai ter que voltar andando...\n";
        }
    } else {
        cout << "Nao foi dessa vez que Rebeka pode ajudar...\n";
    }

    return 0;
}
