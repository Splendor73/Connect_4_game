#include <stdio.h>
#include <stdbool.h>
#include "slist.h"

#define ROW 6
#define COL 7

char gameBoard[ROW][COL];

// FUNCTION PROTOTYPES
void dispayboard();
int InMove(const char *playerName);
void InToken(char token, int col);
bool nospace(int col);
bool checkWin(char token);
bool checkDirection(int r, int c, int rD, int cD, char token);
bool isDraw();

// FUNCTIONS
void displayboard()
{
    for (int i = 0; i < ROW; i++)
    {
        printf("|");

        for (int j = 0; j < COL; j++)
        {
            printf("%c|", gameBoard[i][j]);
        }

        printf("\n");
    }

    printf("---------------\n");
}

int InMove(const char *playerName)
{
    int selectedCol;
    printf("%s to play. Pick a column (1-%d): ", playerName, COL);

    while (1)
    {

        int scanResult = scanf("%d", &selectedCol);
        while (getchar() != '\n')
        {
        } // Clearing buffer immediately

        if (scanResult == 1 && selectedCol >= 1 && selectedCol <= COL)
        {

            if (!nospace(selectedCol - 1))
            {
                break;
            }
            else
            {
                printf("Column full. Choose another column: ");
            }
        }

        else
        {

            printf("Invalid input. Please pick a column between 1 and %d: ", COL);
        }
    }
    return selectedCol - 1; // We subtract 1 to get a 0-based index
}

void InToken(char token, int col)
{

    for (int i = ROW - 1; i >= 0; i--)
    {

        if (gameBoard[i][col] == ' ')
        {

            gameBoard[i][col] = token;
            break;
        }
    }
}

bool nospace(int col)
{

    return gameBoard[0][col] != ' ';
}

bool checkWin(char token)
{
    for (int i = 0; i < ROW; i++)
    {

        for (int j = 0; j < COL; j++)
        {

            if (gameBoard[i][j] == token)
            {

                if (checkDirection(i, j, 1, 0, token) ||
                    checkDirection(i, j, 0, 1, token) ||
                    checkDirection(i, j, 1, 1, token) ||
                    checkDirection(i, j, 1, -1, token))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkDirection(int r, int c, int rD, int cD, char token)
{
    int count = 0;

    for (int i = 0; i < 4; i++)
    {

        if (r >= 0 && r < ROW && c >= 0 && c < COL && gameBoard[r][c] == token)
        {
            count++;
            r += rD;
            c += cD;
        }
        else
        {
            break;
        }
    }
    return count == 4;
}

bool isDraw()
{
    for (int i = 0; i < COL; i++)
    {

        if (!nospace(i))
        {
            return false;
        }
    }
    return true;
}

// MAIN
int main()
{
    SList *list;
    char tempBoard[ROW][COL];
    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y')
    {
        list = createList();
        const char *redPlayer = "Red";
        const char *yellowPlayer = "Yellow";
        char currentPlayer = 'R';
        bool gameWon = false;

        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                gameBoard[i][j] = ' ';
                tempBoard[i][j] = ' ';
            }
        }

        displayboard();
        while (!gameWon && !isDraw())
        {
            int col = InMove(currentPlayer == 'R' ? redPlayer : yellowPlayer);
            insertNode(list, col, currentPlayer);
            InToken(currentPlayer, col);
            displayboard();

            if (checkWin(currentPlayer))
            {
                printf("%s Player Wins!\n", currentPlayer == 'R' ? redPlayer : yellowPlayer);
                gameWon = true;
                break;
            }

            currentPlayer = (currentPlayer == 'R') ? 'Y' : 'R';
        }

        if (!gameWon)
        {
            printf("It's a draw!\n");
        }

        char choice;
        printf("Enter ‘q’ to quit, ‘r’ for replay, any other key to play again: ");
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q')
        {
            playAgain = 'N';
        }
        else if (choice == 'r' || choice == 'R')
        {
            replay(list, tempBoard);
            printf("+Replay Ends+\n\n");

            printf("Press 'q' to quit or any other key to continue: ");
            scanf(" %c", &playAgain); 
            if (playAgain == 'q' || playAgain == 'Q')
            {
                break; 
            }
            else
            {
                playAgain = 'Y'; 
            }
        }
        freeList(list);
    }

    return 0;
}
