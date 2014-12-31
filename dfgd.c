    #include <stdio.h>
    #include <conio.h>
    #include <windows.h>
    COORD coord={0,0};
    void gotoxy(int x,int y);
    void loading();

    int main()
    {
        loading();
        gotoxy(11,7);
        printf("\tHANGMAN INITIALIZED . . . ");
        getch();
        return 0;
    }

    void loading()
    {
        gotoxy(10, 5);
        printf("\t\tLOADING...\n");
        int i, j;
        gotoxy(11,8);
        printf("----------------------------------\n");

        for (i=10; i<20; i++)
            {
                for(j=1; j<=9999999; j++);
                gotoxy(i, 8);
                printf("*");
            }
        for (i=20; i<30; i++)
            {
                for(j=1; j<=90000000; j++);
                gotoxy(i, 8);
                printf("*");
            }
        for (i=30; i<35; i++)
            {
                for(j=1; j<=300000000; j++);
                gotoxy(i, 8);
                printf("*");
            }

        for (i=35; i<45; i++)
            {
                for(j=1; j<=9999999; j++);
                gotoxy(i, 8);
                printf("*");
            }

        printf("\n\t      Press any key to continue...");
        getch();
    }

    void gotoxy(int x,int y)
    {
        coord.X=x;
        coord.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }
