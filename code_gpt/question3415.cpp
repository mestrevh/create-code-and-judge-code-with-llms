/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double R, V, B, S;
    int W, D;

    cin >> R >> W >> D >> V >> B >> S;

    int weekDays = D - (D / 7) * 2;
    double penalty = (weekDays * (weekDays + 1) / 2) * B;
    double totalDebt = V + penalty;
    
    if (R >= totalDebt) {
        cout << fixed << setprecision(2);
        cout << "Nao precisa esperar e nem pedir emprestimo pague agora e ainda vai sobrar R$ " << (R - totalDebt) + S << " quando receber o salario";
    } else {
        if (R + S >= totalDebt) {
            cout << fixed << setprecision(2);
            cout << "Nao da pra pagar agora mas se esperar o dinheiro chegar ao inves de adquirir uma nova divida, vai sobrar R$ " << (R + S - totalDebt) << " no final de tudo";
        } else {
            cout << fixed << setprecision(2);
            cout << "Nao da pra pagar nem quando o salario chegar, vai ter que pedir um emprestimo de R$ " << (totalDebt - R - S);
        }
    }
    return 0;
}
