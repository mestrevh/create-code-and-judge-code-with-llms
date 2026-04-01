/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, l;
    string days[] = {"DOMINGO", "SEGUNDA", "TERCA", "QUARTA", "QUINTA", "SEXTA", "SABADO"};

    while (cin >> p >> l) {
        int prog_met = 0;
        int line_met = 0;
        int max_l = -1;
        int best_day = 0;

        if (p >= 5) prog_met++;
        if (l >= 100) line_met++;
        max_l = l;
        best_day = 0;

        for (int i = 1; i < 7; ++i) {
            if (!(cin >> p >> l)) break;
            if (p >= 5) prog_met++;
            if (l >= 100) line_met++;
            if (l >= max_l) {
                max_l = l;
                best_day = i;
            }
        }

        cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: " << prog_met << "\n";
        cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: " << line_met << "\n";
        cout << "DIA QUE MAIS PRODUZIU: " << days[best_day] << "\n";
    }

    return 0;
}