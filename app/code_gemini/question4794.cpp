/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int calcular_sorvetes(int tempo_total, int tempo_por_sorvete) {
    return tempo_total / tempo_por_sorvete;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tempo_badtz, tempo_keroppi, tempo_sorvete;
    
    std::cin >> tempo_badtz >> tempo_keroppi;
    std::cin >> tempo_sorvete;
    
    int sorvetes_badtz = calcular_sorvetes(tempo_badtz, tempo_sorvete);
    int sorvetes_keroppi = calcular_sorvetes(tempo_keroppi, tempo_sorvete);
    
    std::cout << "Badtz-Maru comeu " << sorvetes_badtz << " sorvetes." << std::endl;
    std::cout << "Keroppi comeu " << sorvetes_keroppi << " sorvetes." << std::endl;
    
    return 0;
}
