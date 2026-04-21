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
    if (!(cin >> total_seconds)) return 0;

    long long days = total_seconds / 86400;
    total_seconds %= 86400;

    long long hours = total_seconds / 3600;
    total_seconds %= 3600;

    long long minutes = total_seconds / 60;
    long long seconds = total_seconds % 60;

    cout << days << "\n" << hours << "\n" << minutes << "\n" << seconds << "\n";

    return 0;
}