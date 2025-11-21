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
    Board(Player* player1, Player* player2)
    {
        pL1 = player1;
        pL2 = player2;
        Counter = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
    }

    void addCounter()
    {
        Counter++;
    }

    bool checkWin()
    {
        for (int i = 0; i < 3; ++i)
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                if (board[i][0] == pL1->getPLCharacter())
                {
                    cout << "Player (" << pL1->getPLname() << ") winer\n";
                    return true;
                }
                else if (board[i][0] == pL2->getPLCharacter())
                {
                    cout << "Player (" << pL2->getPLname() << ") winer\n";
                    return true;
                }
            }

        for (int j = 0; j < 3; ++j)
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            {
                if (board[0][j] == pL1->getPLCharacter())
                {
                    cout << "Player (" << pL1->getPLname() << ") winer\n";
                    return true;
                }
                else if (board[0][j] == pL2->getPLCharacter())
                {
                    cout << "Player (" << pL2->getPLname() << ") winer\n";
                    return true;
                }
            }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            if (board[0][0] == pL1->getPLCharacter())
            {
                cout << "Player (" << pL1->getPLname() << ") winer\n";
                return true;
            }
            else if (board[0][0] == pL2->getPLCharacter())
            {
                cout << "Player (" << pL2->getPLname() << ") winer\n";
                return true;
            }
        }

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
        
};

class Dooz
{
private:
    Board* b;
    int appointment = 1;

public:
    Dooz(Board* board)
    {
        b = board;
    }

    void manageappointment()
    {
        if (appointment == 1)
        {
            b->isValidMove(b->getPL1Char());
        }
        else if (appointment == 2)
        {
            b->isValidMove(b->getPL2Char());
        }
        appointment = (appointment == 1) ? 2 : 1;
    }

    void play()
    {
        cout << "The game is equal\n";
    }
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