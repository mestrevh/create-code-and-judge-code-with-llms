/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    if (T <= 0) {
        long long X;
        if (cin >> X) cout << "Esse numero deve estar errado..." << endl;
        return 0;
    }

    vector<long long> A(T);
    for (int i = 0; i < T; ++i) {
        if (!(cin >> A[i])) break;
    }

    long long X;
    if (!(cin >> X)) return 0;

    if (X == 0) {
        if (A[0] == 0) {
            cout << "0 0" << endl;
        } else {
            cout << "Esse numero deve estar errado..." << endl;
        }
        return 0;
    }

    vector<long long> P(T);
    P[0] = A[0];
    for (int i = 1; i < T; ++i) {
        P[i] = P[i - 1] + A[i];
    }

    long long S = P[T - 1];

    if (X > 0) {
        if (S <= 0) {
            cout << "Esse numero deve estar errado..." << endl;
        } else {
            long long L = X / S;
            long long rem = X % S;
            long long target, loop;
            if (rem == 0) {
                target = S;
                loop = L - 1;
            } else {
                target = rem;
                loop = L;
            }
            bool found = false;
            for (int i = 0; i < T; ++i) {
                if (P[i] >= target) {
                    if (P[i] == target) {
                        cout << i << " " << loop << endl;
                    } else {
                        cout << "Esse numero deve estar errado..." << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Esse numero deve estar errado..." << endl;
        }
    } else if (X < 0) {
        if (S >= 0) {
            cout << "Esse numero deve estar errado..." << endl;
        } else {
            long long L = X / S;
            long long rem = X % S;
            long long target, loop;
            if (rem == 0) {
                target = S;
                loop = L - 1;
            } else {
                target = rem;
                loop = L;
            }
            bool found = false;
            for (int i = 0; i < T; ++i) {
                if (P[i] <= target) {
                    if (P[i] == target) {
                        cout << i << " " << loop << endl;
                    } else {
                        cout << "Esse numero deve estar errado..." << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Esse numero deve estar errado..." << endl;
        }
    }

    return 0;
}