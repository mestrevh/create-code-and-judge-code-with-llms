/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a1, a2, a3, a4;
    std::cin >> a1 >> a2 >> a3 >> a4;

    // Um retângulo dividido por duas linhas perpendiculares e paralelas aos seus lados
    // forma quatro retângulos menores.
    // Se as áreas forem dispostas em uma grade 2x2:
    // A B
    // C D
    //
    // Se as dimensões do retângulo superior esquerdo forem 'w' x 'h', então:
    // A = w * h
    // B = (LarguraTotal - w) * h
    // C = w * (AlturaTotal - h)
    // D = (LarguraTotal - w) * (AlturaTotal - h)
    //
    // Uma propriedade crucial é que o produto das áreas dos retângulos diagonalmente opostos é igual:
    // A * D = (w * h) * ((LarguraTotal - w) * (AlturaTotal - h))
    // B * C = ((LarguraTotal - w) * h) * (w * (AlturaTotal - h))
    //
    // Portanto, A * D == B * C. Esta condição é necessária e, para áreas positivas, também suficiente.
    //
    // O problema fornece quatro áreas a1, a2, a3, a4. A ordem na entrada não indica suas posições.
    // Precisamos verificar se existe *alguma* maneira de atribuir estas quatro áreas às posposições A, B, C, D
    // tal que a condição A * D == B * C seja satisfeita.
    //
    // Existem três maneiras distintas de emparelhar as quatro áreas em dois pares para a verificação diagonal:
    // 1. (a1, a4) e (a2, a3) -> Corresponde a uma atribuição direta de a1=A, a2=B, a3=C, a4=D.
    // 2. (a1, a3) e (a2, a4) -> Corresponde a uma atribuição de a1=A, a2=B, a4=C, a3=D (troca C e D).
    // 3. (a1, a2) e (a3, a4) -> Corresponde a uma atribuição de a1=A, a3=B, a2=C, a4=D (troca B e C).
    //
    // Se qualquer uma dessas três verificações de igualdade de produtos for verdadeira,
    // então o projeto de Bloggs é viável e imprimimos 'S'. Caso contrário, 'N'.

    if ((a1 * a4 == a2 * a3) ||
        (a1 * a3 == a2 * a4) ||
        (a1 * a2 == a3 * a4)) {
        std::cout << 'S' << std::endl;
    } else {
        std::cout << 'N' << std::endl;
    }

    return 0;
}