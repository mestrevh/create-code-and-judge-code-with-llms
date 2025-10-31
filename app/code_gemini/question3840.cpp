/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

const int MAX_K = 100001;
int dopc[MAX_K];

void precompute() {
    for (int i = 3; i < MAX_K; i += 2) {
        if (dopc[i] == 0) {
            for (int j = i; j < MAX_K; j += i) {
                dopc[j]++;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int n, k, p;
    std::cin >> n >> k >> p;

    int first_num = -1;
    int q = 0;

    for (int i = n; i < k; ++i) {
        if (dopc[i] == p) {
            if (first_num == -1) {
                first_num = i;
            } else {
                q++;
            }
        }
    }

    if (first_num != -1) {
        std::cout << first_num << " " << q << std::endl;
    } else {
        std::cout << "Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo." << std::endl;
    }

    return 0;
}
