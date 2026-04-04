/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    long long sake_available = A * 15;
    long long sake_required = D * 4;
    long long manju_required = D * 5;
    long long yakitori_required = D * 3;

    long long sake_missing = sake_required > sake_available ? sake_required - sake_available : 0;
    long long manju_missing = manju_required > B ? manju_required - B : 0;
    long long yakitori_missing = yakitori_required > C ? yakitori_required - C : 0;

    int missing_count = (sake_missing > 0) + (manju_missing > 0) + (yakitori_missing > 0);

    if (missing_count == 0) {
        cout << "Partiu Festa do Japa!" << "\n";
    } else if (missing_count == 3) {
        cout << "Partiu Festa do Japa...Japacama" << "\n";
    } else {
        vector<pair<long long, string>> missing;
        if (sake_missing > 0) missing.push_back({sake_missing, "saques"});
        if (manju_missing > 0) missing.push_back({manju_missing, "manjus"});
        if (yakitori_missing > 0) missing.push_back({yakitori_missing, "yakitoris"});

        cout << "Faltaram ";
        if (missing.size() == 1) {
            cout << missing[0].first << " " << missing[0].second << "\n";
        } else {
            cout << missing[0].first << " " << missing[0].second << " e " << missing[1].first << " " << missing[1].second << "\n";
        }
    }

    return 0;
}