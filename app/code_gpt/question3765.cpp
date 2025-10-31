/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

void OrdenaMatriz(int *maior, int *segundo, int *terceiro, int *menor, int *matriz) {
    int nums[4] = {*menor, *segundo, *terceiro, *maior};
    sort(nums, nums + 4);
    *menor = nums[0];
    *segundo = nums[1];
    *maior = nums[3];
    *terceiro = nums[2];
}

int main() {
    int matriz[5][5], nums[4] = {0, 0, 0, 0}, count = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            cin >> matriz[i][j];
            if (matriz[i][j] != 0 && count < 4) {
                nums[count++] = abs(matriz[i][j]);
            }
        }
    while (count < 4) nums[count++] = 0;
    int maior = nums[0], segundo = nums[1], terceiro = nums[2], menor = nums[3];
    OrdenaMatriz(&maior, &segundo, &terceiro, &menor, nullptr);
    cout << menor << " " << maior << endl;
    cout << segundo << " " << terceiro << endl;
    return 0;
}
