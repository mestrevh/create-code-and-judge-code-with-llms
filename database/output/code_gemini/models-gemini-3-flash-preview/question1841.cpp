/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    string min_name, max_name;
    long long min_score = 0, max_score = 0;
    long long total_sum = 0;
    int count = 0;

    while (cin >> name && name != "sair") {
        long long current_score;
        if (!(cin >> current_score)) break;

        if (count == 0) {
            min_score = current_score;
            min_name = name;
            max_score = current_score;
            max_name = name;
        } else {
            if (current_score <= min_score) {
                min_score = current_score;
                min_name = name;
            }
            if (current_score >= max_score) {
                max_score = current_score;
                max_name = name;
            }
        }

        total_sum += current_score;
        count++;
    }

    if (count == 0) {
        cout << "Nenhum jogador foi registrado." << endl;
    } else {
        double average = static_cast<double>(total_sum) / count;
        cout << min_name << "\n";
        cout << max_name << "\n";
        cout << fixed << setprecision(2) << average << endl;
    }

    return 0;
}