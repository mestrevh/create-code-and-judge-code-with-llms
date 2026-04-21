/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long C, T;
    long long P;
    if (!(cin >> C >> T)) return 0;
    if (!(cin >> P)) return 0;

    const long long ML_PER_TRY = 12;
    const long long MAX_ML = 300;

    auto reached = [&](long long f) -> bool {
        return f >= P;
    };

    __int128 f0 = C;
    if (reached((long long)f0) || f0 > (__int128)LLONG_MAX) {
        long long ml = 0;
        cout << "Eleven perdeu " << ml << "ml de sangue.";
        return 0;
    }

    __int128 f_prev2 = C; 
    __int128 f_prev1 = T; 

    long long tries = 1;
    __int128 cap = (__int128)MAX_ML / ML_PER_TRY + 1;
    long long maxTriesStrict = MAX_ML / ML_PER_TRY; 

    auto stopIfLose = [&](long long currentTries) -> bool {
        long long ml = currentTries * ML_PER_TRY;
        return ml > MAX_ML;
    };

    auto safeMulAdd = [&](const __int128 &a, const __int128 &b) -> __int128 {
        __int128 res = 0;
        res = 2 * a + b;
        return res;
    };

    if (tries * ML_PER_TRY <= MAX_ML && reached((long long)f_prev1) && f_prev1 <= (__int128)LLONG_MAX) {
        long long ml = tries * ML_PER_TRY;
        cout << "Eleven perdeu " << ml << "ml de sangue.";
        return 0;
    }
    if (tries * ML_PER_TRY <= MAX_ML && f_prev1 > (__int128)LLONG_MAX) {
        long long ml = tries * ML_PER_TRY;
        cout << "Eleven perdeu " << ml << "ml de sangue.";
        return 0;
    }

    while (true) {
        if (stopIfLose(tries)) break;

        __int128 f_cur = safeMulAdd(f_prev1, f_prev2);
        tries++;
        if (tries * ML_PER_TRY > MAX_ML) break;

        if (f_cur >= (__int128)P) {
            long long ml = tries * ML_PER_TRY;
            cout << "Eleven perdeu " << ml << "ml de sangue.";
            return 0;
        }

        f_prev2 = f_prev1;
        f_prev1 = f_cur;
        if (tries > maxTriesStrict + 2) break;
    }

    cout << "Eleven ficou fraca demais e acabou desmaiando";
    return 0;
}