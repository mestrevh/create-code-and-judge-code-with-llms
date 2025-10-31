/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

struct Smartphone {
    std::string modelo;
    int memoriaGB;
    float processadorGHz;
    float cameraMPix;
    float bateria;
};

int cadastraSmartphone(int qnt_cadastrada, Smartphone phone[10]) {
    if (qnt_cadastrada >= 10) {
        return qnt_cadastrada;
    }

    Smartphone& novo_phone = phone[qnt_cadastrada];
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, novo_phone.modelo);
    std::cin >> novo_phone.memoriaGB;
    std::cin >> novo_phone.processadorGHz;
    std::cin >> novo_phone.cameraMPix;
    std::cin >> novo_phone.bateria;

    return qnt_cadastrada + 1;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone reqMin, Smartphone phone[10]) {
    int encontrados = 0;
    bool first_print = true;
    
    for (int i = 0; i < qnt_cadastrada; ++i) {
        if (phone[i].memoriaGB >= reqMin.memoriaGB &&
            phone[i].processadorGHz >= reqMin.processadorGHz &&
            phone[i].cameraMPix >= reqMin.cameraMPix &&
            phone[i].bateria >= reqMin.bateria) {
            
            if (!first_print) {
                std::cout << std::endl;
            }
            
            std::cout << "Modelo: " << phone[i].modelo << std::endl;
            std::cout << "Memoria: " << phone[i].memoriaGB << "GB" << std::endl;
            std::cout << "Processador: " << phone[i].processadorGHz << "Ghz" << std::endl;
            
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Camera: " << phone[i].cameraMPix << "MPixels" << std::endl;
            std::cout << "Bateria: " << phone[i].bateria << "mA" << std::endl;
            
            first_print = false;
            encontrados++;
        }
    }
    
    if(encontrados > 0){
        std::cout << std::endl;
    }
    
    return encontrados;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Smartphone phone_list[10];
    int count = 0;
    char choice;

    while (count < 10) {
        std::cin >> choice;
        if (choice == 's') {
            count = cadastraSmartphone(count, phone_list);
        } else {
            break;
        }
    }

    Smartphone min_reqs;
    std::cin >> min_reqs.memoriaGB;
    std::cin >> min_reqs.processadorGHz;
    std::cin >> min_reqs.cameraMPix;
    std::cin >> min_reqs.bateria;

    int found_count = pesquisaSmartphones(count, min_reqs, phone_list);

    std::cout << found_count << " smartphones encontrados." << std::endl;

    return 0;
}
