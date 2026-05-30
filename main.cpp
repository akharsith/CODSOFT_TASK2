#include <iostream>
#include <vector>

using namespace std;

char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";

            if(j < 2)
                cout << "|";
        }

        cout << "\n";

        if(i < 2)
            cout << "-----------\n";
    }

    cout << "\n";
}

bool checkWin(char player)
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == player &&
           board[i][1] == player &&
           board[i][2] == player)
            return true;

        if(board[0][i] == player &&
           board[1][i] == player &&
           board[2][i] == player)
            return true;
    }

    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player)
        return true;

    if(board[0][2] == player &&
       board[1][1] == player &&
       board[2][0] == player)
        return true;

    return false;
}

bool isDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

bool placeMove(int choice, char player)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = player;
        return true;
    }

    return false;
}

void computerMove()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int main()
{
    int choice;

    cout << "===== TIC TAC TOE AI =====\n";

    while(true)
    {
        displayBoard();

        cout << "Enter your move (1-9): ";
        cin >> choice;

        if(choice < 1 || choice > 9)
        {
            cout << "Invalid move!\n";
            continue;
        }

        if(!placeMove(choice, 'X'))
        {
            cout << "Cell already occupied!\n";
            continue;
        }

        if(checkWin('X'))
        {
            displayBoard();
            cout << "You win!\n";
            break;
        }

        if(isDraw())
        {
            displayBoard();
            cout << "Game Draw!\n";
            break;
        }

        computerMove();

        if(checkWin('O'))
        {
            displayBoard();
            cout << "Computer wins!\n";
            break;
        }

        if(isDraw())
        {
            displayBoard();
            cout << "Game Draw!\n";
            break;
        }
    }

    return 0;
}
