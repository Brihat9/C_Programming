#include "ttt_v2.h"

int main(void) {
	loading(); // display the loading animation

	system("cls");
	system("COLOR F0"); // set black text on white background

	srand(time(NULL)); // seed the randomizer

	main_menu(); // show the main menu

	return 0;
}

void gotoxy(int x, int y) {
	COORD coord={0,0}; 		// center of axis is set to (0,0)
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void gotoyx(int y, int x) {
	printf("%c[%d;%df", 0x1B, y, x);
}

void main_menu(void) {
	system("cls");                             // print the header & footer
	print_heading();
	print_footer("Press [Esc] to quit");

	int diff = difficulty();

	gotoxy(0, 5);
	printf("%s",
			"    MAIN MENU | Choose an option                           \n"
			"                                                           \n"
			"     [1]  Play the game                                   \n"
			"     [2]  Rules of the game                               \n");
	printf( "     [3]  Difficulty: %s \n", difficulty_str(diff));
	printf("%s",
			"     [4]  How to play                                      \n"
			"     [5]  Highscores                                       \n"
			"     [6]  About                                            \n");

	char choice = getch();
	switch (choice) {
		case '1': play(); break;
		case '2': rules(); break;
		case '4': how_to_play(); break;
		case '5': highscores(diff); break;
		case '6': about_program(); break;
		case '3': change_difficulty(); main_menu(); break;
		case ESC: exit(0);
		default:  main_menu(); break;
	}
}

void print_heading(void) {
	gotoxy(0, 2);
	printf("%s",
		"    TIC-TAC-TOE                           by MANISH & BRIHAT    \n"
		"  ============================================================  \n");
}

void print_footer(char* str) {
	gotoxy(0, 21); printf("  ------------------------------------------------------------ ");
	gotoxy(0, 22); printf("    %-50s %5s", str, "M&B");
}

char ch(int i) {
	switch (i) {
		case 1: return 'X';
		case 0: return ' ';
		case -1: return 'O';
		default: return '\0';
	}
}

void print_board(int x, int y, int d[9]) {
	gotoxy(x, y+0); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ');
	gotoxy(x, y+1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',ch(d[0]),' ',' ',VCH,' ',' ',ch(d[1]),' ',' ',VCH,' ',' ',ch(d[2]),' ',' ');
	gotoxy(x, y+2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ');
	gotoxy(x, y+3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", HCH,HCH,HCH,HCH,HCH,CCH,HCH,HCH,HCH,HCH,HCH,CCH,HCH,HCH,HCH,HCH,HCH);
	gotoxy(x, y+4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ');
	gotoxy(x, y+5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',ch(d[3]),' ',' ',VCH,' ',' ',ch(d[4]),' ',' ',VCH,' ',' ',ch(d[5]),' ',' ');
	gotoxy(x, y+6); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ');
	gotoxy(x, y+7); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", HCH,HCH,HCH,HCH,HCH,CCH,HCH,HCH,HCH,HCH,HCH,CCH,HCH,HCH,HCH,HCH,HCH);
	gotoxy(x, y+8); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ');
	gotoxy(x, y+9); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',ch(d[6]),' ',' ',VCH,' ',' ',ch(d[7]),' ',' ',VCH,' ',' ',ch(d[8]),' ',' ');
	gotoxy(x, y+10); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ',VCH,' ',' ',' ',' ',' ');
	printf("\n\n");
}

void about_program(void) {
	system("cls");
	print_heading();
	print_footer("Press [Esc] to goto Main Menu");

	gotoxy(0, 5);
	printf("%s",
		"    ABOUT THIS PROGRAM:                                       \n"
		"                                                              \n"
		"    TIC-TAC-TOE is a small console-based mind-game developed \n"
		"    by Brihat Ratna Bajracharya (070-BCT-513) and Manish    \n"
		"    Munikar (070-BCT-520) as a mini-project in the first    \n"
		"    semester at Pulchowk Campus, IOE.                       \n"
		"                                                              \n"
		"    Find Brihat @ facebook.com/...                          \n"
		"    Find Manish @ facebook.com/manish.munikar               \n");

	while(getch() != ESC);
	main_menu();
}

void rules(void) {
	system("cls");
	print_heading();
	print_footer("Press [Esc] to goto Main Menu");

	gotoxy(0,5);
	printf("%s",
		"    RULES OF TIC-TAC-TOE                                      \n"
		"                                                              \n"
		"    1.  asdfasdfasfasfd                                       \n"
		"    2.  asdfasfasdfasf                                        \n"
		"    10. asldjfaslkfaslkdfjaslkdfj                             \n");

	while (getch() != ESC);

	main_menu();
}

void highscores(int dif) {
// function to display the highscores of a particular difficult level

	system("cls");
	print_heading();
	print_footer("Press [Esc] to goto Main Menu");
	gotoxy(0,5);

	FILE *fp;
	fp = fopen("scores", "r"); // open the 'scores' file

	// if file not found, display an error message
	if (fp == NULL) {
		printf("    ERROR: Record file not found! ");
		getch(); main_menu();
	}

	int n = line_count(fp);  // number of lines (or entries) in the 'scores' file
	rewind(fp);		// bring the cursor back to the beginning of file (after counting the lines)

	// save all the lines of the file into an array and split each line with '|' into corresponding data[].name, data[].score, and data[].diff
	char line_str[n][35], name[31];
	int len, score;
	RECORD data[n]; // array of records
	int	i, j;
	for (i=0; i<n; i++) {
		fgets(line_str[i], sizeof(line_str[i]), fp); 	// get a line from the file
		len = strlen(line_str[i]);						// calculates the length of line
		line_str[i][len-1] = '\0'; 						// convert the last character of line_string from '\n' to '\0' (required)

		// split the line with '|' using string-token function
		strcpy(data[i].name, strtok(line_str[i], "|"));				// 1st part of line is name
		data[i].score = (int) strtol(strtok(NULL, "|"), NULL, 10);	// 2nd part of line is score
		data[i].diff = (int) strtol(strtok(NULL, "|"), NULL, 10);	// 3rd part of line is difficulty
	}

	// sort the records in descending order of score
	for (i=0; i<n; i++) {
		for (j=i; j<n; j++)
			if (data[j].score > data[i].score)
				swap_record(&data[i], &data[j]);
	}

	// display the sorted list of top 10

	char d[7];
	strcpy(d, difficulty_str(dif));

	printf("    HIGHSCORES | %-9s  (Press [D] to change difficulty)\n\n", d);
	printf("      %4s %-25s %5s \n", "RANK", "NAME", "SCORE");
	printf("      ------------------------------------- \n");
	int count = 0;
	for (i=0; i<n && count<10; i++) {
		if (data[i].diff == dif) {
			printf("      %3d. %-25s %5d \n", count+1, data[i].name, data[i].score);
			++count;
		}
	}

	fclose(fp); // close the file

	int c;
	while ((c=getch()) != ESC) {		 // if user presses ESC, goto main menu
		if (c=='d') {					// if user presses [D], then show highscores of another difficulty
			if (dif== 0) highscores(1);
			else if (dif==1) highscores(2);
			else if (dif==2) highscores(0);
		}
	}
	main_menu();
}

int line_count(FILE *file) {
// function to count the number of lines (records) in a file
	rewind(file);

	int n = 0;
	while(!feof(file))
		if (fgetc(file) == '\n') n++;
	return n;

	rewind(file);
}

void swap_record(RECORD *R1, RECORD *R2) {
	RECORD temp;
	temp = *R1;
	*R1 = *R2;
	*R2 = temp;
}

void multi_player(void) {
// the page when user selets 'Play against human'

	system("cls");
	print_heading();
	print_footer("Press [Esc] to goto Main Menu");
	gotoxy(0,5);

	char player[3][31]; // Player[0] will be O's name... player[-1+1]
						// player[2] will be X's name... player[ 1+1]

	// ask players' name, if invalid, goto previous screen
	printf("\n    Enter Player 'O' name: "); strin(player[0], sizeof(player[0]), stdin);
	if (strlen(player[0])<1) {
		printf("\n    INVALID NAME!"); getch(); play();
	}

	printf("\n    Enter Player 'X' name: "); strin(player[2], sizeof(player[2]), stdin);
	if (strlen(player[2]) < 1) {
		printf("\n    INVALID NAME!"); getch(); play();
	}

	// initialize turn randomly. Once initialized, the turn will alternate
	int turn_array[2]={-1, 1};
	int turn = turn_array[rand()%2];

	start_multiplayer(turn, player); // begin the multiplayer game

	while(getch() != ESC); // if the user presses [Esc], goto previous screen
	play();
}

void start_multiplayer(int init_turn, char player[3][31]) {
	int turn_start = init_turn;
	int wins[3]={0,0,0}, draws=0; // initializing the number of wins and draws

	// while user wants to play new game (after completing one game)
	int newgame=1;
	while (newgame==1) {
		int board[9] = {0,0,0,0,0,0,0,0,0}; // initialize board before every game

		int turn = turn_start;
		int c, pos=0, moves=0;

		multiplayerUI(board, turn, moves, player); // show the current board, and turn/win/draw

		int x=22, y=6; // this is necessary for arrow controls
		gotoxy(x, y);

		int ask=1;
		while (ask==1 && (c=getch())) {
			if (c==ESC) 				{ status(player, wins, draws); } // if [Esc], show the current game status
			else if (c==UP && y>6) 		{ gotoxy(x, y-=4); pos-=3; }
			else if (c==DOWN && y<14) 	{ gotoxy(x, y+=4); pos+=3; }
			else if (c==LEFT && x>22) 	{ gotoxy(x-=6, y); pos--; }
			else if (c==RIGHT && x<34) 	{ gotoxy(x+=6, y); pos++; }

			else if (c==ENTER && board[pos]==0 && moves<9) {
				board[pos]=turn; 	// if user presses [Enter] in blank spot, play that move
				turn *= -1;			// and then change the turn
				moves++;			// and increase the moves count
			}

			multiplayerUI(board, turn, moves, player);	// show the board and turn/win/draw
			gotoxy(x, y);

			// after every move, check if its game-over
			int winner;
			if (winner=iswon(board)) {
				wins[winner+1]++;
				newgame=1; ask=0;
				turn_start *= -1;
				getch();
			}

			if (moves==9 && iswon(board)==0) {
				draws++;
				newgame=1; ask=0;
				turn_start *= -1;
				getch();
			}
		}
	}
}

void strin(char *str, int maxlen, FILE *file) {
// inputs the string (including spaces) upto \n and converts the last \n into \0, and stores it in a char*
	fgets(str, maxlen, file);
	int len = strlen(str);

	if (len>0 && str[len-1]=='\n')
		str[len-1] = '\0';
}

void play(void) {
// the 'Play the game' page
	system("cls");
	print_heading();
	print_footer("Press [Esc] to goto Main Menu");

	gotoxy(0, 5);
	printf("%s",
		"    CHOOSE GAME MODE:                                          \n"
		"                                                               \n"
		"      [1] Play against computer (Single-Player)                \n"
		"      [2] Play against human    (Multi-Player)                 \n");

	char c = getch();
	switch (c) {
		case ESC: main_menu(); break;
		case '1': single_player(); break;
		case '2': multi_player(); break;
		default:  play(); break;
	}
}

void single_player(void) {
	system("cls");
	print_heading();
	print_footer("Press [Esc] to go back");

	// ask the player's name. The AI player's name will be "COMPUTER"
	char name[31], player[3][31];
	gotoxy(0,5); printf("    Enter your name: "); strin(name, sizeof(name), stdin);
	if (strlen(name)<1) {
		printf("\n    INVALID NAME");
		getch();
		play();
	}

	gotoxy(0,7); printf("%s", "    [1] Play with O \n"
							  "    [2] Play with X \n");
	int ask=1, c, human;
	while (ask==1 && (c=getch())) {
		if (c=='1') {
			human = -1;
			strcpy(player[0], name);
			strcpy(player[2], "COMPUTER");
			ask=0;
		}
		else if (c=='2') {
			human = 1;
			strcpy(player[0], "COMPUTER");
			strcpy(player[2], name);
			ask=0;
		}
		else if (c==ESC) play();
	}

	// initialize the turn randomly. Once initialized, the turn will alternate
	int turn_array[2]={1,-1};
	int init_turn = turn_array[rand() % 2];

	start_singleplayer(player, human, init_turn);

}

void start_singleplayer(char player[3][31], int human, int init_turn) {
	int computer = human *-1;
	int turn_start = init_turn;
	int wins[3]={0,0,0}, draws=0, diff=difficulty();

	int newgame=1;
	while (newgame==1) {
		int board[9]={0,0,0,0,0,0,0,0,0};
		int c, pos=0, moves=0;
		int turn = turn_start;

		singleplayerUI(board, moves, turn, human);

		int x=22, y=6;
		gotoxy(x,y);

		int ask=1;
		while (ask==1) {
			if (turn==human && moves<9 && iswon(board)==0) {
				c = getch();
				if (c==ESC)               {
					int score = wins[human+1] - wins[computer+1];
					save_record(player[human+1], score, difficulty());
					status(player, wins, draws);
				}
				else if (c==UP && y>6)    { y -= 4; pos -= 3; }
				else if (c==DOWN && y<14) { y+=4; pos+=3; }
				else if (c==LEFT && x>22) { x-=6; pos-=1; }
				else if (c==RIGHT && x<34) { x+=6; pos+=1; }
				else if (c==ENTER && board[pos]==0) {
					board[pos] = human;
					turn *= -1;
					moves++;
				}
			}
			else if (turn==computer && moves<9 && iswon(board)==0) {

				int j;
				for (j=0; j<300000000; j++); // delay for a second

				int bestMove = computer_move(board, human);
				board[bestMove]=computer;
				turn *= -1;
				moves++;
			}

			singleplayerUI(board, moves, turn, human);
			gotoxy(x, y);

			int winner;
			if (winner=iswon(board)) {
				wins[winner+1]++;
				newgame=1; ask=0;
				turn_start *= -1;
				getch();
			}

			if (moves==9 && iswon(board)==0) {
				draws++;
				newgame=1; ask=0;
				turn_start *= -1;
				getch();
			}
		}
	}
}

int iswon(int d[9]) {
	// possible winning positions
	int wins[8][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };

	int i;
	for (i=0; i<8; i++) {
		if (d[wins[i][0]] != 0 && d[wins[i][1]] == d[wins[i][0]] && d[wins[i][2]] == d[wins[i][0]] )
			return d[wins[i][0]];
	}

	return 0;
}

int difficulty(void) {
	FILE *df = fopen("difficulty", "r");
	if (df == NULL) return 0;

	int d;
	fscanf(df, "%d", &d);

	if (d==1 || d==2) return d;
	return 0;
}

char *difficulty_str(int diff) {
	switch (diff) {
		case 0: return "Easy"; break;
		case 1: return "Medium"; break;
		case 2: return "Hard"; break;
		default: return NULL;
	}
}

void change_difficulty(void) {
	int diff = difficulty();

	switch (diff) {
		case 0: diff=1; break;
		case 1: diff=2; break;
		case 2: diff=0; break;
	}

	FILE *df = fopen("difficulty", "w");
	fprintf(df, "%d", diff);
	fclose(df);
}

void status(char player[3][31], int wins[3], int draws) {
	system("cls");
	print_heading();
	print_footer("Press [Esc] to goto Main Menu");

	gotoxy(0,5);
	printf("    LAST GAME STATUS: \n\n");
	printf("      %-20s : %3d \n", player[0], wins[0]);
	printf("      %-20s : %3d \n", player[2], wins[2]);
	printf("      %-20s : %3d \n", "DRAWS", draws);

	while (getch() != ESC);
	main_menu();
}

void multiplayerUI(int board[9], int turn, int moves, char player[3][31]) {
	system("cls");
	print_heading();
	print_footer("Press [Esc] to end the game");

	print_board(20,5, board);

	gotoxy(20, 18);

	int winner;
	if (winner=iswon(board))
		printf("%s (%c) WINS! Press any key...", player[winner+1], ch(winner));

	else if (moves==9)
		printf("A DRAW! Press any key...");

	else
		printf("%s's turn (%c)", player[turn+1], ch(turn));
}

void how_to_play(void) {
	system("cls");
	print_heading();
	print_footer("Press [Esc] to goto Main Menu");

	gotoxy(0,5);
	printf("%s",
			"    HOW TO PLAY:           \n"
			"                           \n"
			"    asdfajslkf;jasldkfsalf \n");

	while (getch() != ESC);
	main_menu();
}

void singleplayerUI(int board[9], int moves, int turn, int human) {
	system("cls");
	print_heading();
	print_footer("Press [Esc] to end the game");

	print_board(20,5,board);

	gotoxy(20,18);

	int winner;
	if (winner = iswon(board)) {
		if (winner==human) printf("CONGRATULATION! YOU WIN!");
		else printf("BOOO! YOU LOSE! Better luck next time!");
	}
	else if (moves==9)
		printf("A DRAW! Press any key...");
	else {
		if (turn==human) printf("Your turn");
		else printf("COMPUTER's turn");
	}

}

int computer_move(int board[9], int human) {
	int computer = human * -1;
	int diff = difficulty();

	// start at random
	if (empty_board(board)) return (rand() % 9);

	// check if there is winning move
	int i;
	for (i=0; i<9; i++) { // for all the positions
		if (board[i]==0) { // if the position is empty
			board[i] = computer; // try the move
			if (iswon(board) == computer) {
				board[i] = 0;
				return i;
			}
			board[i] = 0;
		}
	}

	// for medium difficulty, check if there is blocking move
	if (diff >= 1) {
		for (i=0; i<9; i++) {
			if (board[i] == 0) {
				board[i] = human;
				if (iswon(board) == human) {
					board[i] = 0;
					return i;
				}
				board[i] = 0;
			}
		}
	}

	// for hard difficulty, make the computer unbeatable
	int bestMove, best = -2;
	if (diff >= 2) {
		for (i=0; i<9; i++) {
			if (board[i]==0) {
				board[i] = computer;
				int score = minimax(board, human, human);
				board[i] = 0;

				if (score > best) {
					best = score;
					bestMove = i;
				}
			}
		}
		return bestMove;
	}

	// or place anywhere in the blank spot
	int blank[9] = {0,0,0,0,0,0,0,0,0};
	int blank_count = 0;
	for (i=0; i<9; i++)
		if (board[i] == 0)
			blank[blank_count++] = i;
	return blank[rand() % blank_count];
}

int maximum(int a, int b) {
	int m = (a>b)? a:b;
	return m;
}

int minimum(int a, int b) {
	int m = (a<b)? a:b;
	return m;
}

int maximize(int board[9], int player, int human) {
	int computer = human * -1;
	// if it is terminal node, return the heuristic values
	// 1 for computer win
	// -1 for human win
	// 0 for draw

	if (iswon(board) == computer) return 1;
	else if (iswon(board) == human) return -1;
	else if (filled(board)==1 && iswon(board)==0) return 0;

	int v = -2;
	int index;
	for (index=0; index<9; ++index) {
		if (board[index] == 0) {
			board[index] = player;
			int result = minimize(board, player*-1, human);
			board[index] = 0;

			v = maximum(v, result);
		}
	}

	return v;
}

int minimize(int board[9], int player, int human) {
	int computer = human * -1;
	// check if it is terminal node

	if (iswon(board) == computer) return 1;
	else if (iswon(board) == human) return -1;
	else if (filled(board)==1 && iswon(board)==0) return 0;

	int v = 2;
	int index;
	for (index=0; index<9; index++) {
		if (board[index] == 0) {
			board[index] = player;
			int result = maximize(board, player*-1, human);
			board[index] = 0;

			v = minimum(v, result);
		}
	}
	return v;

}

int minimax(int board[9], int player, int human) {
	int computer = human * -1;

	// check if its the terminal node
	if (iswon(board) == computer) return 1;
	else if (iswon(board) == human) return -1;
	else if (filled(board) && !iswon(board)) return 0;

	int bestScore;
	if (player == computer) bestScore = -2;
	else if (player == human) bestScore = 2;

	int i;
	for (i=0; i<9; i++) {
		if (board[i] == 0) {
			board[i] = player;
			int score = minimax(board, player*-1, human);
			board[i] = 0;

			if (player == computer)
				bestScore = maximum(bestScore, score);
			else if (player == human)
				bestScore = minimum(bestScore, score);
		}
	}

	return bestScore;
}

int negamax(int board[9], int player) {
	// check if terminal node
	if (iswon(board)) return iswon(board)*player;
	else if (filled(board) && !iswon(board)) return 0;

	int best = -2;
	int i;
	for (i=0; i<9; i++) {
		if (board[i] == 0) {
			board[i] = player;
			int score = -negamax(board, player*-1);
			board[i] = 0;

			best = maximum(best, score);
		}
	}

	return best;
}

int filled(int board[9]) {
	int full = 1;
	int i;
	for (i=0; i<9; i++)
		if (board[i] == 0) full = 0;

	return full;
}

int empty_board(int board[9]) {
	int emp = 1;
	int i;
	for (i=0; i<9; i++)
		if (board[i] != 0) emp = 0;

	return emp;
}

void save_record(char name[31], int score, int diff) {
	FILE *file = fopen("scores", "a");

	fprintf(file, "%s|%d|%d\n", name, score, diff);

	fclose(file);
}

void loading(void) {
	system("COLOR 0F");

	int step = 10;

	int i,j;
	for (i=0; i<10; i++) {
		for (j=0; j<100000000; j++); // delay one second

		system("cls");
		gotoxy(20,9); printf("Loading...     %3d%c", step*(i+1), '%');

		for (j=0; j<10; j++) {
			gotoxy(20+j*2, 11); printf("%c%c", 196, 196);
		}

		for (j=0; j<=i; j++) {
			gotoxy(20+j*2, 11); printf("%c%c", 219, 219);
		}
	}

	for (i=0; i<200000000; i++);
	system("cls");
	gotoxy(20,9); printf("Press any key...");
	getch();
}

char* sCase(char *str, int c) {
	int i;
	for (i=0; i<strlen(str); i++) {
		if (isalpha(str[i])) {
			if (c==0)
				str[i] = tolower(str[i]);
			else if (c==1)
				str[i] = toupper(str[i]);
		}
	}

	return str;
}

;
