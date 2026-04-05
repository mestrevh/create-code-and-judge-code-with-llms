/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int age;
    int max_age = -1;
    int total_count = 0;
    int target_count = 0;

    while (cin >> age && age != -1) {
        char sex, hair, eyes;
        if (!(cin >> sex >> hair >> eyes)) break;

        if (age > max_age) {
            max_age = age;
        }

        total_count++;

        if (sex == 'f' && age >= 18 && age <= 35 && hair == 'l' && eyes == 'v') {
            target_count++;
        }
    }

    if (total_count > 0) {
        double percentage = (double)target_count / total_count * 100.0;
        cout << "Mais velho: " << max_age << "\n";
        cout << "Mulheres com olhos verdes, loiras com 18 a 35 anos: " << fixed << setprecision(2) << percentage << "%\n";
    } else {
        // According to problem logic, if no people were entered, we can output 0.00% or nothing.
        // However, the stop condition -1 usually follows data.
        cout << "Mais velho: 0\n";
        cout << "Mulheres com olhos verdes, loiras com 18 a 35 anos: 0.00%\n";
    }

    return 0;
}