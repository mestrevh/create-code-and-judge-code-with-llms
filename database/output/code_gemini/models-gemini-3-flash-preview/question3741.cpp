/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void ajudearachel(float troco) {
    long long remaining_cents = (long long)round(troco * 100.0);
    
    int notas_val[] = {5000, 2000, 1000, 500, 200};
    int moedas_val[] = {100, 50, 25, 10, 5};
    
    int count_notas = 0;
    for (int v : notas_val) {
        count_notas += remaining_cents / v;
        remaining_cents %= v;
    }
    
    int count_moedas = 0;
    for (int v : moedas_val) {
        count_moedas += remaining_cents / v;
        remaining_cents %= v;
    }
    
    cout << fixed << setprecision(2) << troco << "\n";
    cout << count_notas << " notas e " << count_moedas << " moedas" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    float v_pedido, v_pago;
    if (cin >> v_pedido >> v_pago) {
        ajudearachel(v_pago - v_pedido);
    }
    
    return 0;
}