/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
== Saida Truncada =</input test>
<output test>
0
1
3
3
3
4
2
3
2
2
3
2
2
10
5
1
1
1
1
10
11
34
31
2307
2252
2118
2232
2176
2227
12470
12558
12502
12573
12586
12551
2321
2269
2200
2177
2245
1417</output teste>
</test 1>
</test cases>
--- FIM DO PROBLEMA ---
```

    The letter representing the starting orientation could be 'N', 'S', 'L', 'O'. Let's ensure the mapping for "L" (Leste - East) and "O" (Oeste - West) is correct.
    N (North) -> row-1
    S (South) -> row+1
    L (East)  -> col+1
    O (West)  -> col-1

    Order: N, L, S, O (Clockwise)
    Index: 0, 1, 2, 3
    Turn 'D': $(i+1)\%4$
    Turn 'E': $(i+3)\%4$

    Wait, the mapping should be:
    'N' -> 0 (dr=-1, dc=0)
    'L' -> 1 (dr=0, dc=1)
    'S' -> 2 (dr=1, dc=0)
    'O' -> 3 (dr=0, dc=-1)
    Check 'D' from 'N': 'N' to 'L' is correct (0 to 1).
    Check 'E' from 'N': 'N' to 'O' is correct (0 to 3).

    The input `S` can be up to 50,000. Use `std::string` or `std::vector<char>` or a fixed-size `char` array.

    - Memory: $100 \times 100$ grid + $50,000$ string = ~60 KB. Well within limits.
    - Time: Process each char once. $O(S)$ per case. $100 \times 100$ to read grid. Total per case $\sim 60,000$ operations. Many cases could fit in 1s.

    Reading $N, M, S$.
    Then $N$ lines of $M$ chars.
    Then the command string of $S$ chars.
    The command string might be on one line or split? "A última linha da entrada contém uma sequência de S caracteres". Usually means one line.

    Wait, I should use `cin >> grid[i]` to skip whitespace if necessary, but the problem says "contém uma cadeia com M caracteres". This often means no spaces within the line. `cin >> grid[i]` is safe. Similarly for the instruction string.

    The collection happens *whenever* the robot occupies a cell.
    If the robot moves to $(r, c)$ and it has a sticker, collect it.
    If the robot tries to move but stays in the *same* cell (due to pillar or boundary), it doesn't "re-occupy" it in a way that would trigger a *new* collection of a *different* sticker. But stickers are removed once collected, so it doesn't matter anyway.
    Wait, what if the robot *starts* on a sticker?
    The problem says the start cell contains 'N', 'S', 'L', or 'O'. These are characters. So the start cell *cannot* contain '*' at the same time.

    Wait, the robot *patina* (skids) and remains in the cell if it hits a pillar or boundary. So the position doesn't change. We only need to check for a sticker after a successful move.

    ```cpp
    if (cmd == 'F') {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] != '#') {
            r = nr;
            c = nc;
            if (grid[r][c] == '*') {
                ans++;
                grid[r][c] = '.';
            }
        }
    }
    ```

    `0 0 0` signals the end.

    - Fast I/O: `ios_base::sync_with_stdio(false); cin.tie(NULL);`
    - Small grid: `char g[105][105]`
    - Directional arrays.
    - Char mapping.
    - Sticker removal.

    ```cpp
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int N, M, S;
        while (cin >> N >> M >> S && (N != 0 || M != 0 || S != 0)) {
            vector<string> grid(N);
            int r, c, d;
            for (int i = 0; i < N; ++i) {
                cin >> grid[i];
                for (int j = 0; j < M; ++j) {
                    if (grid[i][j] == 'N') { r = i; c = j; d = 0; }
                    else if (grid[i][j] == 'L') { r = i; c = j; d = 1; }
                    else if (grid[i][j] == 'S') { r = i; c = j; d = 2; }
                    else if (grid[i][j] == 'O') { r = i; c = j; d = 3; }
                }
            }

            string cmds;
            cin >> cmds;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            int ans = 0;
            for (char cmd : cmds) {
                if (cmd == 'D') {
                    d = (d + 1) % 4;
                } else if (cmd == 'E') {
                    d = (d + 3) % 4;
                } else {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] != '#') {
                        r = nr;
                        c = nc;
                        if (grid[r][c] == '*') {
                            ans++;
                            grid[r][c] = '.';
                        }
                    }
                }
            }
            cout << ans << "\n";
        }
        return 0;
    }
    ```

    The instructions say "RETORNE EXCLUSIVAMENTE CÓDIGO".

    One detail to double-check: "A primeira linha que aparece na descrição da arena é a que está mais ao norte". So row 0 is North. Decreasing row moves North. Increasing row moves South.
    "A primeira coluna que aparece na descrição da uma linha de células da arena é a que está mais a oeste". So col 0 is West. Decreasing col moves West. Increasing col moves East.
    Directions:
    - North (N): row - 1
    - South (S): row + 1
    - East (L): col + 1
    - West (O): col - 1
    Mapping:
    - N: 0, dr=-1, dc=0
    - L: 1, dr=0, dc=1
    - S: 2, dr=1, dc=0
    - O: 3, dr=0, dc=-1
    Turns:
    - N (0) -> D -> L (1)
    - L (1) -> D -> S (2)
    - S (2) -> D -> O (3)
    - O (3) -> D -> N (0)
    Turn D is $(d+1)\%4$. Correct.
    - N (0) -> E -> O (3)
    - O (3) -> E -> S (2)
    - S (2) -> E -> L (1)
    - L (1) -> E -> N (0)
    Turn E is $(d+3)\%4$. Correct.

    - $N, M \le 100$: `int` is fine.
    - $S \le 50,000$: `int` is fine.
    - Sticker count: Max stickers is $100 \times 100 = 10,000$. `int` is fine.

    Wait, is there any possibility of stickers at the starting position? "A letra representa a orientação inicial do robô (única na arena)." It replaces the '.' or '*' at that spot. But if it replaces a '*', does it count as collected?
    Looking at the examples:
    Case 1:
    ***
    *N*
    ***
    Initial N is at (1,1). (1,1) doesn't have a sticker. The code won't collect anything unless it moves.
    If there was a sticker at (1,1), the map would have an 'N' there instead of a '*'. So the robot cannot *start* on a sticker.

    Input strings:
    The grid might have spaces? "contém uma cadeia com M caracteres". `cin >>` usually reads until whitespace. If there are spaces *within* a grid row, `cin >>` might fail. However, in competitive programming "cadeia de caracteres" usually means a single word/string without spaces. Let's use `cin >> string` to be safe. If `getline` was needed, the problem would specify.

    ```cpp
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, m, s;
        while (cin >> n >> m >> s && (n || m || s)) {
            vector<string> grid(n);
            int r, c, d;
            for (int i = 0; i < n; i++) {
                cin >> grid[i];
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 'N') { r = i; c = j; d = 0; }
                    else if (grid[i][j] == 'L') { r = i; c = j; d = 1; }
                    else if (grid[i][j] == 'S') { r = i; c = j; d = 2; }
                    else if (grid[i][j] == 'O') { r = i; c = j; d = 3; }
                }
            }
