/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, C, M;
    cin >> A >> C >> M;

    int mesasAdultos = A / M;
    int sobrasAdultos = A % M;
    int mesasCriancas = C / M;
    int sobrasCriancas = C % M;

    int totalMesas = mesasAdultos + mesasCriancas;
    int totalCustoAdultos = 3 * mesasAdultos * M;
    int totalCustoCriancas = 2 * mesasCriancas * M;

    if (sobrasAdultos == 0 && sobrasCriancas == 0) {
        cout << mesasAdultos << " mesas com adultos: R$" << totalCustoAdultos << "\n";
        cout << mesasCriancas << " mesas com criancas: R$" << totalCustoCriancas << "\n";
    } else {
        int mesasMistas = 0;
        if (sobrasAdultos + sobrasCriancas == M) {
            mesasMistas = 1;
            totalCustoAdultos += 4 * M;
        } else if (sobrasAdultos > 0 && sobrasCriancas > 0) {
            if (sobrasAdultos % 2 == 0 && sobrasCriancas % 2 == 0) {
                mesasMistas = 2;
                totalCustoAdultos += 4 * M;
                totalCustoCriancas += 2 * M;
            }
        }

        if (sobrasAdultos > 0) {
            if (sobrasAdultos < 4) {
                totalCustoAdultos += 3 * sobrasAdultos;
            } else {
                totalCustoAdultos += 3 * M;
                mesasAdultos++;
            }
        }

        if (sobrasCriancas > 0) {
            if (sobrasCriancas < 4) {
                totalCustoCriancas += 2 * sobrasCriancas;
            } else {
                totalCustoCriancas += 2 * M;
                mesasCriancas++;
            }
        }

        cout << mesasAdultos << " mesas com adultos: R$" << totalCustoAdultos << "\n";
        cout << mesasCriancas << " mesas com criancas: R$" << totalCustoCriancas << "\n";
        cout << mesasMistas << " mesas mistas: R$" << mesasMistas * 2 * M << "\n";
    }

    return 0;
}
