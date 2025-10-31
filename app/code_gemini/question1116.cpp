/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool is_valid_date(int d, int m, int a) {
    if (a < 1900 || a > 2100) {
        return false;
    }
    if (m < 1 || m > 12) {
        return false;
    }
    if (d < 1) {
        return false;
    }

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap(a)) {
        days_in_month[2] = 29;
    }

    if (d > days_in_month[m]) {
        return false;
    }

    return true;
}

string number_to_string_1_to_99(int n) {
    if (n <= 0 || n >= 100) return "";

    vector<string> unidades = {"", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    vector<string> teens = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    vector<string> dezenas = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};

    if (n < 10) {
        return unidades[n];
    }
    if (n < 20) {
        return teens[n - 10];
    }
    if (n % 10 == 0) {
        return dezenas[n / 10];
    }
    return dezenas[n / 10] + " e " + unidades[n % 10];
}

string day_to_string(int d) {
     if (d >= 1 && d <= 20) {
        return number_to_string_1_to_99(d);
     }
     if (d > 20 && d <= 31) {
        if (d == 30) return "trinta";
        return "vinte e " + number_to_string_1_to_99(d % 20) ;
     }
     // special cases for 21-31
      switch(d){
        case 21: return "vinte e um";
        case 22: return "vinte e dois";
        case 23: return "vinte e tres";
        case 24: return "vinte e quatro";
        case 25: return "vinte e cinco";
        case 26: return "vinte e seis";
        case 27: return "vinte e sete";
        case 28: return "vinte e oito";
        case 29: return "vinte e nove";
        case 31: return "trinta e um";
     }
     return "";
}


string month_to_string(int m) {
    vector<string> months = {"", "janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    return months[m];
}

string year_to_string(int a) {
    if (a >= 1900 && a < 2000) {
        if (a == 1900) {
            return "mil e novecentos";
        }
        return "mil e novecentos e " + number_to_string_1_to_99(a % 100);
    }
    if (a >= 2000 && a <= 2100) {
        if (a == 2000) {
            return "dois mil";
        }
        if (a == 2100) {
            return "dois mil e cem";
        }
        return "dois mil e " + number_to_string_1_to_99(a % 100);
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, m, a;
    cin >> d >> m >> a;

    if (!is_valid_date(d, m, a)) {
        cout << "data invalida" << endl;
        return 0;
    }
    
    // A better day to string implementation for edge cases
    vector<string> day_names = {
        "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez",
        "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove", "vinte",
        "vinte e um", "vinte e dois", "vinte e tres", "vinte e quatro", "vinte e cinco", "vinte e seis", "vinte e sete", "vinte e oito", "vinte e nove", "trinta",
        "trinta e um"
    };

    cout << day_names[d - 1] << " de " << month_to_string(m) << " de " << year_to_string(a) << endl;

    return 0;
}
