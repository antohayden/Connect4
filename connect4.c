//Connect 4 game

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int grid[6][6];//playing field

void title (void);     //title function
void grid_empty (void); //draws empty playing field
int check (int); //checks if character entered is valid
int position (int*, int); //stores position of circles: takes in turn and number entered
int winner (int); //function to check if this is a winning move

main()
{
    char player1[15], player2[15], winner_name[15];
    int circ_pos1, move;
    int turn = 1;
    int game; //used for a loop to switch between player turns

    title();
    
    printf("\n\n *****        The aim of the game is to match 4 circles in a row.        ***** \n"
           " *****      This can be done horizontally, vertically or diagonally      ***** \n"
           " ***** To place a circle in a column, enter the number above the column  ***** \n"
           " *****         The circle will drop to the lowest available tier         ***** \n"
           " *****      The game ends when a winner is declared or game is tied      ***** \n\n"
           "   ------Good luck and have fun!!!! <-(exlamation marks mean it's fun)-----    \n");
                
    
    printf("\n\nPlease enter the name of Player 1:\n"); //retrieve player names
    scanf("%14s", player1);
    printf("\n\nPlease enter the name of Player 2:\n");
    scanf("%14s", player2);

    
    /////////////////////////////////      end title screen        //////////////////////////////
    
    while (1) //START of game loop
    {
    if ( turn%2 != 0 ) // checks if number is odd or even to decide turn;
    {
        
        clrscr();   //clear screen
        grid_empty (); //Displays playing screen
        printf("%s, Please enter a number to place a circle in it's column:\n", player1);
        scanf( "%d", &move );        //takes in player move
        move = move - 1; //removes one to represent the array row
        move = check( move );//function to check if valid number
        
        circ_pos1 = position ( &turn, move);//checks where the circle is to be placed, also resets player move if column is full

        if (circ_pos1 != 99)//continues assuming no problems in if statment
            {
                grid[circ_pos1][move] = 1; //assigns 1 to chosen element
            }  

        game = winner (1); //runs check to see if 4 circles have connected
            
            if ( game == 0 )
            {
                strcpy( winner_name, player1 ); //assigns winner and exits loop
                break;
            }
            
        turn++; 
    }
    else
    {
        
        clrscr();   //clear screen
        grid_empty (); //Displays playing screen
        printf("%s, Please enter a number to place a circle in it's column:\n", player2);
        scanf( "%d", &move ); //takes in player move
        move = move - 1; //removes one to represent the array row
        move = check( move );//function to check if valid number
        
        circ_pos1 = position (&turn, move);//checks where the circle is to be placed

        if (circ_pos1 != 99)//continues assuming no problems in if statment
            {
                grid[circ_pos1][move] = 2; //assigns 1 to chosen element
            }  
            
        game = winner(2);
            
            if ( game == 0 )
            {
                strcpy( winner_name, player2 ); //assigns winner and exits loop
                break;
            }
            if ( game == 3 )
            {
                break;
            }
            
        turn++;
    }

    }//END of game loop
    
    clrscr();
    grid_empty (); //Displays playing screen
    
    if ( game == 3 )
    {
        printf("\n\n The game is tied. You both equally suck at this...");
    }
    else
    {
        printf("\n\n**********       %s has WON!       *********", winner_name); // winning message
    }
    

    
    getchar();
    getchar();
    
    
}

void title (void)
{
    char title_name[] = "Welcome to Connect 4!!";
    int j, i;
    j = strlen (title_name);//get string length for centering text
    
    for ( i = 0; i < 13; i++)
    {
        printf(" ");
    }
    
    for (i = 0; i < 51; i++)
    {
        printf("*");//top border
    }
    printf("\n*");//new line beginning with star
    
    for ( i = 0; i < 13; i++)
    {
        printf(" ");
    }
    
    for ( i = 0; i < (25 - (j/2)); i++)
    {
        printf(" ");//apply white space to left of string text
    }
    
    printf("%s", title_name); //string name
    
    for ( i = 0; i < 13; i++)
    {
        printf(" ");
    }
    
    for ( i = 0; i < ((25 - (j/2)) - 1); i++)
    {
        printf(" ");//apply white space to right of string text
    }
    
    printf("*\n");
    
        for ( i = 0; i < 13; i++)
    {
        printf(" ");
    }
    
        for (i = 0; i < 51; i++)
        {
        printf("*");//bottom border
        }
}//end function title

void grid_empty () // function creates the empty playing field to begin and subsequent fields with circles
{
    int i, j;
    
    char line0[] = "   1       2       3       4       5       6    \n";
    char line1[] = " ______ ";
    char line2[] = "|      |";
    char line3[] = " ------ ";
    char line4[] = "| **** |";
    char line5[] = "|*    *|";
    char line7[] = "|******|";

    
    printf("%s", line0); // prints numbers at top of screen
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++) //first line 
        {
            printf("%s", line1);
        }
            printf("\n");
        
        for (j = 0; j < 6; j++)//second line
        {
                if ( (grid[i][j] == 1) || (grid[i][j] == 2))
                {
                    printf("%s", line4);
                }
                else 
                {
                    printf("%s", line2);
                }
            
        }
        printf("\n");
        
        for (j = 0; j < 6; j++) //third line
        {
            if ( grid[i][j] == 1)
            {
                printf("%s", line5);
            }
            else if ( grid[i][j] == 2)
            {
                printf("%s", line7);
            }
            else 
            {
                printf("%s", line2);
            }
        }
        printf("\n");
        
        for (j = 0; j < 6; j++) //fourth line
        {
            if ( grid[i][j] == 1)
            {
                printf("%s", line5);
            }
            else if ( grid[i][j] == 2)
            {
                printf("%s", line7);
            }
            else 
            {
                printf("%s", line2);
            }
        }
        printf("\n");
    
            for (j = 0; j < 6; j++) //fifth line
            {
                if ( grid[i][j] == 1)
                {
                    printf("%s", line5);
                }
                else if ( grid[i][j] == 2)
                {
                    printf("%s", line7);
                }
                else 
                {
                    printf("%s", line2);
                }
            }
        printf("\n");
        
        for (j = 0; j < 6; j++)     //sixth line
        {
            if ( grid[i][j] == 1 || grid[i][j] == 2)
            {
                printf("%s", line4);
            }
            else 
            {
                printf("%s", line2);
            }
        }
        printf("\n");
            
        for (j = 0; j < 6; j++) //seventh line
            {
                printf("%s", line1);
            }
    
        printf("\n");
        
    }//end outer for loop
    
        for (j = 0; j < 6; j++)
    {
        printf("%s", line3);
    }
    printf("\n");
}

//Function to check if entry is correct

int check (int move)
{
        if ( ( move < 6 ) )
            {
                return (move);//returns number if correct
            }
        else
            {
            printf("Incorrect input, please try again:");
            scanf("%d", &move);
            return ( check (move));
            }
}

//function for position of circle
int position (int* turn, int move)
{
    int i;
    
    for ( i = 0; i < 6; i++ )
    {
            if ( (grid[i][move] == 1) ||  (grid[i][move] == 2) ) //checks is element is occupied already
            {
                if ( i == 0 ) //true if column is full
                {
                    printf("\nThat column is full. Please try another!"); //prints if the column is full
                    *turn = *(turn) - 1; //resets players turn
                    return (99);
                }
                else
                {
                    return ( i - 1 ); //returns row which circle is to be placed
                }
            }

    }
    return (5);
}//end function

//function to check if the winning move has taken place
int winner (int num)
{
    int i, j;
    int tie = 0;
    
    for ( i = 0; i < 3; i++ )
    {
        for ( j = 0; j < 6; j++)                //less than 3 because it's the highest up a 4 line can be
        {
            if ( grid[i][j] == num )              //checks vertical lines ( top - > bottom )
               if (grid[i + 1][j] == num )
                   if (grid[i + 2][j] == num )
                       if (grid[i + 3][j] == num )
                       {
                           return ( 0 );
                       }
        }
    }
    
    for ( i = 0; i < 6; i++ ) //less than 3 because it's the furthest a 4 line can be from left
    {
        for  ( j = 0; j < 3; j++ )
        {
            if ( grid[i][j] == num )              //checks horizontal lines ( left - > right )
                if ( grid[i][j + 1] == num )
                    if ( grid[i][j + 2] == num )
                        if ( grid[i][j + 3] == num )
                        {
                            return ( 0 );
                        }
        }
    }
    
    for ( i = 0; i < 3; i ++ )              //checks diagonal lines ( acute )
    {
        for ( j = 3; j < 6; j ++ )      
        {
            if ( grid[i][j] == num )
                if ( grid[i + 1][j - 1] == num )
                    if ( grid[i + 2][j - 2] == num )
                        if ( grid[i + 3][j - 3] == num )
                        {
                            return ( 0 );
                        }
        }
    }
    
    for ( i = 0; i < 3; i++ )           //checks diagonal lines ( obtuse )
    {
        for ( j = 0; j < 3; j++ )
        {
            if ( grid[i][j] == num )
                if ( grid[i + 1][j + 1] == num )
                    if ( grid[i + 2][j + 2] == num )
                        if ( grid[i + 3][j + 3] == num )
                        {
                            return ( 0 );
                        }
        }
    }
    
    for ( i = 0; i < 6; i++ ) //loop to check if every element has been filled ( game tied )
    {
        for ( j = 0; j < 6; j++ )
        {
            if ( grid[i][j] == 1 || grid[i][j] == 2 )
            {
                tie ++;
                if ( tie == 36 )
                {
                    return ( 3 );
                }
            }
        }
    }
            
    
    return (1); //returns 1 to resume play if none of the 4 loops show a winner
}
   
    
    
    
    
    
    
    
    
    
    
    
    
    