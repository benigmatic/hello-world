

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>
#define ROWS 5
#define COLS 5
#define FREE 2
#define SCALE 15
#define SHIFT 1
#define MAXVAL 75
#define FALSE 0
#define TRUE 1
#define MINVAL 1
#define VALUES 25
#define B 0
#define I 1
#define N 2
#define G 3
#define O 4
#define DOB 'X'
#define BINGO 5
void welcomeScreen();
void displayExplicitCard();
void clearScreen();
void displayCard();
void displayRandomCard();
void fillCardRand (int array[ROWS][COLS], int used[MAXVAL]);
void setValue (int array[ROWS][COLS],int r, int c, int used[MAXVAL]);
void displayBingoCard (int array[ROWS][COLS]);
void initializeArray (int used[MAXVAL],int called[MAXVAL],char result[ROWS][COLS]);
void play (int card[ROWS][COLS],int called[MAXVAL], char result [ROWS][COLS]);
// add initialization;
void displayNumber(char letter,int number);
 void checkNumber( char letter,int number, int card[ROWS][COLS],char result [ROWS][COLS] );
int callNumber (int called[MAXVAL]);
void displayBingoCardPlay(int card[ROWS][COLS],char result[ROWS][COLS]);
 bool horizontalLine(char result[ROWS][COLS]);
// MAIN FUNCTION
int main()
{
    int card [ROWS][COLS];
    int used [MAXVAL];
    int called [MAXVAL];
    char result [ROWS][COLS];
   srand( time(0)) ;
    welcomeScreen();

    clearScreen();

//  displayExplicitCard();
//clearScreen();
//  displayCard();
//   clearScreen();
//   displayRandomCard();
   // update part 4
//   clearScreen();
  initializeArray (used,called,result);
   fillCardRand(card,used);
 displayBingoCard(card);
   play(card,called,result );

    return 0;
}


void welcomeScreen()
{
    // prints the welcome screen
    printf("\t\t\t\t\t\t    WELCOME TO ... \n \n \n");
    printf("\t\t\t\t\t BBBBB   II  NN     NN    GGGGG     OOOO   |\n");
    printf("\t (\\ /) \t\t\t\t BB  BB  II  NN N   NN  GG         OO  OO  |\n");
    printf("\t ( ^.^) \t\t\t BBBB    II  NN  N  NN  GG         OO  OO  |\n");
    printf("\t C\(\"\)\(\"\)\t\t\t BB  BB  II  NN   N NN  GG   GGGG  OO  OO  |\n");
    printf("\t\t\t\t\t BBBBb   II  NN     NN    GGGGG     OOOO   .\n");


    printf("\n \t\t\t\t\t\t\RULES OF THE GAME: \n\n 1. A player receives a BINGO CARD\n 2. Each card has a random placement of numbers for each column, B, I, N, G, O");
    printf("\n \t Column B contains values 1-15\n\t Column I contains values 16-30");
    printf("\n\t Column N contains values 31 - 45 in addition to a FREE space");
    printf("\n\t Column G contains values 46-60\n\t Column O contains values 61 - 75");
    printf(" 3. Various patterns are identified to accomplish a BINGO\n 4. Each round of the game will identify which pattern should be accomplished to win a BINGO");
    printf("\n 5. Winning numbers are randomly selected during play\n 6. GOOD LUCK TO YOU!");
}


 void clearScreen(){
 char letter;
 printf("\n\t\t\t\t\t\t HIT <ENTER> TO CONTINUE... \n");
 scanf("%c",&letter);


    //Windows
 system("cls");
    // Unix
        //system ("clear");
 }


 void displayExplicitCard()
 {   printf ("Function displayExplicitCard\n");
     printf("\t\t\t\t | ========================================== |\n");
     printf("\t\t\t\t |     B   |   I   |   N    |   G    |   O    |\n");
     printf("\t\t\t\t | ------------------------------------------ |\n");
     printf("\t\t\t\t |    15   |   17  |   34   |   48   |   63   |\n");
     printf("\t\t\t\t | ------------------------------------------ |\n");
    printf ("\t\t\t\t |    3    |   24  |   44   |   46   |   67   |\n");
     printf("\t\t\t\t | ------------------------------------------ |\n");
    printf ("\t\t\t\t |    5    |   23  |  FREE  |   55   |   68   |\n");
     printf("\t\t\t\t | ------------------------------------------ |\n");
    printf ("\t\t\t\t |    4    |   22  |   40   |   53   |   70   |\n");
     printf("\t\t\t\t | ------------------------------------------ |\n");
    printf ("\t\t\t\t |    10   |   21  |   41   |   54   |   72   |\n");
     printf("\t\t\t\t | ========================================== |\n");

 }

 void displayCard(){
  int row;
  int col;
  int num=15;
    printf("Function displayCard\n");
    printf("\t\t\t\t| ========================================== |\n");
    printf("\t\t\t\t|     B   |   I   |   N    |   G    |   O    |\n");
    printf("\t\t\t\t| ------------------------------------------ |\n");
    for (row=0;row<ROWS ; row++){
printf("\t\t\t\t");
        for (col=0; col<COLS ; col++){

       if(row== FREE && col==FREE){
          printf("|  FREE  ");}
          else{ printf("|   %d   ",num);}
        num= num+ SCALE;

        } num = 15 - (row+1);

        printf("|\n");
         printf("\t\t\t\t| ------------------------------------------ |\n");
    }
 }
void displayRandomCard(){

    int row;
    int col;
    int num;
    int base = 1;
        printf("Function displayRandomCard\n");
    printf("\t\t\t\t| ========================================== |\n");
    printf("\t\t\t\t|     B   |   I   |   N    |   G    |   O    |\n");
    printf("\t\t\t\t| ------------------------------------------ |\n");
     for (row=0;row<ROWS ; row++){
printf("\t\t\t\t");
        for (col=0; col<COLS ; col++){
num= rand()% 15 + base;
base = base + SCALE;
       if(row== FREE && col==FREE){
          printf("|  FREE  ");}
          else if (num<=9){
            printf("|   %d    ",num);

          }
          else {
             printf("|   %d   ",num);

          }
        }
 base = 1;

        printf("|\n");
         printf("\t\t\t\t| ------------------------------------------ |\n");

     }}

void fillCardRand (int array[ROWS][COLS], int used[MAXVAL]) {
 int row;
    int col;
 for ( row=0;row<5;row++)
{
    for (col=0; col<5;col++){
     if ((row==2)&& (col==2))
        { int num =0;}
     else {
        setValue (array,row,col,used);

     }
    }
}
}

void displayBingoCard (int array[ROWS][COLS]){
    int row;
    int col;
    printf("Function displayBingoCard\n");
   printf("\t\t\t\t| ========================================== |\n");
    printf("\t\t\t\t|     B   |   I   |   N    |   G    |   O    |\n");
    printf("\t\t\t\t| ------------------------------------------ |\n");
   for (row=0;row<ROWS ; row++){
            printf("\t\t\t\t");
        for (col=0; col<COLS ; col++){

       if(row== FREE && col==FREE){
          printf("|  FREE  ");}
          else if (array[col][row]<=9){
            printf("|   %d    ",array [col][row]);

          }
          else {
             printf("|   %d   ",array[col][row]);

          }
        }


        printf("|\n");
         printf("\t\t\t\t| ------------------------------------------ |\n");

     }
       }


void setValue (int array[ROWS][COLS],int r, int c, int used [MAXVAL]){
     int num;
     int base;
     int idx;
     base = r*SCALE + SHIFT;
     num= rand()% 15 + base;
     idx = num + SHIFT;
     if (used[idx]== FALSE){
        used [idx]= TRUE;
        array[r][c]=num;
     } else {
     setValue(array,r,c,used);}
}

void initializeArray (int used[MAXVAL],int called[MAXVAL],char result[ROWS][COLS]) {
    int col; int row;
        for (col=0;col<MAXVAL; col++){
            used[col]= FALSE;
                called[col]=FALSE;}
                    for (row=0;row<COLS;row++){
                        for (col=0;col<COLS;col++){

                            result[row][col]=' ';
       }
     }


}
 void play (int card[ROWS][COLS],int called[MAXVAL],char result[ROWS][COLS]) {
 int number;
 bool bingo;
 char letter;
 int counter=0;
 while (bingo== false){

    number = callNumber(called);
    if (number>=0 && number<=15){
        letter = 'B';
            } else if (number>=16 && number<=30){
        letter = 'I'; }
        else if (number>=31 && number<=45){
        letter = 'N'; }
        else if (number>=46 && number<=60){
        letter = 'G'; }
        else if (number>=61 && number<=75){
        letter = 'O'; }

checkNumber (letter, number,card,result);
 displayNumber (letter,number);


 displayBingoCardPlay(card,result);
bingo = horizontalLine(result);
 }
  }

  void displayNumber(char letter,int number){

    printf ("%c - %d... %c...%d...", letter,number,letter,number);
    getchar();

  }
  void checkNumber( char letter,int number, int card[ROWS][COLS],char result [ROWS][COLS] ){
 int row; int col;
  switch(letter) {
      case 'B' :
        col = 0;
         break;
      case 'I' :
        col =1;
          break;
      case 'N' :
        col=2;
         break;
      case 'G' :
         col=3;
         break;
      case 'O' :
         col=4;
         break;
      default :
         printf("Invalid letter" );
   }
   for (row=0;row<ROWS;row++){
    if (card[col][row]==number){
        result[col][row]='X';
    }
   }

  }


  int callNumber (int called[MAXVAL]){
      int num;
    int idx;

    idx = (rand() % MAXVAL);
    num = idx + SHIFT;

    // based case to stop recursion
    if(called[idx] == FALSE)
    {
        called[idx] = TRUE;
        return num;
    }
    else
    {
        callNumber(called);
    }









  }
 void displayBingoCardPlay(int card[ROWS][COLS],char result[ROWS][COLS]){
     int row;
    int col;

    printf("\n Function displayBingoCardPlay \n");
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");

    for(col = 0; col < ROWS; col++)
    {
        printf("|");

        for(row = 0; row < COLS; row++)
        {
            if(col == FREE && row == FREE)
            {
                printf("  FREE |");
            }
            else if (result[row][col]=='X'){
               printf ("   X   |");
            } else
            {
                printf("%s%-3d", "   ", card[row][col]);
                printf(" |");
            }
        }

        printf("\n");
        printf("|---------------------------------------|\n");
    }
}
  bool horizontalLine(char result[ROWS][COLS]){
     int count = 0;
     int row=0;
     int col=0;

      if (result[0][0]=='X'&&result[1][0]=='X'&&result[2][0]=='X'&&result[3][0]=='X'&&result[4][0]=='X'||result[0][1]=='X'&&result[1][1]=='X'&&result[2][1]=='X'&&result[3][1]=='X'&&result[4][1]=='X' ||result[0][2]=='X'&&result[1][2]=='X'&&result[3][2]=='X'&&result[4][2]=='X'||result[0][3]=='X'&&result[1][3]=='X'&&result[2][3]=='X'&&result[3][3]=='X'&&result[4][3]=='X'||result[0][4]=='X'&&result[1][4]=='X'&&result[2][4]=='X'&&result[3][4]=='X'&&result[4][4]=='X') {

            printf("\n\n\t\t\t\tBINGO! YOU HAVE A BINGO!!! You won $1 MILLION DOLLARS!\n\n");
            return true; }
            else {return false;}

  }
