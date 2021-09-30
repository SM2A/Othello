#include <stdio.h>
#include "othello.h"
#include"graphics.h"

#define EMPTYCELL '.'
#define TRUE 1
#define FALSE 0
#define WHITE 'W'
#define BLACK 'B'
#define POINTER '*'
#define RADIUS 23
#define WIDTH 730
#define HIGHT 462
#define ERROR "Please chosse correct place\n"

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
void printTable(char cells[9][9], int time) {

	int back_ground = COLOR(66, 222, 225);
	int b_pick = COLOR(35, 4, 68);
	int w_pick = COLOR(237, 130, 64);
	int line_color = COLOR(29, 77, 79);
	int point = COLOR(89, 74, 78);
	int move = COLOR(98, 16, 85);
	int bCount = 2;
	int wCount = 2;
	char wc[10];
	char bc[10];

	if (time == 1) {

	initwindow(WIDTH, HIGHT, "OTHELLO",400,150);
	setfillstyle(SOLID_FILL, back_ground);
	floodfill(0, 0, back_ground);

	for (int i = 1; i < 9; i++) {

		char a[2];
		sprintf(a, "%d", i);

		setcolor(line_color);
		line(i * 50, 50, i * 50, 450);
		line(50, i * 50, 450, i * 50);

		settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
		setbkcolor(back_ground);
		outtextxy((i * 50) + 17, 16, a);
		outtextxy(15, (i * 50) + 14, a);
	}
	line(9 * 50, 50, 9 * 50, 450);
	line(50, 9 * 50, 450, 9 * 50);
}

	for (int i = 1; i < 9;i++) {
		for (int j = 1; j < 9; j++) {
			if (cells[i][j]==WHITE) {
				setcolor(w_pick);
				circle((j * 50) + 25, (i * 50) + 25, RADIUS);
				setfillstyle(SOLID_FILL, w_pick);
				floodfill((j * 50) + 25, (i * 50) + 25, w_pick);
			}
			else if (cells[i][j] == BLACK) {
				setcolor(b_pick);
				circle((j * 50) + 25, (i * 50) + 25, RADIUS);
				setfillstyle(SOLID_FILL, b_pick);
				floodfill((j * 50) + 25, (i * 50) + 25, b_pick);
			} 
		}
	}

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (cells[i][j] == POINTER) cells[i][j] = EMPTYCELL;
		}
	}

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			setcolor(back_ground);
			circle((j * 50) + 25, (i * 50) + 25, 24);
		}
	}

	setcolor(back_ground);
	sprintf(bc, "BLACK = %d", 100);
	sprintf(wc, "WHITE = %d", 100);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	outtextxy(470, 50, bc);
	outtextxy(470, 100, wc);

	wCount = 0;
	bCount = 0;

	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			if (cells[i][j] == WHITE) wCount++;
			else if (cells[i][j] == BLACK) bCount++;
		}
	}

	settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	setcolor(back_ground);
	outtextxy(470, 200, "Please chosse correct cell");
	
	setcolor(point);
	sprintf(bc, "BLACK = %d", bCount);
	sprintf(wc, "WHITE = %d", wCount);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	outtextxy(470, 50, bc);
	outtextxy(470, 100, wc);
}

/*Check Valid Input*/
void inputCheck(char cells[9][9], int position[2], char turn) {

	int back_ground = COLOR(66, 222, 225);
	int b_pick = COLOR(35, 4, 68);
	int w_pick = COLOR(237, 130, 64);
	int indicator = COLOR(144, 48, 61);
	int error = COLOR(157, 11, 11);
	char tempTurn;
	int tempPosition;
	if (turn == BLACK) tempTurn = WHITE;
	else if (turn == WHITE) tempTurn = BLACK;

	while (TRUE) {

		setcolor(back_ground);
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
		outtextxy(470, 150, "PLAYER BLACK TURN");
		outtextxy(470, 150, "PLAYER WHITE TURN");

		char player[20];
		if (turn == BLACK) {
			setcolor(b_pick);
			sprintf(player, "PLAYER %s TURN", "BLACK");
			outtextxy(470, 150, player);
		}
		else if (turn == WHITE) {
			setcolor(w_pick);
			sprintf(player, "PLAYER %s TURN", "WHITE");
			outtextxy(470, 150, player);
		}

		setcolor(indicator);
		rectangle(63, 63, 85, 85);
		setfillstyle(SOLID_FILL, indicator);
		floodfill(75, 75, indicator);

		char place=0;
		int w = 1, s = 1, a = 1, d = 1;
		int ver = 0, hor = 0;
		int ci = 63, cj = 63;

		while (place!=' '){

			setcolor(indicator);
			rectangle(cj, ci, cj+22, ci+22);
			setfillstyle(SOLID_FILL, indicator);
			floodfill(cj+1,ci+1, indicator);

			place = getch();

			setcolor(back_ground);
			outtextxy(470, 200, "Please chosse correct cell");

			switch (place){
			case 'w':
				if (ci==63) continue;
				w++;
				break;
			case 's':
				if (ci ==413) continue;
				s++;
				break;
			case 'd':
				if (cj == 413) continue;
				d++;
				break;
			case 'a':
				if (cj == 63) continue;
				a++;
				break;
			default:
				setcolor(error);
				outtextxy(470, 200, "Please chosse correct key");
			}
			setcolor(getpixel(cj-1,ci-1));
			rectangle(cj, ci, cj + 22, ci + 22);
			setfillstyle(SOLID_FILL, getpixel(cj - 1, ci - 1));
			floodfill(cj+1, ci+1, getpixel(cj - 1, ci - 1));
			ver = s - w;
			hor = d - a;
			ci = (ver * 50) + 63;
			cj = (hor * 50) + 63;
		}
		
		position[1] = hor+1;
		position[0] = ver+1;
		
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

					}
					else {
						printf(ERROR);
						continue;
					}
				}
				else {
					printf(ERROR);
					continue;
				}
			}
			else {
				printf(ERROR);
				continue;
			}
		}
		else {
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

	int a = -1;
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

	int b = -1;
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

	int c = -1;
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

	int d = -1;
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

	int e = -1, f = -1;
	for (e = position[0] + 1; e < 9;) {
		for (f = position[1] + 1; f < 9;) {
			if (cells[e][f] == tempTurn) {
				e++;
				f++;
				continue;
			}
			else if (cells[e][f] == turn) break;
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

	int g = -1, h = -1;
	for (g = position[0] - 1; g > 0;) {
		for (h = position[1] - 1; h > 0;) {
			if (cells[g][h] == tempTurn) {
				g--;
				h--;
				continue;
			}
			else if (cells[g][h] == turn) break;
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

	int m = -1, n = -1;
	for (m = position[0] + 1; m < 9;) {
		for (n = position[1] - 1; n > 0;) {
			if (cells[m][n] == tempTurn) {
				m++;
				n--;
				continue;
			}
			else if (cells[m][n] == turn) break;
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

	int o = -1, p = -1;
	for (o = position[0] - 1; o > 0;) {
		for (p = position[1] + 1; p < 9;) {
			if (cells[o][p] == tempTurn) {
				o--;
				p++;
				continue;
			}
			else if (cells[o][p] == turn) break;
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

				if ((cells[l][v] != EMPTYCELL) || (cells[l][v] == POINTER)) continue;

				int a = -1;
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
						if (cells[l][k] != EMPTYCELL) {
							//cells[l][k] = POINTER;
							check++;
						}
					}
				}

				int b = -1;
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
						if (cells[l][k] != EMPTYCELL) {
							//cells[l][k] = POINTER;
							check++;
						}
					}
				}

				int c = -1;
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

				int d = -1;
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

				int e = -1, f = -1;
				for (e = l + 1; e < 9;) {
					for (f = v + 1; f < 9;) {
						if (cells[e][f] == tempTurn) {
							e++;
							f++;
							continue;
						}
						else if (cells[e][f] == turn) break;
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

				int g = -1, h = -1;
				for (g = l - 1; g > 0;) {
					for (h = v - 1; h > 0;) {
						if (cells[g][h] == tempTurn) {
							g--;
							h--;
							continue;
						}
						else if (cells[g][h] == turn) break;
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

				int m = -1, n = -1;
				for (m = l + 1; m < 9;) {
					for (n = v - 1; n > 0;) {
						if (cells[m][n] == tempTurn) {
							m++;
							n--;
							continue;
						}
						else if (cells[m][n] == turn) break;
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

				int o = -1, p = -1;
				for (o = l - 1; o > 0;) {
					for (p = v + 1; p < 9;) {
						if (cells[o][p] == tempTurn) {
							o--;
							p++;
							continue;
						}
						else if (cells[o][p] == turn) break;
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
	}
	else {
		return FALSE;
	}
}

/*Check If Chossen Place Can Revers Any Achate*/
int possiblePlace(char cells[9][9], int position[2], char turn) {

	char tempTurn;
	int check = 0;
	if (turn == BLACK) tempTurn = WHITE;
	else if (turn == WHITE) tempTurn = BLACK;

	int a = -1;
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

	int b = -1;
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

	int c = -1;
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

	int d = -1;
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

	int e = -1, f = -1;
	for (e = position[0] + 1; e < 9;) {
		for (f = position[1] + 1; f < 9;) {
			if (cells[e][f] == tempTurn) {
				e++;
				f++;
				continue;
			}
			else if (cells[e][f] == turn) break;
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

	int g = -1, h = -1;
	for (g = position[0] - 1; g > 0;) {
		for (h = position[1] - 1; h > 0;) {
			if (cells[g][h] == tempTurn) {
				g--;
				h--;
				continue;
			}
			else if (cells[g][h] == turn) break;
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

	int m = -1, n = -1;
	for (m = position[0] + 1; m < 9;) {
		for (n = position[1] - 1; n > 0;) {
			if (cells[m][n] == tempTurn) {
				m++;
				n--;
				continue;
			}
			else if (cells[m][n] == turn) break;
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

	int o = -1, p = -1;
	for (o = position[0] - 1; o > 0;) {
		for (p = position[1] + 1; p < 9;) {
			if (cells[o][p] == tempTurn) {
				o--;
				p++;
				continue;
			}
			else if (cells[o][p] == turn) break;
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
	scanf_s("%d", &exit);
	while ((exit != 1) && (exit != 2)) {
		fflush(stdin);
		printf("Please enter correct number :\n");
		scanf_s("%d", &exit);
	}
	if (exit == 1) {
		preTableDefine(cells);
		return 1;
	}
	else if (exit == 2) {
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