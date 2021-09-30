#include <stdio.h>

#define EMPTYCELL '.'
#define TRUE 1
#define FALSE 0
#define WHITE 'W'
#define BLACK 'B'
#define ERROR "Please enter correct number :\n"
#define TABLEFORMAT "    1  2  3  4  5  6  7  8\n10  %c  %c  %c  %c  %c  %c  %c  %c\n20  %c  %c  %c  %c  %c  %c  %c  %c\n30  %c  %c  %c  %c  %c  %c  %c  %c\n40  %c  %c  %c  %c  %c  %c  %c  %c\n50  %c  %c  %c  %c  %c  %c  %c  %c\n60  %c  %c  %c  %c  %c  %c  %c  %c\n70  %c  %c  %c  %c  %c  %c  %c  %c\n80  %c  %c  %c  %c  %c  %c  %c  %c\n"

/*Functions Prototypes*/
void preTableDefine(char [9][9]);
void upadteGameData(int[2], char [9][9], char);
char roundTurn(int);
void printTable(char [9][9]);
void inputCheck(char[9][9], int[2], char);
void changeCell(char[9][9], int[2], char);
int possibleMove(char[9][9], char);
int possiblePlace(char [9][9], int [2], char);
int newGame(char[9][9]);
void winPlayer(char[9][9]);

/*Making The Table For First round*/
void preTableDefine(char cells[9][9]) {

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cells[i][j] = EMPTYCELL;
        }
    }

    cells[4][4] = WHITE;
    cells[5][5] = WHITE;
    cells[4][5] = BLACK;
    cells[5][4] = BLACK;
}

/*Put Player Achate In Table*/
void upadteGameData(int position[2], char cells[9][9], char turn) {

    cells[position[0]][position[1]] = turn;
}

/*Check How Have To Playe*/
char roundTurn(int round) {

    if ((round % 2) == 1) return BLACK;
    else if ((round % 2) == 0) return WHITE;
    else return '?';
}

/*Print Table*/
void printTable(char cells[9][9]) {

    int bCount = 0;
    int wCount = 0;

    printf(TABLEFORMAT, cells[1][1], cells[1][2], cells[1][3], cells[1][4], cells[1][5], cells[1][6], cells[1][7],
           cells[1][8], cells[2][1], cells[2][2], cells[2][3], cells[2][4], cells[2][5], cells[2][6], cells[2][7],
           cells[2][8], cells[3][1], cells[3][2], cells[3][3], cells[3][4], cells[3][5], cells[3][6], cells[3][7],
           cells[3][8], cells[4][1], cells[4][2], cells[4][3], cells[4][4], cells[4][5], cells[4][6], cells[4][7],
           cells[4][8], cells[5][1], cells[5][2], cells[5][3], cells[5][4], cells[5][5], cells[5][6], cells[5][7],
           cells[5][8], cells[6][1], cells[6][2], cells[6][3], cells[6][4], cells[6][5], cells[6][6], cells[6][7],
           cells[6][8], cells[7][1], cells[7][2], cells[7][3], cells[7][4], cells[7][5], cells[7][6], cells[7][7],
           cells[7][8], cells[8][1], cells[8][2], cells[8][3], cells[8][4], cells[8][5], cells[8][6], cells[8][7],
           cells[8][8]);

    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            if (cells[i][j] == WHITE) wCount++;
            else if (cells[i][j] == BLACK) bCount++;
        }
    }

    printf("[ Black : %d ] [ White : %d ]\n", bCount, wCount);
}

/*Check Valid Input*/
void inputCheck(char cells[9][9], int position[2], char turn) {

    char tempTurn;
    int tempPosition;
    if (turn == BLACK) tempTurn = WHITE;
    else if (turn == WHITE) tempTurn = BLACK;

    while (TRUE) {

        printf("PLAYER %c TURN\n", turn);
        fflush(stdin);
        scanf("%d", &tempPosition);
        position[1] = tempPosition % 10;
        tempPosition = tempPosition / 10;
        position[0] = tempPosition;

        if (((position[0] == 1) || (position[0] == 2) || (position[0] == 3)
             || (position[0] == 4) || (position[0] == 5) || (position[0] == 6)
             || (position[0] == 7) || (position[0] == 8))
            && ((position[1] == 1) || (position[1] == 2) || (position[1] == 3)
                || (position[1] == 4) || (position[1] == 5) || (position[1] == 6)
                || (position[1] == 7) || (position[1] == 8))) {

            if (cells[position[0]][position[1]] == EMPTYCELL) {

                if ((cells[position[0] + 1][position[1]]) == tempTurn
                    || (cells[position[0] - 1][position[1]]) == tempTurn
                    || (cells[position[0]][position[1] + 1]) == tempTurn
                    || (cells[position[0]][position[1] - 1]) == tempTurn
                    || (cells[position[0] + 1][position[1] + 1]) == tempTurn
                    || (cells[position[0] - 1][position[1] - 1]) == tempTurn
                    || (cells[position[0] - 1][position[1] + 1]) == tempTurn
                    || (cells[position[0] + 1][position[1] - 1]) == tempTurn) {

                    if (possiblePlace(cells, position, turn) == TRUE) {

                        break;

                    } else {
                        printf(ERROR);
                        continue;
                    }
                } else {
                    printf(ERROR);
                    continue;
                }
            } else {
                printf(ERROR);
                continue;
            }
        } else {
            printf(ERROR);
            continue;
        }
    }
}

/*Updating Table By Revers Surrounded Achates*/
void changeCell(char cells[9][9], int position[2], char turn) {

    char tempTurn;
    if (turn == BLACK) tempTurn = WHITE;
    else if (turn == WHITE) tempTurn = BLACK;

    int a;
    for (a = position[1] + 1; a < 9; ++a) {
        if (cells[position[0]][a] == tempTurn) continue;
        else if (cells[position[0]][a] == turn) break;
        else if (cells[position[0]][a] == EMPTYCELL) {
            a = 0;
            break;
        }
    }
    if ((a > 0) && (a < 9)) {
        for (int k = position[1]; k < a; ++k) {
            if (k == 9) break;
            if (cells[position[0]][k] != EMPTYCELL) cells[position[0]][k] = turn;
        }
    }

    int b;
    for (b = position[1] - 1; b > 0; --b) {
        if (cells[position[0]][b] == tempTurn) continue;
        else if (cells[position[0]][b] == turn) break;
        else if (cells[position[0]][b] == EMPTYCELL) {
            b = 10;
            break;
        }
    }
    if ((b < 9) && (b > 0)) {
        for (int k = position[1]; k > b; --k) {
            if (k == 0) break;
            if (cells[position[0]][k] != EMPTYCELL) cells[position[0]][k] = turn;
        }
    }

    int c;
    for (c = position[0] - 1; c > 0; --c) {
        if (cells[c][position[1]] == tempTurn) continue;
        else if (cells[c][position[1]] == turn) break;
        else if (cells[c][position[1]] == EMPTYCELL) {
            c = 10;
            break;
        }
    }
    if ((c < 9) && (c > 0)) {
        for (int k = position[0]; k > c; --k) {
            if (k == 0) break;
            if (cells[k][position[1]] != EMPTYCELL) cells[k][position[1]] = turn;
        }
    }

    int d;
    for (d = position[0] + 1; d < 9; ++d) {
        if (cells[d][position[1]] == tempTurn) continue;
        else if (cells[d][position[1]] == turn) break;
        else if (cells[d][position[1]] == EMPTYCELL) {
            d = 0;
            break;
        }
    }
    if ((d > 0) && (d < 9)) {
        for (int k = position[0]; k < d; ++k) {
            if (k == 9) break;
            if (cells[k][position[1]] != EMPTYCELL) cells[k][position[1]] = turn;
        }
    }

    int e, f;
    for (e = position[0] + 1; e < 9;) {
        for (f = position[1] + 1; f < 9;) {
            if (cells[e][f] == tempTurn) {
                e++;
                f++;
                continue;
            } else if (cells[e][f] == turn) break;
            else if (cells[e][f] == EMPTYCELL) {
                e = 0;
                f = 0;
                break;
            }
            if ((e == 9) || (f == 9)) break;
        }
        if ((e == 9) || (f == 9)) break;
        if ((e == 0) || (f == 0)) break;
        else if (cells[e][f] == turn) break;
    }
    if ((e > 0) && (f > 0) && (e < 9) && (f < 9)) {
        for (int i = position[0]; i < e;) {
            for (int j = position[1]; j < f;) {
                if ((i == 9) || (j == 9)) break;
                if (cells[i][j] != EMPTYCELL) cells[i][j] = turn;
                i++;
                j++;
            }
        }
    }

    int g, h;
    for (g = position[0] - 1; g > 0;) {
        for (h = position[1] - 1; h > 0;) {
            if (cells[g][h] == tempTurn) {
                g--;
                h--;
                continue;
            } else if (cells[g][h] == turn) break;
            else if (cells[g][h] == EMPTYCELL) {
                g = 10;
                h = 10;
                break;
            }
            if ((g == 0) || (h == 0)) break;
        }
        if ((g == 0) || (h == 0)) break;
        if ((g == 10) || (h == 10)) break;
        else if (cells[g][h] == turn) break;
    }
    if ((g < 9) && (h < 9) && (g > 0) && (h > 0)) {
        for (int i = position[0]; i > g;) {
            for (int j = position[1]; j > h;) {
                if ((i == 0) || (j == 0)) break;
                if (cells[i][j] != EMPTYCELL) cells[i][j] = turn;
                i--;
                j--;
            }
        }
    }

    int m, n;
    for (m = position[0] + 1; m < 9;) {
        for (n = position[1] - 1; n > 0;) {
            if (cells[m][n] == tempTurn) {
                m++;
                n--;
                continue;
            } else if (cells[m][n] == turn) break;
            else if (cells[m][n] == EMPTYCELL) {
                m = 0;
                n = 10;
                break;
            }
            if ((m == 9) || (n == 0)) break;
        }
        if ((m == 9) || (n == 0)) break;
        if ((m == 0) || (n == 10)) break;
        else if (cells[m][n] == turn) break;
    }
    if ((m > 0) && (n < 9) && (m < 9) && (n > 0)) {
        for (int i = position[0]; i < m;) {
            for (int j = position[1]; j > n;) {
                if ((i == 9) || (j == 0)) break;
                if (cells[i][j] != EMPTYCELL) cells[i][j] = turn;
                i++;
                j--;
            }
        }
    }

    int o, p;
    for (o = position[0] - 1; o > 0;) {
        for (p = position[1] + 1; p < 9;) {
            if (cells[o][p] == tempTurn) {
                o--;
                p++;
                continue;
            } else if (cells[o][p] == turn) break;
            else if (cells[o][p] == EMPTYCELL) {
                o = 10;
                p = 0;
                break;
            }
            if ((o == 0) || (p == 9)) break;
        }
        if ((o == 0) || (p == 9)) break;
        if ((o == 10) || (p == 0)) break;
        else if (cells[o][p] == turn) break;
    }
    if ((o < 9) && (p > 0) && (o > 0) && (p < 9)) {
        for (int i = position[0]; i > o;) {
            for (int j = position[1]; j < p;) {
                if ((i == 0) || (j == 9)) break;
                if (cells[i][j] != EMPTYCELL) cells[i][j] = turn;
                i--;
                j++;
            }
        }
    }
}

/*Check If Player Can Have A Move To Revers Any Achate*/
int possibleMove(char cells[9][9], char turn) {

    char tempTurn;
    int check = 0;
    if (turn == BLACK) tempTurn = WHITE;
    else if (turn == WHITE) tempTurn = BLACK;

    for (int pass = 0; pass <= 2; pass++) {

        for (int l = 1; l < 9; ++l) {
            for (int v = 1; v < 9; ++v) {

                if (cells[l][v] != EMPTYCELL) continue;

                int a;
                for (a = v + 1; a < 9; ++a) {
                    if (cells[l][a] == tempTurn) continue;
                    else if (cells[l][a] == turn) break;
                    else if (cells[l][a] == EMPTYCELL) {
                        a = 0;
                        break;
                    }
                }
                if ((a > 0) && (a < 9)) {
                    for (int k = v; k < a; ++k) {
                        if (k == 9) break;
                        if (cells[l][k] != EMPTYCELL) check++;
                    }
                }

                int b;
                for (b = v - 1; b > 0; --b) {
                    if (cells[l][b] == tempTurn) continue;
                    else if (cells[l][b] == turn) break;
                    else if (cells[l][b] == EMPTYCELL) {
                        b = 10;
                        break;
                    }
                }
                if ((b < 9) && (b > 0)) {
                    for (int k = v; k > b; --k) {
                        if (k == 0) break;
                        if (cells[l][k] != EMPTYCELL) check++;
                    }
                }

                int c;
                for (c = l - 1; c > 0; --c) {
                    if (cells[c][v] == tempTurn) continue;
                    else if (cells[c][v] == turn) break;
                    else if (cells[c][v] == EMPTYCELL) {
                        c = 10;
                        break;
                    }
                }
                if ((c < 9) && (c > 0)) {
                    for (int k = l; k > c; --k) {
                        if (k == 0) break;
                        if (cells[k][v] != EMPTYCELL) check++;
                    }
                }

                int d;
                for (d = l + 1; d < 9; ++d) {
                    if (cells[d][v] == tempTurn) continue;
                    else if (cells[d][v] == turn) break;
                    else if (cells[d][v] == EMPTYCELL) {
                        d = 0;
                        break;
                    }
                }
                if ((d > 0) && (d < 9)) {
                    for (int k = l; k < d; ++k) {
                        if (k == 9) break;
                        if (cells[k][v] != EMPTYCELL) check++;
                    }
                }

                int e, f;
                for (e = l + 1; e < 9;) {
                    for (f = v + 1; f < 9;) {
                        if (cells[e][f] == tempTurn) {
                            e++;
                            f++;
                            continue;
                        } else if (cells[e][f] == turn) break;
                        else if (cells[e][f] == EMPTYCELL) {
                            e = 0;
                            f = 0;
                            break;
                        }
                        if ((e == 9) || (f == 9)) break;
                    }
                    if ((e == 9) || (f == 9)) break;
                    if ((e == 0) || (f == 0)) break;
                    else if (cells[e][f] == turn) break;
                }
                if ((e > 0) && (f > 0) && (e < 9) && (f < 9)) {
                    for (int i = l; i < e;) {
                        for (int j = v; j < f;) {
                            if ((i == 9) || (j == 9)) break;
                            if (cells[i][j] != EMPTYCELL) check++;
                            i++;
                            j++;
                        }
                    }
                }

                int g, h;
                for (g = l - 1; g > 0;) {
                    for (h = v - 1; h > 0;) {
                        if (cells[g][h] == tempTurn) {
                            g--;
                            h--;
                            continue;
                        } else if (cells[g][h] == turn) break;
                        else if (cells[g][h] == EMPTYCELL) {
                            g = 10;
                            h = 10;
                            break;
                        }
                        if ((g == 0) || (h == 0)) break;
                    }
                    if ((g == 0) || (h == 0)) break;
                    if ((g == 10) || (h == 10)) break;
                    else if (cells[g][h] == turn) break;
                }
                if ((g < 9) && (h < 9) && (g > 0) && (h > 0)) {
                    for (int i = l; i > g;) {
                        for (int j = v; j > h;) {
                            if ((i == 0) || (j == 0)) break;
                            if (cells[i][j] != EMPTYCELL) check++;
                            i--;
                            j--;
                        }
                    }
                }

                int m, n;
                for (m = l + 1; m < 9;) {
                    for (n = v - 1; n > 0;) {
                        if (cells[m][n] == tempTurn) {
                            m++;
                            n--;
                            continue;
                        } else if (cells[m][n] == turn) break;
                        else if (cells[m][n] == EMPTYCELL) {
                            m = 0;
                            n = 10;
                            break;
                        }
                        if ((m == 9) || (n == 0)) break;
                    }
                    if ((m == 9) || (n == 0)) break;
                    if ((m == 0) || (n == 10)) break;
                    else if (cells[m][n] == turn) break;
                }
                if ((m > 0) && (n < 9) && (m < 9) && (n > 0)) {
                    for (int i = l; i < m;) {
                        for (int j = v; j > n;) {
                            if ((i == 9) || (j == 0)) break;
                            if (cells[i][j] != EMPTYCELL) check++;
                            i++;
                            j--;
                        }
                    }
                }

                int o, p;
                for (o = l - 1; o > 0;) {
                    for (p = v + 1; p < 9;) {
                        if (cells[o][p] == tempTurn) {
                            o--;
                            p++;
                            continue;
                        } else if (cells[o][p] == turn) break;
                        else if (cells[o][p] == EMPTYCELL) {
                            o = 10;
                            p = 0;
                            break;
                        }
                        if ((o == 0) || (p == 9)) break;
                    }
                    if ((o == 0) || (p == 9)) break;
                    if ((o == 10) || (p == 0)) break;
                    else if (cells[o][p] == turn) break;
                }
                if ((o < 9) && (p > 0) && (o > 0) && (p < 9)) {
                    for (int i = l; i > o;) {
                        for (int j = v; j < p;) {
                            if ((i == 0) || (j == 9)) break;
                            if (cells[i][j] != EMPTYCELL) check++;
                            i--;
                            j++;
                        }
                    }
                }
            }
        }
    }

    if (check > 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*Check If Chossen Place Can Revers Any Achate*/
int possiblePlace(char cells[9][9], int position[2], char turn) {

    char tempTurn;
    int check = 0;
    if (turn == BLACK) tempTurn = WHITE;
    else if (turn == WHITE) tempTurn = BLACK;

    int a;
    for (a = position[1] + 1; a < 9; ++a) {
        if (cells[position[0]][a] == tempTurn) continue;
        else if (cells[position[0]][a] == turn) break;
        else if (cells[position[0]][a] == EMPTYCELL) {
            a = 0;
            break;
        }
    }
    if ((a > 0) && (a < 9)) {
        for (int k = position[1]; k < a; ++k) {
            if (k == 9) break;
            if (cells[position[0]][k] != EMPTYCELL) check++;
        }
    }

    int b;
    for (b = position[1] - 1; b > 0; --b) {
        if (cells[position[0]][b] == tempTurn) continue;
        else if (cells[position[0]][b] == turn) break;
        else if (cells[position[0]][b] == EMPTYCELL) {
            b = 10;
            break;
        }
    }
    if ((b < 9) && (b > 0)) {
        for (int k = position[1]; k > b; --k) {
            if (k == 0) break;
            if (cells[position[0]][k] != EMPTYCELL) check++;
        }
    }

    int c;
    for (c = position[0] - 1; c > 0; --c) {
        if (cells[c][position[1]] == tempTurn) continue;
        else if (cells[c][position[1]] == turn) break;
        else if (cells[c][position[1]] == EMPTYCELL) {
            c = 10;
            break;
        }
    }
    if ((c < 9) && (c > 0)) {
        for (int k = position[0]; k > c; --k) {
            if (k == 0) break;
            if (cells[k][position[1]] != EMPTYCELL) check++;
        }
    }

    int d;
    for (d = position[0] + 1; d < 9; ++d) {
        if (cells[d][position[1]] == tempTurn) continue;
        else if (cells[d][position[1]] == turn) break;
        else if (cells[d][position[1]] == EMPTYCELL) {
            d = 0;
            break;
        }
    }
    if ((d > 0) && (d < 9)) {
        for (int k = position[0]; k < d; ++k) {
            if (k == 9) break;
            if (cells[k][position[1]] != EMPTYCELL) check++;
        }
    }

    int e, f;
    for (e = position[0] + 1; e < 9;) {
        for (f = position[1] + 1; f < 9;) {
            if (cells[e][f] == tempTurn) {
                e++;
                f++;
                continue;
            } else if (cells[e][f] == turn) break;
            else if (cells[e][f] == EMPTYCELL) {
                e = 0;
                f = 0;
                break;
            }
            if ((e == 9) || (f == 9)) break;
        }
        if ((e == 9) || (f == 9)) break;
        if ((e == 0) || (f == 0)) break;
        else if (cells[e][f] == turn) break;
    }
    if ((e > 0) && (f > 0) && (e < 9) && (f < 9)) {
        for (int i = position[0]; i < e;) {
            for (int j = position[1]; j < f;) {
                if ((i == 9) || (j == 9)) break;
                if (cells[i][j] != EMPTYCELL) check++;
                i++;
                j++;
            }
        }
    }

    int g, h;
    for (g = position[0] - 1; g > 0;) {
        for (h = position[1] - 1; h > 0;) {
            if (cells[g][h] == tempTurn) {
                g--;
                h--;
                continue;
            } else if (cells[g][h] == turn) break;
            else if (cells[g][h] == EMPTYCELL) {
                g = 10;
                h = 10;
                break;
            }
            if ((g == 0) || (h == 0)) break;
        }
        if ((g == 0) || (h == 0)) break;
        if ((g == 10) || (h == 10)) break;
        else if (cells[g][h] == turn) break;
    }
    if ((g < 9) && (h < 9) && (g > 0) && (h > 0)) {
        for (int i = position[0]; i > g;) {
            for (int j = position[1]; j > h;) {
                if ((i == 0) || (j == 0)) break;
                if (cells[i][j] != EMPTYCELL) check++;
                i--;
                j--;
            }
        }
    }

    int m, n;
    for (m = position[0] + 1; m < 9;) {
        for (n = position[1] - 1; n > 0;) {
            if (cells[m][n] == tempTurn) {
                m++;
                n--;
                continue;
            } else if (cells[m][n] == turn) break;
            else if (cells[m][n] == EMPTYCELL) {
                m = 0;
                n = 10;
                break;
            }
            if ((m == 9) || (n == 0)) break;
        }
        if ((m == 9) || (n == 0)) break;
        if ((m == 0) || (n == 10)) break;
        else if (cells[m][n] == turn) break;
    }
    if ((m > 0) && (n < 9) && (m < 9) && (n > 0)) {
        for (int i = position[0]; i < m;) {
            for (int j = position[1]; j > n;) {
                if ((i == 9) || (j == 0)) break;
                if (cells[i][j] != EMPTYCELL) check++;
                i++;
                j--;
            }
        }
    }

    int o, p;
    for (o = position[0] - 1; o > 0;) {
        for (p = position[1] + 1; p < 9;) {
            if (cells[o][p] == tempTurn) {
                o--;
                p++;
                continue;
            } else if (cells[o][p] == turn) break;
            else if (cells[o][p] == EMPTYCELL) {
                o = 10;
                p = 0;
                break;
            }
            if ((o == 0) || (p == 9)) break;
        }
        if ((o == 0) || (p == 9)) break;
        if ((o == 10) || (p == 0)) break;
        else if (cells[o][p] == turn) break;
    }
    if ((o < 9) && (p > 0) && (o > 0) && (p < 9)) {
        for (int i = position[0]; i > o;) {
            for (int j = position[1]; j < p;) {
                if ((i == 0) || (j == 9)) break;
                if (cells[i][j] != EMPTYCELL) check++;
                i--;
                j++;
            }
        }
    }
    if (check > 0) return TRUE;
    else return FALSE;
}

/*Asking For NewGame*/
int newGame(char cells[9][9]) {

    int exit;

    printf("To play another game enter 1\nFor exit 2\n");
    scanf("%d", &exit);
    while ((exit != 1) && (exit != 2)) {
        fflush(stdin);
        printf("Please enter correct number :\n");
        scanf("%d", &exit);
    }
    if (exit == 1) {
        preTableDefine(cells);
        return 1;
    } else if (exit == 2) {
        return 2;
    }
}

/*Announcing Winner*/
void winPlayer(char cells[9][9]) {

    int wCount = 0;
    int bCount = 0;

    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            if (cells[i][j] == WHITE) wCount++;
            else if (cells[i][j] == BLACK) bCount++;
        }
    }

    if (wCount == bCount) printf("Game Draw\nNo One Wins\n");
    else if (wCount > bCount) printf("Player White Wins\n");
    else if (wCount < bCount)printf("Player Black Wins\n");
}