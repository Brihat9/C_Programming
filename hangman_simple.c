    #include <stdio.h>
    #include <conio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    #include <windows.h>
    #include <ctype.h>

    // This is the function to make gotoxy() work in CodeBlocks
    COORD coord={0,0};

    void display_loading();
    void title_block();
    void gotoxy(int x,int y);
    void display_heading();
    int tryagain();
    void game_lost();
    void bye();

    int main(void)
    {
    title_block();
    display_loading();

	start:                      // This is the randomizer in C
	srand(time(NULL));
	int random = rand() % 20;	// random ranges from 0 to 9
	int 	x,					// for gotoxy function
			y,					// "
			i, 				    // for 'FOR' loop
			length, 			// length of word (with spaces)
			a_count=0,		    // number of chosen alphabets
			spaces=0, 		    // number of spaces in the word
			chosenornot, 	    // a flag to check whether an alphabet is already chosen
			j, 				    // for 'FOR' loop
			right, 			    // number of correct alphabets
			start=1, 		    // game only runs when start=1
			mistake=0;		    // number of incorrect choices = a_count - right

	char *words[20] = {	        "AFGHANISTAN",
								"NEPAL",
								"UNITED STATES",
								"INDIA",
								"NORWAY",
								"CHINA",
								"DENMARK",
								"ENGLAND",
								"JAPAN",
								"BRAZIL",
								"KENYA",
								"FRANCE",
								"CZECH REPUBLIC",
								"RUWANDA",
								"WALES",
								"MEXICO",
								"CANADA",
								"ANGOLA",
								"HUNGARY",
								"AUSTRIA"	};
	char *word = words[random];
	length = strlen(word);

	startsame:


	system("cls");
    display_heading();

	x=5; y=7;
	gotoxy(x, y);
    for (i=0; i<length; i++)
        {
			if (word[i] == ' ')
                {
                    printf("  "); spaces++;
                }
			else
                printf("_ ");
		}

	char ch, chosen[26]={};
	a_count=0;
	while (start==1 && (ch=getch()) != 13)
        {
		// check if entered alphabet is chosen or not
		chosenornot = 0;
		for (i=0; i<=a_count; i++)
            {
                if (toupper(ch) == chosen[i])
                    {
                        chosenornot=1;
                    }
            }

		// if not chosen then proceed
		if (chosenornot != 1)
            {
                system("cls");
                display_heading();
                gotoxy(x, y);
                chosen[a_count] = toupper(ch);
                a_count++;
                for (i=0; i<length; i++)
                {
					if (word[i] == ' ')
                        printf("  ");
					else
                        printf("_ ");
                }

                right = 0;
                for (i=0; i<length; i++)
                    {
                        for (j=0; j<a_count; j++)
                        {
                            if (word[i] == chosen[j])
                            {
                                gotoxy(x+(i*2), y);
                                printf("%c", word[i]);
                                right++;
                            }
                        }
                    }
                mistake = a_count - right;

                if (mistake == 10)
                {
                    game_lost();
                    if (tryagain())
                        goto startsame;
                    else
                        bye();
                }
                else
                {
                    gotoxy(x, y+2);
                    printf("%i chances left", 10-mistake);
                }

                if (right == (length-spaces))
                {
                    gotoxy(x, y+4);
                    printf("Congrats, you win!");
                    if (tryagain())
                        goto start;
                    else
                        bye();
                }
            }
            else
                {
                    gotoxy(x, y+4);
                    printf("Already chosen!");
                }
        }
        return 0;
    }

    void display_loading()
    {
                    int i, j, k=17,l=25;
                    gotoxy(38, 16);
                    printf("LOADING...\n");

                    gotoxy(25,k);
                    printf("-----------------------------------");

                    for (i=l; i<l+10; i++)
                        {
                        for(j=1; j<=9999999; j++);
                            gotoxy(i, k);
                            printf("*");
                        }
                    for (i=l+10; i<l+20; i++)
                        {
                            for(j=1; j<=90000000; j++);
                            gotoxy(i, k);
                            printf("*");
                        }
                    for (i=l+20; i<l+25; i++)
                        {
                            for(j=1; j<=300000000; j++);
                            gotoxy(i, k);
                            printf("*");
                        }

                    for (i=l+25; i<l+35; i++)
                        {
                            for(j=1; j<=9999999; j++);
                            gotoxy(i, k);
                            printf("*");
                        }
                    gotoxy(33,16);
                    printf("HANGMAN INITIALIZED");
                    gotoxy(28, 18);
                    printf("Press any key to continue ...");
                    getch();
                }


    void title_block()
    {
        printf("\n");
        printf("   HH      HH  AAAAAAAA  NN       NN GGGGGGGGGG MM       MM  AAAAAAAA  NNN      NN \n");
        printf("   HH      HH AA      AA NNN      NN GG       G MMM     MMM AA      AA NNN      NN \n");
        printf("   HH      HH AA      AA NNNN     NN GG         MM M   M MM AA      AA NNNN     NN \n");
        printf("   HH      HH AA      AA NN NN    NN GG         MM  M M  MM AA      AA NN NN    NN \n");
        printf("   HH      HH AA      AA NN  NN   NN GG         MM   M   MM AA      AA NN  NN   NN \n");
        printf("   HHHHHHHHHH AAAAAAAAAA NN   N   NN GG  GGGGGG MM       MM AAAAAAAAAA NN   N   NN \n");
        printf("   HH      HH AA      AA NN   NN  NN GG      GG MM       MM AA      AA NN   NN  NN \n");
        printf("   HH      HH AA      AA NN    NN NN GG      GG MM       MM AA      AA NN    NN NN \n");
        printf("   HH      HH AA      AA NN     NNNN GG      GG MM       MM AA      AA NN     NNNN \n");
        printf("   HH      HH AA      AA NN      NNN GG      GG MM       MM AA      AA NN      NNN \n");
        printf("   HH      HH AA      AA NN       NN GGGGGGGGGG MM       MM AA      AA NN       NN \n");

        gotoxy(37,22);
            printf("Project by:");
        gotoxy(37,23);
            printf(" BCT 2070");
    }

    void display_heading()
    {
        printf("\n *** WELCOME TO HANGMAN PROGRAM ***\n\n");
        printf(" Press ENTER to exit\n\n");
        printf(" The following word is a country");
    }

    int tryagain()
    {
        char yesno;
        printf("\n\n Try again? (y/n) ");
        do
        {
            yesno = getch();
        }while (yesno != 'y' && yesno != 'n');
        switch (yesno)
        {
            case 'y': return 1;
            case 'n': return 0;
        }
    }

    void game_lost()
    {
        printf("\n\n You lost!");
    }

    void bye()
    {
        printf("\n\n Thanks for playing. Press any key to exit");
        getch();
        exit(0);
    }

    void gotoxy(int x,int y)
    {
        coord.X=x;
        coord.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }
