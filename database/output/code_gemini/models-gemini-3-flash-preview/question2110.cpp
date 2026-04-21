/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string c1, c2;
    long long v1 = 0, v2 = 0;

    if (!(cin >> c1)) return 0;
    
    bool is_c1_r_t = (c1 == "roubo" || c1 == "tráfico");
    if (is_c1_r_t) {
        if (!(cin >> v1)) {}
    }

    if (!(cin >> c2)) {
        cout << "Crime inválido." << endl;
        return 0;
    }
    
    bool is_c2_r_t = (c2 == "roubo" || c2 == "tráfico");
    if (is_c2_r_t) {
        if (!(cin >> v2)) {}
    }

    bool c1_valid = (c1 == "roubo" || c1 == "tráfico" || c1 == "homicídio");
    bool c2_valid = (c2 == "roubo" || c2 == "tráfico" || c2 == "homicídio");

    if (!c1_valid || !c2_valid) {
        cout << "Crime inválido." << endl;
        return 0;
    }

    bool concedida = false;

    if (c1 == "roubo") {
        if (c2 == "roubo") {
            if (v2 > 5 * v1) concedida = true;
        } else if (c2 == "tráfico") {
            if (v2 > 3 * v1) concedida = true;
        } else if (c2 == "homicídio") {
            concedida = true;
        }
    } else if (c1 == "tráfico") {
        if (c2 == "tráfico") {
            if (v2 > 5 * v1) concedida = true;
        } else if (c2 == "homicídio") {
            concedida = true;
        }
    } else if (c1 == "homicídio") {
        if (c2 == "homicídio") {
            concedida = true;
        }
    }

    if (concedida) {
        cout << "Delação concedida." << endl;
    } else {
        cout << "Delação rejeitada." << endl;
    }

    return 0;
}