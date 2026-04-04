/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string current_name;
    string tallest_name = "";
    double current_height;
    double max_height = -1.0;

    while (cin >> current_name && current_name != "parar") {
        if (!(cin >> current_height)) break;
        
        if (current_height > max_height) {
            max_height = current_height;
            tallest_name = current_name;
        }
    }

    if (!tallest_name.empty()) {
        int height_cm = static_cast<int>(round(max_height * 100.0));
        cout << "O aluno mais alto tem " << height_cm << " cm e se chama " << tallest_name << "." << endl;
    }

    return 0;
}