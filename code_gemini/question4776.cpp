/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    int total_latas = 0;
    int vencedor = -1;
    string horario_vencedor;
    int latas_vencedor = 0;

    if (x == 0) {
        for (int i = 1; i <= n; ++i) {
             
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i % x == 0) {
                total_latas++;
            }
        }
    }


    for (int i = 0; i < y; ++i) {
        string horario;
        int latas;
        cin >> horario >> latas;
        if (x == 0) {
             
        }
        else {

        }
        total_latas += latas;
       
        if (total_latas >= 50 && vencedor == -1) {
            
            int cliente = 0;
            int latas_temp = 0;
            
            if (x == 0) {
                 for (int k = 1; k <= n ; ++k)
                 {
                    
                    if(latas_temp + latas >= 50 && vencedor == -1)
                    {
                        vencedor = k;
                        horario_vencedor = horario;
                        latas_vencedor = latas;
                        
                        break;
                    }

                     if(k <= (n - y) )
                     {
                         latas_temp += 0; 
                     }
                    
                 }
                
                
                
            }
            else{
                for (int k = 1; k <= n ; ++k)
                {
                    
                    if(latas_temp + latas >= 50 && vencedor == -1)
                    {
                        vencedor = k;
                        horario_vencedor = horario;
                        latas_vencedor = latas;
                        break;
                    }
                    if(k % x == 0 && k <= (n - y) )
                    {
                        latas_temp++;
                    }
                    
                }
            }

           
           
            
        }
       
    }


    if (vencedor != -1) {
        cout << "Quem levou a cesta basica foi o " << vencedor << "* cliente atendido por coragem, as " << horario_vencedor << ". Que comprou " << latas_vencedor << (latas_vencedor > 1 ? " latas." : " lata.") << endl;
    } else {
        cout << "Ainda nao foram vendidas latas suficientes. Faltam " << (50 - total_latas) << ( (50 - total_latas) > 1 ? " latas." : " lata.") << endl;
    }

    return 0;
}
