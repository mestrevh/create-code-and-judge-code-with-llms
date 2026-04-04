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

    double input_salary;
    if (!(cin >> input_salary)) return 0;

    float s = (float)input_salary;
    float d = 0.0f;

    if (s <= 1751.81f) {
        d = s * 0.08f;
    } else if (s <= 2919.72f) {
        d = s * 0.09f;
    } else if (s <= 5839.45f) {
        d = s * 0.11f;
    } else {
        d = 5839.45f * 0.11f;
    }

    cout << "Desconto do INSS: R$ " << fixed << setprecision(6) << (double)d << endl;

    return 0;
}