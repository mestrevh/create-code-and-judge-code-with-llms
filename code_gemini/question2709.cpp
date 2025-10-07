/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

struct PessoaNode {
    std::string nome;
    double nota;
    PessoaNode* next;

    PessoaNode(std::string n, double s) : nome(n), nota(s), next(nullptr) {}
};

void insert_tail(PessoaNode** head, std::string nome, double nota) {
    PessoaNode* new_node = new PessoaNode(nome, nota);
    if (*head == nullptr) {
        *head = new_node;
        return;
    }
    PessoaNode* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void free_list(PessoaNode* head) {
    PessoaNode* current = head;
    while (current != nullptr) {
        PessoaNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double nota_atual;
    std::cin >> nota_atual;

    PessoaNode* all_people_head = nullptr;
    std::string nome;
    double nota_pessoa;
    while (std::cin >> nome >> nota_pessoa) {
        insert_tail(&all_people_head, nome, nota_pessoa);
    }
    
    double limite = nota_atual - 0.2;
    
    PessoaNode* bons_amigos_head = nullptr;

    PessoaNode* current = all_people_head;
    while (current != nullptr) {
        if (current->nota < limite) {
            std::cout << current->nome << " nao serve para aumentar minha nota.\n";
        } else {
            insert_tail(&bons_amigos_head, current->nome, current->nota);
        }
        current = current->next;
    }

    bool conseguiu = false;
    double aumento_total = 0.0;
    const double nota_sonhada = 4.5;
    
    PessoaNode* nao_precisa_head = nullptr;
    
    current = bons_amigos_head;
    while (current != nullptr) {
        if (conseguiu) {
            insert_tail(&nao_precisa_head, current->nome, current->nota);
            current = current->next;
            continue;
        }

        double p_nota = current->nota;
        double x;
        if (p_nota >= 4.8) {
            x = 1.2;
        } else if (p_nota >= 4.5) {
            x = 1.0;
        } else if (p_nota >= 4.0) {
            x = 0.8;
        } else {
            x = 0.5;
        }
        
        double aumento;
        if (p_nota > nota_atual) {
            aumento = ( (p_nota - nota_atual) * x ) / 50.0 + (p_nota - nota_atual)/10.0;
        } else {
            aumento = ( (nota_atual - p_nota) * x ) / 50.0 + (nota_atual - p_nota)/100.0;
        }


        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Minha nota aumentou em " << aumento << " por causa de " << current->nome << "!\n";

        nota_atual += aumento;
        aumento_total += aumento;

        if (nota_atual >= nota_sonhada) {
            conseguiu = true;
            std::cout << "Consegui a nota sonhada, ja posso comprar a casa dos meus sonhos, nao preciso de mais ninguem.\n";
        } else {
            double diferenca = nota_sonhada - nota_atual;
            std::cout << "Ja consegui aumentar " << aumento_total << " na minha nota\n";
            std::cout << "Atualmente estou com " << nota_atual << " e ainda falta " << diferenca << " para conseguir a nota sonhada.\n";
        }
        
        current = current->next;
    }

    if (nao_precisa_head != nullptr) {
        std::cout << "Pessoas que nao preciso cativar:\n";
        current = nao_precisa_head;
        while(current != nullptr) {
            std::cout << current->nome << "\n";
            current = current->next;
        }
    }

    if (!conseguiu && bons_amigos_head != nullptr) {
        std::cout << "Mesmo com tantos amigos nao consegui minha casa dos sonhos :(\n";
    }

    free_list(all_people_head);
    free_list(bons_amigos_head);
    free_list(nao_precisa_head);

    return 0;
}
