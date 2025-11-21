#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    char PLCharacter;
    string PLname;

public:
    Player(char PLChar, string pLname)
    {
        PLCharacter = PLChar;
        PLname = pLname;
    }

    char getPLCharacter() const
    {
        return PLCharacter;
    }

    string getPLname() const
    {
        return PLname;
    }
};

class Board
{
private:
    char board[3][3];
    int Counter;
    Player* pL1;
    Player* pL2;

public:

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            if (board[0][2] == pL1->getPLCharacter())
            {
                cout << "Player (" << pL1->getPLname() << ") winer\n";
                return true;
            }
            else if (board[0][2] == pL2->getPLCharacter())
            {
                cout << "Player (" << pL2->getPLname() << ") winer\n";
                return true;
            }
        }
        return false;
    }

    void drawBoard()
    {
        cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "-------\n";
            cout << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
        }
        cout << "-------\n"
             << "\n";
    }

    void makeMove(char c, int i, int j)
    {
        board[i][j] = c;
        addCounter();
    }

    void isValidMove(char c)
    {
       
    }

    void isFull()
    {
        if (Counter >= 9)
        {
            cout << "All pLaces is full\n";
        }
    }

    bool isBoardFull()
    {
        return Counter >= 9;
    }
    
    char getPL1Char() const 
    {
        return pL1->getPLCharacter();
    }
    
    char getPL2Char() const 
    {
        return pL2->getPLCharacter();
    }
};

class Dooz
{
private:
    Board* b;
    int appointment = 1;

public:
   
};

int main()
{
    string name1, name2;
    char char1 = 'X';
    char char2 = 'O';

    cout << "Please enter the name of player 1:\n";
    cin >> name1;
    cout << "Your sign as a player 1 is (" << char1 << ")\n";
    cout << "Please enter the name of player 2:\n";
    cin >> name2;
    cout << "Your sign as a player 2 is (" << char2 << ")\n";

    Player p1(char1, name1);
    Player p2(char2, name2);
    Board b(&p1, &p2);
    Dooz d(&b);

    while (true)
    {
        b.drawBoard();
        d.manageappointment();
        
        if (b.checkWin())
        {
            b.drawBoard();
            cout << "The Dooz ended\n";
            break;
        }
        if (b.isBoardFull())
        {
            d.play();
            cout << "The Dooz ended and the game have not winer\n";
            break;
        }
    }
    return 0;
}