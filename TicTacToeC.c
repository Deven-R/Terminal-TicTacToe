#include <stdio.h>
#include <string.h>

char gridsize_n[50][50];      //Global variables in use

int start_grid(int markersize);  //to initialize and reset grid                                                              /* Functions in use */
void print_grid(int markersize); //to draw the grid
void player_1move(void);
void player_2move(void);
int row_covered(int markersize, char gridsize_n[50][50], int finished);

int main(void){
    int finished = 0;
    int counter = 0;
    int markersize = 0;                                                                              // n = markersize, to make it easier to navigate
    
    printf("WELCOME TO TIC TAC TOE! PLEASE ENTER THE SIZE OF THE GRID YOU WANT TO PLAY ON: \n");
    scanf("%d", &markersize);
    
    if (markersize>50) {                                                  //Defines the n x n grid; returns 1 in order to cancel making the grid after 50
        printf("Invalid! Try again \n");
        return 1;}
        
            start_grid(markersize);                                       //GAME STARTS by drawing out the grid and asking for n (markersize)
            print_grid(markersize);
            
            do {
            player_1move();
            print_grid(markersize);
            finished = row_covered(markersize, gridsize_n, finished);      //Row_covered function to check winner, depended on what return finished is
            if (finished != 0) {
                printf("Player 1 Won!!! \n");
                break;
            }
            player_2move();
            print_grid(markersize);
            counter++;                                                     //turn counter
            finished = row_covered(markersize, gridsize_n, finished);
                if(finished == 2)
                    printf("Player %d Won!!! \n",finished);
               } while (finished == 0);
    printf("Thanks for playing!! Please Re-Run program in order to play again! \n");
        return 0;
}

int start_grid(int markersize){                                                                                                //Initializing the grid
    
    int row=0;
    int column=0;
    
    for (row = 0; row<markersize; row++) {
        for (column = 0; column<markersize; column++) {
            gridsize_n[row][column] = '-';                                           //This substitues '-' so when a putchar is used, a '-' is printed
        } //
    } return 0;
   }

void print_grid(int markersize){                                                                                          //Main function to draw grid
    
    int column;
    int row;
    
    for (row = 0; row < markersize; row++)
        {
            for (column = 0; column < markersize; column++)
            {
                printf("  \t");                      //having spaces between grid marks, \t functions as tab (added to make the marks have bigger spaces
                if (gridsize_n[row][column])
                {
                    putchar (gridsize_n[row][column]);
                }
                else
                {
                    printf("-");                                                                                        //Printing out marks for the grid
                }
            }
            printf("\n");
        }
}

void player_1move(void){
    
    int x;
    int y;
    
    
    printf("Player 1 __X__ Enter the row and column you wish to mark: \n ");
    scanf("%d,%d",&x,&y);
    x--;y--;                  //Decreminting each x and y so that the marks are accurately placed as the player wants and not as matrix of the array works                                                                                                                                 (starting from 0)
    
    if((gridsize_n[x][y] != '-')){                                                                                  //checking for empty spaces to mark
    printf("Invalid move \n");                                                                                    //return invalid if space is occupied
        player_1move();                                                                                      //repeating the function after invalid move
    }
    else
        gridsize_n[x][y] = 'X';                                                           //Player1 prefedined as X to make program simpler and efficient
}

void player_2move(void){
    
    int x;
    int y;
    
    
    printf("Player 2 __O__ Enter the row and column you wish to mark: \n ");
    scanf("%d,%d",&x,&y);
    x--;y--;
    
    if((gridsize_n[x][y] != '-')){
        printf("Invalid move \n");
        player_2move();
    }
    else
    gridsize_n[x][y] = 'O'; //Player 2
}

int row_covered(int markersize, char gridsize_n[50][50], int finished){
    
    int rowCounter = 0;
    int colCounter = 0;
    int x;
    int y;
    
    //HORIZONTAL win CHECK
    
   for (x = 0; x < markersize; x++) {
        if (rowCounter == markersize || colCounter == markersize)                                            //Game logic was to assign X = 1 and 0 = -1
            return finished = 1;
        else if (rowCounter == -1*markersize || colCounter == -1*markersize)                            //If X added up was positive N then player 1 won
            return finished = 2;                                                                        //If O added up to a negative N then player 2 won
        rowCounter = 0;                                //Columns and rows in their specific checks were counted in order to determine a sum
        colCounter = 0;
        
       for (y = 0; y < markersize; y++) {
       if (gridsize_n[x][y] == 'X'){
           rowCounter++;
           }
       if (gridsize_n[x][y] == 'O')
           rowCounter--;
       if (gridsize_n[y+1][x] == 'X')
           colCounter++;
       if (gridsize_n[y+1][x] == 'O')
           colCounter--;}
}
    //VERTICAL win CHECK
    
    for (x = 0; x < markersize; x++)  {
         if (rowCounter == markersize || colCounter == markersize)
             return finished = 1;
         else if (rowCounter == -1*markersize || colCounter == -1*markersize)
             return finished = 2;
         rowCounter = 0;
         colCounter = 0;
         
             for (y = 0; y < markersize; y++) {
             if (gridsize_n[x][y] == 'X'){
                 rowCounter++;
                 }
             if (gridsize_n[x][y] == 'O')
                 rowCounter--;
             if (gridsize_n[y][x+1] == 'X')
                 colCounter++;
             if (gridsize_n[y][x+1] == 'O')
                 colCounter--;}
         }
    
    for (x = 0; x < markersize; x++)  {
         if (rowCounter == markersize || colCounter == markersize)
             return finished = 1;
         else if (rowCounter == -1*markersize || colCounter == -1*markersize)
             return finished = 2;
         rowCounter = 0;
         colCounter = 0;
         
             for (y = 0; y < markersize; y++) {
             if (gridsize_n[x][y] == 'X'){
                 rowCounter++;
                 }
             if (gridsize_n[x][y] == 'O')
                 rowCounter--;
             if (gridsize_n[y+1][x+1] == 'X')
                 colCounter++;
             if (gridsize_n[y+1][x+1] == 'O')
                 colCounter--;}
         }
    
    return finished = 0;
}


