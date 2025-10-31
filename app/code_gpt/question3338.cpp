/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double binomial_prob(int n, int k, double p) {
    double combination = 1.0;
    for (int i = 0; i < k; ++i) {
        combination *= (n - i) / static_cast<double>(i + 1);
    }
    return combination * pow(p, k) * pow(1 - p, n - k);
}

double overload_probability(int n, double p, int B, int D) {
    double prob = 0.0;
    for (int k = n; k >= (D / B) + 1; --k) {
        prob += binomial_prob(n, k, p);
    }
    return prob;
}

int main() {
    int n, B;
    cin >> n >> B;
    int best_id = -1;
    double min_prob = 1.0;

    while (true) {
        int id;
        double p, D;
        cin >> id >> p >> D;
        if (id == -1 && p == 0 && D == 0) break;

        double prob = overload_probability(n, p, B, D);
        if (prob < min_prob) {
            min_prob = prob;
            best_id = id;
        }
    }

    cout << fixed << setprecision(5);
    cout << "O roteador escolhido foi o " << best_id << ", com probabilidade de " << min_prob << endl;
    return 0;
}
