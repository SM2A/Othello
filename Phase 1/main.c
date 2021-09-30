#include "othello.h"

#define TRUE 1
#define FALSE 0

int main() {

    char cells[9][9];
    int position[2];
    int round = 0;
    char turn;
    int end = FALSE;
    preTableDefine(cells);
    printTable(cells);

    while (round <= 256) {

        round++;
        turn = roundTurn(round);

        /*Checking Pass Situation*/
        while (possibleMove(cells, turn) == FALSE) {
            turn = roundTurn(round);
            round++;
            if (round >= 256) {
                end = TRUE;
                break;
            }
        }

        /*Show The Winner And Ask For NewGame*/
        if (end == TRUE) {
            winPlayer(cells);
            int newGameVal = newGame(cells);
            if (newGameVal == 1) {
                round = 0;
                end = FALSE;
                printTable(cells);
                continue;
            } else if (newGameVal == 2) break;
        }

        inputCheck(cells, position, turn);
        upadteGameData(position, cells, turn);
        changeCell(cells, position, turn);
        printTable(cells);

    }
    return 0;
}