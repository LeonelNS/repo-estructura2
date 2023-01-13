//TicTacToe GAME 

#include <iostream>

using namespace std;

string player1;
string player2;

char space[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int winner();
void board();

int main()
{
    int player = 1, choice, i;

    char mark;

    cout << "Introduzca el nombre del jugador 1" << endl;
    cin >> player1;

    cout << "\nIntroduzca el nombre del jugador 2" << endl;
    cin >> player2;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        if (player == 1) {
            cout << player1 << " introduzca el numero donde desea jugar: " << endl;
        }
        else {
            cout << player2 << " introduzca el numero donde desea jugar: " << endl;

        }
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && space[1] == '1')
        {
            space[1] = mark;
        }
        else if (choice == 2 && space[2] == '2')
        {
            space[2] = mark;
        }
        else if (choice == 3 && space[3] == '3')
        {
            space[3] = mark;
        }
        else if (choice == 4 && space[4] == '4')
        {
            space[4] = mark;
        }
        else if (choice == 5 && space[5] == '5')
        {
            space[5] = mark;
        }
        else if (choice == 6 && space[6] == '6')
        {
            space[6] = mark;
        }
        else if (choice == 7 && space[7] == '7')
        {
            space[7] = mark;
        }
        else if (choice == 8 && space[8] == '8')
        {
            space[8] = mark;
        }
        else if (choice == 9 && space[9] == '9')
        {
            space[9] = mark;
        }
        else
        {
            cout << "Movimiento invalido";

            player--;
            cin.ignore();
            cin.get();
        }

        i = winner();
        player++;

    } while (i == -1);
    board();
    if (i == 1)
    {
        player--;
        if (player == 1) {
            cout << "\aFELICIDADES " << player1 << ", ERES EL GANADOR!";
        }
        else {
            cout << "\aFELICIDADES " << player2 << ", ERES EL GANADOR!";

        }
    }
    else
    {
        cout << "EMPATE!";
    }
    cin.ignore();
    cin.get();
    return 0;
}


int winner()
{
    if (space[1] == space[2] && space[2] == space[3])
    {
        return 1;
    }
    else if (space[4] == space[5] && space[5] == space[6])
    {
        return 1;
    }
    else if (space[7] == space[8] && space[8] == space[9])
    {
        return 1;
    }
    else if (space[1] == space[4] && space[4] == space[7])
    {
        return 1;
    }
    else if (space[2] == space[5] && space[5] == space[8])
    {
        return 1;
    }
    else if (space[3] == space[6] && space[6] == space[9])
    {
        return 1;
    }
    else if (space[1] == space[5] && space[5] == space[9])
    {
        return 1;
    }
    else if (space[3] == space[5] && space[5] == space[7])
    {
        return 1;
    }
    else if (space[1] != '1' && space[2] != '2' && space[3] != '3'
        && space[4] != '4' && space[5] != '5' && space[6] != '6'
        && space[7] != '7' && space[8] != '8' && space[9] != '9')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void board()
{
    system("cls");
    cout << "Bienvenido a TIC TAC TOE" << endl;

    cout << player1 << "(X)  -  " << player2 << "(O)" << endl;


    cout << "     |     |     " << endl;
    cout << "  " << space[1] << "  |  " << space[2] << "  |  " << space[3] << endl;

    cout << " ____|_____|____" << endl;
    cout << "     |     |     " << endl;


    cout << "  " << space[4] << "  |  " << space[5] << "  |  " << space[6] << endl;


    cout << " ____|_____|____" << endl;
    cout << "     |     |     " << endl;


    cout << "  " << space[7] << "  |  " << space[8] << "  |  " << space[9] << endl;
    cout << "     |     |     " << endl;
}
