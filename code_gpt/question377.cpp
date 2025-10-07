/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string time1, time2;
    int pontos1, saldoGols1, golsFeitos1;
    int pontos2, saldoGols2, golsFeitos2;

    std::cin >> time1 >> pontos1 >> saldoGols1 >> golsFeitos1;
    std::cin >> time2 >> pontos2 >> saldoGols2 >> golsFeitos2;

    if (pontos1 > pontos2) {
        std::transform(time1.begin(), time1.end(), time1.begin(), ::tolower);
        std::cout << time1 << std::endl;
    } else if (pontos2 > pontos1) {
        std::transform(time2.begin(), time2.end(), time2.begin(), ::tolower);
        std::cout << time2 << std::endl;
    } else {
        if (saldoGols1 > saldoGols2) {
            std::transform(time1.begin(), time1.end(), time1.begin(), ::tolower);
            std::cout << time1 << std::endl;
        } else if (saldoGols2 > saldoGols1) {
            std::transform(time2.begin(), time2.end(), time2.begin(), ::tolower);
            std::cout << time2 << std::endl;
        } else {
            if (golsFeitos1 > golsFeitos2) {
                std::transform(time1.begin(), time1.end(), time1.begin(), ::tolower);
                std::cout << time1 << std::endl;
            } else if (golsFeitos2 > golsFeitos1) {
                std::transform(time2.begin(), time2.end(), time2.begin(), ::tolower);
                std::cout << time2 << std::endl;
            } else {
                std::cout << "EMPATE" << std::endl;
            }
        }
    }

    return 0;
}
