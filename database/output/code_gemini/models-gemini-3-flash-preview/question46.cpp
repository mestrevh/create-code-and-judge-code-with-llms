/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Determina se um ano é bissexto seguindo as regras do Calendário Gregoriano.
 */
inline bool is_leap(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

/**
 * Calcula o número total de dias transcorridos desde o ano 1 até a data fornecida.
 */
long long total_days(int d, int m, int y) {
    // Dias acumulados antes do início do mês m (não bissexto)
    static const int pref[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    
    long long py = y - 1;
    // Anos comuns + ajuste de anos bissextos
    long long days = py * 365 + py / 4 - py / 100 + py / 400;
    
    // Adiciona dias do mês atual e meses passados
    days += pref[m] + d;
    
    // Se for bissexto e já passou de fevereiro, adiciona o dia extra
    if (m > 2 && is_leap(y)) {
        days++;
    }
    
    return days;
}

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, m1, y1, d2, m2, y2;
    char sep;

    // Leitura das datas no formato dd/mm/yyyy
    // O operador >> do cin com int ignora caracteres não numéricos ao encontrar o char sep
    if (cin >> d1 >> sep >> m1 >> sep >> y1 >> d2 >> sep >> m2 >> sep >> y2) {
        long long res1 = total_days(d1, m1, y1);
        long long res2 = total_days(d2, m2, y2);
        
        long long diff = res1 - res2;
        if (diff < 0) diff = -diff;
        
        cout << diff << "\n";
    }

    return 0;
}