/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    int max_votes = max({a, b, c});
    int winners_count = 0;
    if (a == max_votes) winners_count++;
    if (b == max_votes) winners_count++;
    if (c == max_votes) winners_count++;

    if (winners_count > 1) {
        cout << "Empate." << endl;
    } else if (a == max_votes) {
        cout << "O vencedor é Introducao a Programacao com um total de " << a << " E O HEXA VEIO." << endl;
    } else if (b == max_votes) {
        cout << "O vencedor é Introducao a Computacao com um total de " << b << " votos." << endl;
    } else if (c == max_votes) {
        cout << "O vencedor é Calculo 6 com um total de " << c << " votos." << endl;
    }

    return 0;
}