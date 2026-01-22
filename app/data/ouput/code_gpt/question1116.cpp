/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, string> dias = {
    {1, "um"}, {2, "dois"}, {3, "três"}, {4, "quatro"}, {5, "cinco"}, 
    {6, "seis"}, {7, "sete"}, {8, "oito"}, {9, "nove"}, {10, "dez"}, 
    {11, "onze"}, {12, "doze"}, {13, "treze"}, {14, "quatorze"}, 
    {15, "quinze"}, {16, "dezesseis"}, {17, "dezessete"}, {18, "dezoito"}, 
    {19, "dezenove"}, {20, "vinte"}, {21, "vinte e um"}, {22, "vinte e dois"}, 
    {23, "vinte e três"}, {24, "vinte e quatro"}, {25, "vinte e cinco"},
    {26, "vinte e seis"}, {27, "vinte e sete"}, {28, "vinte e oito"},
    {29, "vinte e nove"}, {30, "trinta"}, {31, "trinta e um"}
};

map<int, string> meses = {
    {1, "janeiro"}, {2, "fevereiro"}, {3, "março"}, {4, "abril"},
    {5, "maio"}, {6, "junho"}, {7, "julho"}, {8, "agosto"},
    {9, "setembro"}, {10, "outubro"}, {11, "novembro"}, {12, "dezembro"}
};

string por_extenso(int ano) {
    if (ano < 2000) return dias[ano / 1000] + " mil " + dias[(ano % 1000) / 100] + " " + dias[(ano % 100) / 10] + " " + dias[(ano % 10)];
    else return "dois mil " + dias[(ano % 100) / 10] + " " + dias[(ano % 10)];
}

bool data_valida(int d, int m, int a) {
    if (a < 1900 || a > 2100) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || (m == 2 && ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0) ? d > 29 : d > 28))) return false;
    if (d > 31 || (m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    return true;
}

int main() {
    int d, m, a;
    cin >> d >> m >> a;
    if (!data_valida(d, m, a)) {
        cout << "data invalida" << endl;
    } else {
        cout << dias[d] << " de " << meses[m] << " de " << por_extenso(a) << endl;
    }
    return 0;
}
