#include <iostream>
using namespace std;

int row;
int column;
char token = 'x';
bool tie;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

string n1;
string n2;

void functionOne() {
    cout << "__|____|__" << endl;
    cout << " " << space[0][0] << "| " << space[0][1] << "  |" << space[0][2] << " \n";
    cout << "__|____|__" << endl;
    cout << "  |    |" << endl;
    cout << " " << space[1][0] << "| " << space[1][1] << "  |" << space[1][2] << " \n";
    cout << "__|____|__" << endl;
    cout << "  |    |" << endl;
    cout << " " << space[2][0] << "| " << space[2][1] << "  |" << space[2][2] << " \n";
    cout << "__|____|__" << endl;
}

void functionTwo() {
    int digit;

    if (token == 'x') {
        cout << n1 << ", please enter a number (1-9): "<<endl;
        cin >> digit;
    } else {
        cout << n2 << ", please enter a number (1-9): "<<endl;
        cin >> digit;
    }

    if (digit < 1 || digit > 9) {
        cout << "Invalid input! Please choose a number between 1 and 9." << endl;
        functionTwo();
        return;
    }

    row = (digit - 1) / 3;
    column = (digit - 1) % 3;

    if (space[row][column] != 'x' && space[row][column] != '0') {
        if (token == 'x') {
            space[row][column] = 'x';
            token = '0';
        } else {
            space[row][column] = '0';
            token = 'x';
        }
    } else {
        cout << "Invalid input or position already taken!" << endl<<endl;
        functionTwo();
    }
}

bool functionThree() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2] || space[0][i] == space[1][i] && space[1][i] == space[2][i])
            return true;
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }
    tie = true;
    return true;
}

int main() {
    cout << "Enter the name of the first player: "<<endl;
    getline(cin, n1);
    cout << "Enter the name of the second player: "<<endl;
    getline(cin, n2);
    cout << n1 << " is Player 1, playing as 'x'." << endl;
    cout << n2 << " is Player 2, playing as '0'." << endl;

    while (!functionThree()) {
        functionOne();
        functionTwo();
    }

    functionOne();

    if (token == 'x' && !tie) {
        cout << n2 << " Wins!" << endl;
    } else if (token == '0' && !tie) {
        cout << n1 << " Wins!" << endl<<endl;
    } else {
        cout << "It's a Draw!" << endl<<endl;
    }

    return 0;
}
