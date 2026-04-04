/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
 * Grande Mestre em Programação Competitiva
 * Solução: Arithmetic Debt
 * 
 * Estratégia:
 * 1. Calcular o dia atual de pagamento baseado no atraso D e no dia da semana inicial W.
 * 2. Se o dia atual cair no fim de semana, o pagamento é adiado para a próxima segunda-feira.
 * 3. Calcular a dívida acumulada até o dia atual (multa aritmética de base B).
 * 4. Se Sofia tiver saldo (R) suficiente, ela paga agora.
 * 5. Caso contrário, ela espera até a sexta-feira da próxima semana para usar seu salário S.
 * 6. Calcular a dívida projetada para essa nova data e verificar se o saldo R + S é suficiente.
 * 7. Exibir o resultado formatado conforme as especificações e casos de teste.
 */

long long countWeekdays(long long n) {
    if (n <= 0) return 0;
    long long weeks = n / 7;
    long long rem = n % 7;
    long long result = weeks * 5;
    if (rem >= 1) {
        result += min(rem, 5LL);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double R, V, B, S;
    long long W, D;

    if (!(cin >> R >> W >> D >> V >> B >> S)) return 0;

    // T1 é o dia em que ela percebe o atraso e decide se paga agora.
    // Mon=1, Tue=2, Wed=3, Thu=4, Fri=5, Sat=6, Sun=7
    long long T1 = W + D;
    
    // Ajuste: pagamentos só em dias de semana.
    if ((T1 - 1) % 7 + 1 == 6) { // Sabado
        T1 += 2;
    } else if ((T1 - 1) % 7 + 1 == 7) { // Domingo
        T1 += 1;
    }

    // k1 = número de dias úteis de atraso.
    long long k1 = countWeekdays(T1) - countWeekdays(W);
    // Multa aritmética: B + 2B + ... + k1*B = B * k1*(k1+1)/2
    double penalty1 = B * (k1 * (k1 + 1.0) / 2.0);
    double debt1 = V + penalty1;

    cout << fixed << setprecision(2);

    if (R >= debt1) {
        // Consegue pagar agora. No final ela ainda terá o salário S.
        double leftover = R - debt1 + S;
        cout << "Nao precisa esperar e nem pedir emprestimo pague agora e ainda vai sobrar R$ " << leftover << " quando receber o salario" << endl;
    } else {
        // Não consegue pagar agora, precisa esperar a sexta-feira da próxima semana.
        // weekIdx do dia T1: 0-indexed.
        long long currentWeekIdx = (T1 - 1) / 7;
        // Sexta-feira da semana seguinte à semana do dia T1.
        long long T2 = (currentWeekIdx + 1) * 7 + 5;
        
        long long k2 = countWeekdays(T2) - countWeekdays(W);
        double penalty2 = B * (k2 * (k2 + 1.0) / 2.0);
        double debt2 = V + penalty2;
        
        if (R + S >= debt2) {
            double leftover = (R + S) - debt2;
            cout << "Nao da pra pagar agora mas se esperar o dinheiro chegar ao inves de adquirir uma nova divida, vai sobrar R$ " << leftover << " no final de tudo" << endl;
        } else {
            double loan = debt2 - (R + S);
            cout << "Nao da pra pagar nem quando o salario chegar, vai ter que pedir um emprestimo de R$ " << loan << endl;
        }
    }

    return 0;
}