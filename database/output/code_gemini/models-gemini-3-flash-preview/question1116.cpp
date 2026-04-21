/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Função para determinar se um ano é bissexto segundo as regras do calendário gregoriano.
bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Converte números de 1 a 99 para sua representação por extenso em português.
string small_to_text(int n) {
    static const string units[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    static const string teens[] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    static const string tens[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    
    if (n < 10) return units[n];
    if (n < 20) return teens[n - 10];
    if (n % 10 == 0) return tens[n / 10];
    return tens[n / 10] + " e " + units[n % 10];
}

// Retorna o nome do mês por extenso.
string month_to_text(int m) {
    static const string months[] = {"", "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    return months[m];
}

// Converte o ano (entre 1900 e 2100) para sua representação por extenso conforme as normas gramaticais.
string year_to_text(int a) {
    if (a == 1900) return "mil e novecentos";
    if (a < 2000) return "mil novecentos e " + small_to_text(a % 100);
    if (a == 2000) return "dois mil";
    if (a < 2100) return "dois mil e " + small_to_text(a % 100);
    if (a == 2100) return "dois mil e cem";
    return "";
}

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, m, a;
    // Tenta ler o dia, mês e ano.
    if (cin >> d >> m >> a) {
        bool valid = true;
        
        // Verifica se o ano está dentro do intervalo permitido [1900, 2100].
        if (a < 1900 || a > 2100) {
            valid = false;
        } 
        // Verifica se o mês é válido.
        else if (m < 1 || m > 12) {
            valid = false;
        } 
        // Verifica se o dia é compatível com o mês e o ano (considerando bissextos).
        else {
            int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (is_leap(a)) days_in_month[2] = 29;
            
            if (d < 1 || d > days_in_month[m]) {
                valid = false;
            }
        }

        // Saída do resultado conforme validade da data.
        if (!valid) {
            cout << "data invalida" << endl;
        } else {
            cout << small_to_text(d) << " de " << month_to_text(m) << " de " << year_to_text(a) << endl;
        }
    }

    return 0;
}