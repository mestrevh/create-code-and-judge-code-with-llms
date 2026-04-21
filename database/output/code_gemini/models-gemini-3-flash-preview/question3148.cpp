/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double P, N;
    double M, K;

    while (cin >> P >> N >> M >> K) {
        // Probability Zilde gets infected (pz):
        // He makes P independent contacts, each having a probability M*K of infecting him.
        // Probability Zilde is not infected by one contact: 1 - (M * K)
        // Probability Zilde is not infected by all P contacts: (1 - M * K)^P
        // Probability Zilde is infected: 1 - (1 - M * K)^P
        double pz = 1.0 - pow(1.0 - M * K, P);

        // Probability at least one family member gets infected (pf):
        // There are N family members. For each member, the probability they catch it
        // from Zilde is (pz * K).
        // The problem logic (matching test cases) treats these as N independent events.
        // Probability one family member is not infected: 1 - (pz * K)
        // Probability all N family members are not infected: (1 - pz * K)^N
        // Probability at least one family member is infected: 1 - (1 - pz * K)^N
        double pf = 1.0 - pow(1.0 - pz * K, N);

        cout << fixed << setprecision(4) << pf << endl;
    }

    return 0;
}