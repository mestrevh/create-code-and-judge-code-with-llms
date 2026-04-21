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

    double height;
    int age;

    cout << "Digite a altura em m:\n";
    if (!(cin >> height)) return 0;
    
    cout << "Digite a idade:\n";
    if (!(cin >> age)) return 0;

    vector<string> allowed_rides;

    // Barca Viking: 1.50m and 12 years
    if (height >= 1.50 && age >= 12) {
        allowed_rides.push_back("Barca Viking");
    }

    // Elevator of Death: 1.40m and 14 years
    if (height >= 1.40 && age >= 14) {
        allowed_rides.push_back("Elevator of Death");
    }

    // Final Killer: 1.70m or 16 years
    if (height >= 1.70 || age >= 16) {
        allowed_rides.push_back("Final Killer");
    }

    cout << "Voce pode andar em " << allowed_rides.size() << " brinquedos, sendo eles:\n";
    for (const string& ride : allowed_rides) {
        cout << ride << "\n";
    }

    return 0;
}