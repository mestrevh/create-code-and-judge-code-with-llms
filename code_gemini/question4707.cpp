/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

void saudacoes(std::string nome) {
  std::cout << "Olá, " << nome << "! Seja bem-vindo" << std::endl;
}

int main() {
  std::string nome;
  std::getline(std::cin, nome);
  saudacoes(nome);
  return 0;
}
