/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int D_int, VF_int, VG_int;
    
    while (std::cin >> D_int >> VF_int >> VG_int) {
        if (D_int == -1 && VF_int == -1 && VG_int == -1) {
            break;
        }
        
        double D = static_cast<double>(D_int);
        double VF = static_cast<double>(VF_int);
        double VG = static_cast<double>(VG_int);
        
        double time_fugitive = 12.0 / VF;
        
        double dist_guard = std::sqrt(D * D + 144.0);
        
        double time_guard = dist_guard / VG;
        
        if (time_guard <= time_fugitive) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
    }
    
    return 0;
}
