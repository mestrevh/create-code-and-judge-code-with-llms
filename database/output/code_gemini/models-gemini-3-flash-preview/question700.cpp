/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long total_seconds;
    while (cin >> total_seconds) {
        long long hours = total_seconds / 3600;
        long long remaining_seconds = total_seconds % 3600;
        long long minutes = remaining_seconds / 60;
        long long seconds = remaining_seconds % 60;

        cout << hours << " h " << minutes << " m " << seconds << " s" << "\n";
    }

    return 0;
}