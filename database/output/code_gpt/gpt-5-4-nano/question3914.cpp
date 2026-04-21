/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long total;
    long long x, y, z;
    if (!(cin >> total)) return 0;
    if (!(cin >> x >> y >> z)) return 0;

    auto solveWithDivision = [&](long long invest, bool withLetters, long long& A, long long& B, long long& C, string& msg) -> bool {
        long long sumPerc = x + y + z;
        long double tp = (long double)(total + invest);

        auto rounded = [&](long double v) -> long long {
            return (long long) llround(v);
        };

        long double va = tp * (long double)x / 100.0L;
        long double vb = tp * (long double)y / 100.0L;
        long double vc = tp * (long double)z / 100.0L;

        bool isInt = (fabsl(va - floor(va)) < 1e-12L) && (fabsl(vb - floor(vb)) < 1e-12L) && (fabsl(vc - floor(vc)) < 1e-12L);

        long double used = va + vb + vc;
        long double leftover = tp - used;

        long long leftoverInt = 0;
        bool leftoverIsInt = fabsl(leftover - floor(leftover)) < 1e-9L;
        if (leftoverIsInt) leftoverInt = (long long) llround(leftover);

        if (withLetters) {
            char a, b, c;
            cin >> a >> b >> c;
            int Aletter = tolower(a) - 'a' + 1;
            int Bletter = tolower(b) - 'a' + 1;
            int Cletter = tolower(c) - 'a' + 1;
            cout << (Aletter + Bletter + Cletter) << "\n";
            return false;
        } else {
            int aage, bage, cage;
            cin >> aage >> bage >> cage;

            bool cond = (aage % 3 == 0) || (bage % 3 == 0) || (cage % 3 == 0);

            if (!cond) return false;

            long long ages[3] = {aage, bage, cage};
            long long parcels = 0;
            for (int i = 0; i < 3; i++) {
                if (ages[i] % 3 == 0) parcels += ages[i] / 3;
            }
            cout << parcels << "\n";
            return false;
        }
    };

    auto computeDivision = [&](long long newTotal, long long& A, long long& B, long long& C) -> bool {
        long double va = (long double)newTotal * (long double)x / 100.0L;
        long double vb = (long double)newTotal * (long double)y / 100.0L;
        long double vc = (long double)newTotal * (long double)z / 100.0L;
        bool ok = (fabsl(va - floor(va)) < 1e-12L) && (fabsl(vb - floor(vb)) < 1e-12L) && (fabsl(vc - floor(vc)) < 1e-12L);
        if (!ok) return false;
        A = (long long) llround(va);
        B = (long long) llround(vb);
        C = (long long) llround(vc);
        return true;
    };

    auto leftoverCondition = [&](long long newTotal, long long A, long long B, long long C, long long invest) -> bool {
        long long leftover = newTotal - (A + B + C);
        return leftover >= invest + 1;
    };

    long long A=0,B=0,C=0;
    long long newTotal = total;

    bool intDivision = computeDivision(newTotal, A, B, C);

    if (intDivision) {
        cout << "Cada homem ficou com " << A << ", " << B << " e " << C << " reais, respectivamente\n";
        if (total >= 7) {
            cout << "Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n";
        } else {
            cout << "E parece que Rebeka vai ter que voltar andando...\n";
        }
        return 0;
    }

    long long withTwo = total + 2;
    long long A2,B2,C2;
    if (computeDivision(withTwo, A2, B2, C2)) {
        cout << "Cada homem ficou com " << A2 << ", " << B2 << " e " << C2 << " reais, respectivamente\n";
        if (withTwo - total >= 0) {
            if (total >= 5) {
                cout << "Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n";
            } else {
                cout << "E parece que Rebeka vai ter que voltar andando...\n";
            }
        } else {
            cout << "E parece que Rebeka vai ter que voltar andando...\n";
        }
        return 0;
    }

    long long withThree = total + 3;
    long long A3,B3,C3;
    if (computeDivision(withThree, A3, B3, C3)) {
        if (leftoverCondition(withThree, A3, B3, C3, 3)) {
            cout << "Cada homem ficou com " << A3 << ", " << B3 << " e " << C3 << " reais, respectivamente\n";
            if (total >= 4) {
                cout << "Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n";
            } else {
                cout << "E parece que Rebeka vai ter que voltar andando...\n";
            }
        } else {
            cout << "Nao foi dessa vez que Rebeka pode ajudar...\n";
        }
        return 0;
    }

    long long A4,B4,C4;
    if (computeDivision(total, A4, B4, C4)) {
        cout << "Cada homem ficou com " << A4 << ", " << B4 << " e " << C4 << " reais, respectivamente\n";
        if (total >= 7) {
            cout << "Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n";
        } else {
            cout << "E parece que Rebeka vai ter que voltar andando...\n";
        }
        return 0;
    }

    cout << "Nao foi dessa vez que Rebeka pode ajudar...\n";
    return 0;
}