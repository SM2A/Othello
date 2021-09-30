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