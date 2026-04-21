/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <set>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double grade;
    int phil_approved = 0;
    int total_approved = 0;
    int socio_fail_adult = 0;
    string youngest_name = "";
    int min_age = INT_MAX;
    set<int> ages_seen;

    while (cin >> grade && grade >= 0) {
        string name;
        int age;
        string course_input;
        
        if (!(cin >> name >> age >> course_input)) {
            break;
        }

        if (ages_seen.find(age) != ages_seen.end()) {
            continue;
        }
        ages_seen.insert(age);

        char course = course_input[0];

        if (grade >= 70) {
            total_approved++;
            if (course == 'f') {
                phil_approved++;
            }
        } else {
            if (course == 's' && age >= 18) {
                socio_fail_adult++;
            }
        }

        if (age < min_age) {
            min_age = age;
            youngest_name = name;
        }
    }

    cout << "Quantidade de aprovados em filosofia : " << phil_approved << "\n";
    if (!ages_seen.empty()) {
        cout << "O nome da pessoa mais jovem : " << youngest_name << "\n";
    }
    cout << "Quantidade de aprovados : " << total_approved << "\n";
    cout << "Quantidade pessoas maiores de idade nao aprovadas em sociologia : " << socio_fail_adult << "\n";

    return 0;
}