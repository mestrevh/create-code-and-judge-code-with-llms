/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums(10);
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (!(cin >> nums[i])) break;
        sum += nums[i];
    }

    double media = sum / 10.0;
    int last_num = nums[9];
    int count_last = 0;
    int pares = 0;
    int div3 = 0;
    vector<int> maiores;

    for (int i = 0; i < 10; ++i) {
        if (nums[i] == last_num) {
            count_last++;
        }
        if (nums[i] % 2 == 0) {
            pares++;
        }
        if (nums[i] % 3 == 0) {
            div3++;
        }
        if (nums[i] > media) {
            maiores.push_back(nums[i]);
        }
    }

    cout << fixed << setprecision(1);
    cout << "Media: " << media << "\n";
    cout << "Ultimo numero: " << count_last << "\n";
    cout << "Pares: " << pares << "\n";
    cout << "Divisiveis por 3: " << div3 << "\n";
    cout << "Lista maiores que a media: [";
    for (size_t i = 0; i < maiores.size(); ++i) {
        cout << maiores[i];
        if (i < maiores.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}