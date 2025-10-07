/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int somar_lista(vector<int> numeros) {
    return accumulate(numeros.begin(), numeros.end(), 0);
}

int main() {
    vector<int> numeros;
    int num;
    while (cin >> num) {
        numeros.push_back(num);
    }
    int resultado = somar_lista(numeros);
    cout << resultado << endl;
    return 0;
}
