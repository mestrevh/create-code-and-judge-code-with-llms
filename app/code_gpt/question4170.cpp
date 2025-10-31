/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<int> nums(10);
    for (int i = 0; i < 10; ++i) {
        cin >> nums[i];
    }

    double sum = 0;
    for (int num : nums) {
        sum += num;
    }
    double media = sum / 10.0;

    int ultimo_numero = nums[9];
    int pares = 0, divisiveis_por_3 = 0;
    vector<int> maiores;

    for (int num : nums) {
        if (num % 2 == 0) pares++;
        if (num % 3 == 0) divisiveis_por_3++;
        if (num > media) maiores.push_back(num);
    }

    cout << fixed << setprecision(1) << "Media: " << media << endl;
    cout << "Ultimo numero: " << ultimo_numero << endl;
    cout << "Pares: " << pares << endl;
    cout << "Divisiveis por 3: " << divisiveis_por_3 << endl;
    cout << "Lista maiores que a media: [";
    for (size_t i = 0; i < maiores.size(); ++i) {
        cout << maiores[i];
        if (i < maiores.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
