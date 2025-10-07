/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int printed_pages;
    double percentage;

    cin >> printed_pages >> percentage;

    int total_pages = (printed_pages * 100) / percentage;
    int remaining_pages = total_pages - printed_pages;

    cout << "O documento possui " << total_pages << " paginas" << endl;
    cout << "Já foram impressas " << printed_pages << " paginas" << endl;
    cout << "Faltam " << remaining_pages << " paginas" << endl;

    return 0;
}
