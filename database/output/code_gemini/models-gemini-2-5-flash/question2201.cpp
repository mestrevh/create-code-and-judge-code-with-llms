/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long L, C;
    std::cin >> L >> C;

    // Based on the problem description and provided examples (L=3, C=5 -> 23 type 1, 12 type 2; L=1, C=1 -> 1 type 1, 0 type 2),
    // we can deduce the following formulas:
    //
    // A type 1 tile is a square with 1 meter diagonal, covering 0.5 square meters.
    // A type 2 tile is half of a type 1 tile, covering 0.25 square meters.
    // A type 3 tile is half of a type 2 tile, covering 0.125 square meters.
    //
    // The problem states that 4 type 3 tiles are always needed for the corners.
    // The total area covered by these 4 type 3 tiles is 4 * 0.125 = 0.5 square meters.
    //
    // For type 2 tiles:
    // These tiles cover the "edges" of the room, excluding the 4 corners.
    // For a room of L x C, there are (L-1) segments along each of the two C-length sides,
    // and (C-1) segments along each of the two L-length sides.
    // Thus, the total number of "edge units" not at corners is 2 * (L-1) + 2 * (C-1).
    // Each such segment requires one type 2 tile.
    // So, num_type2 = 2 * (L-1) + 2 * (C-1) = 2 * (L + C - 2).
    //
    // For type 1 tiles:
    // The total area of the room is L * C square meters.
    // The area covered by type 3 tiles is 0.5 square meters.
    // The area covered by type 2 tiles is num_type2 * 0.25 square meters.
    // Area_type2 = (2 * (L + C - 2)) * 0.25 = (L + C - 2) / 2 square meters.
    //
    // The remaining area must be covered by type 1 tiles:
    // Area_remaining = L * C - 0.5 - (L + C - 2) / 2
    // Area_remaining = L * C - (1/2) - (L/2 + C/2 - 1)
    // Area_remaining = L * C - (0.5 + 0.5*L + 0.5*C - 1)
    // Area_remaining = L * C - (0.5*L + 0.5*C - 0.5)
    // This can be written as L * C - (L + C - 1) / 2.
    //
    // Since each type 1 tile covers 0.5 square meters:
    // num_type1 = Area_remaining / 0.5
    // num_type1 = (L * C - (L + C - 1) / 2) / (1/2)
    // num_type1 = 2 * L * C - (L + C - 1).

    long long num_type1 = 2 * L * C - (L + C - 1);
    long long num_type2 = 2 * (L + C - 2);

    std::cout << num_type1 << "\n";
    std::cout << num_type2 << "\n";

    return 0;
}