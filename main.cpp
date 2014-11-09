#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//Question 1
double cubic_root( double key, double error ) {
    double high, low, mid;
    // when input is larger than 1
    if (key > 1) {
        cout << ">1" <<endl;
        low = 0;
        high = key;
        mid = (low + high) / 2;
        while (abs(mid * mid * mid - key) > error) {
            mid = (low + high) / 2;
            if ((mid * mid * mid - key) > 0)
                high = mid;
            else if ((mid * mid * mid - key) < 0)
                low = mid;
            else
                break;
        }
    }
        // when input i less than 1
    else if (key < 1) {
        cout << "<1" <<endl;
        low = key ;
        high = 1;
        mid = (low + high) / 2;
        while (abs(mid * mid * mid - key) > error) {
            mid = (low + high) / 2;
            if ((mid * mid * mid - key) < 0)
                low = mid;
            else if ((mid * mid * mid - key) > 0)
                high = mid;
            else
                break;
        }
}
   return mid;
}
// find_min function
int find_min(int array[]){
    int smallest = array[0];
    int i= 0;
    for (int k=0;k<12;k++)
    {
        if (array[k]<smallest)
        { smallest = array[k];
            i = k;
        }
    }
    return i;
}
//
//Update UI function
int updateUI(vector<string>game) {
    cout<<endl;
    for (auto &i :game) {
        cout << i;
    }
    return 0;
}
// scan the next count of wins
int  scanGame (vector<string>game,string scan){
    int visited[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int count = 8;
    if((game[0] == scan && game[1] == scan && game[2] == scan)
            || (game[0] == scan && game[4] == scan && game[8] == scan)
            || (game[0] == scan && game[5] == scan && game[10]== scan)
            || (game[1] == scan && game[5] == scan && game[9] == scan)
            || (game[4] == scan && game[5] == scan && game[6] == scan)
            || (game[2] == scan && game[5] == scan && game[8] == scan)
            || (game[8] == scan && game[9] == scan && game[10] == scan)
            || (game[2] == scan && game[6] == scan && game[10] == scan))
    {
        count = -998;
        visited [0] = 1;
        visited [1] = 1;
        visited [2] = 1;
        visited [3] = 1;
        visited [4] = 1;
        visited [5] = 1;
        visited [6] = 1;
        visited [7] = 1;
    }
    else {
        for (int i = 0; i < 9; i++) {
            if (visited[0] == 0 && (game[0] == scan || game[1] == scan || game[2] == scan)) {
                count -= 1;
                visited[0] = 1;
            }
            else if (visited[1] == 0 && (game[4] == scan || game[5] == scan || game[6] == scan)) {
                count -= 1;
                visited[1] = 1;
            }
            else if (visited[2] == 0 && (game[8] == scan || game[9] == scan || game[10] == scan)) {
                count -= 1;
                visited[2] = 1;
            }
            else if (visited[3] == 0 && (game[0] == scan || game[4] == scan || game[8] == scan)) {
                count -= 1;
                visited[3] = 1;
            }
            else if (visited[4] == 0 && (game[1] == scan || game[5] == scan || game[9] == scan)) {
                count -= 1;
                visited[4] = 1;
            }
            else if (visited[5] == 0 && (game[2] == scan || game[6] == scan || game[10] == scan)) {
                count -= 1;
                visited[5] = 1;
            }
            else if (visited[6] == 0 && (game[0] == scan || game[5] == scan || game[10] == scan)) {
                count -= 1;
                visited[6] = 1;
            }
            else if (visited[7] == 0 && (game[2] == scan || game[5] == scan || game[8] == scan)) {
                count -= 1;
                visited[7] = 1;
            }
        }
    }
        return count;
    }
//to calculate the utility function
int utilityCal(vector<string> game){
    int utility[] = {999,999,999,999,999,999,999,999,999,999,999,999};
    for (int i = 0; i<12;i++){
        if (game[i]!="o "&& game[i]!="\n" &&game[i] !="x ") {
            game[i] ="o ";
            utility[i] = scanGame(game, "o ") - scanGame(game, "x ");
            game[i] = "_ ";
        }
    }
    for  (int j = 0; j<12;j++){
        if (game[j]!="o "&& game[j]!="\n" &&game[j] !="x ") {
            game[j] ="x ";
            int utilityNew= scanGame(game, "x ") - scanGame(game, "o ");
            if (utilityNew< utility[j])
                utility[j] = utilityNew - 4;
            game[j] = "_ ";
        }
    }
    cout<< "The utility value is " << endl;
    for (auto i : utility)
        cout << i << " ";
    int position = find_min(utility);
    return position;
}
// main game function
int tictactoe() {
    bool win = false;
    vector<string> game{"_ ", "_ ", "_ ", "\n", "_ ", "_ ", "_ ", "\n", "_ ", "_ ", "_ ", "\n"};
    int vacancy = 9;
    updateUI(game);
    /*   Debug
    game[2] = "x ";
    game[5] = "x ";
    game[8] = "o ";
    game[10] = "o ";
    game[4] = "o ";
    int i =scanGame(game, "x ");
    int j =scanGame(game, "o ");
    cout << i << " "<<j;
    */
    while (!win) {
        int row, col;
        while (1) {
            cout << "Please enter your step (o) (format : x x) :" << endl;
            cin >> row >> col;
            int position = (row - 1) * 4 + (col - 1);
            if ((row>3) || (col>3))
            {
                cout<< "Opps Maximun 3 col and row" <<endl;
            }
            else if (game[position] != "_ "){
                cout<< "Opps This slot is occupied" <<endl;
            }
            else {
                cout << "You entered :" << row << "," << col << endl;
                break;
            }
        }
        int position = (row - 1) * 4 + (col - 1);
        game[position] = "o ";
        vacancy -= 1;
        updateUI(game);
        int me_position = utilityCal(game);
        if ((game[me_position] != "x ")&&(game[me_position] != "o ") ) {
            game[me_position] = "x ";
            vacancy -= 1;
            cout << "\nMy step (x) : " << endl;
            updateUI(game);
        }
    // win or lose
            if((game[0] == "x " && game[1] == "x " && game[2] == "x ")
            || (game[0] == "x " && game[4] == "x " && game[8] == "x ")
            || (game[0] == "x " && game[5] == "x " && game[10]== "x ")
            || (game[1] == "x " && game[5] == "x " && game[9] == "x ")
            || (game[4] == "x " && game[5] == "x " && game[6] == "x ")
            || (game[2] == "x " && game[6] == "x " && game[10] == "x ")
            || (game[8] == "x " && game[9] == "x " && game[10] == "x ")
            || (game[2] == "x " && game[5] == "x " && game[8] == "x ")) {
        cout << "I win !" << endl;
        win = true;
    }
       else if((game[0] == "o " && game[1] == "o " && game[2] == "o ")
            || (game[0] == "o " && game[4] == "o " && game[8] == "o ")
            || (game[0] == "o " && game[5] == "o " && game[10]== "o ")
            || (game[1] == "o " && game[5] == "o " && game[9] == "o ")
            || (game[4] == "o " && game[5] == "o " && game[6] == "o ")
            || (game[2] == "o " && game[6] == "o " && game[10] == "o ")
            || (game[8] == "o " && game[9] == "o " && game[10]== "o ")
            || (game[2] == "o " && game[5] == "o " && game[8] == "o ")) {
        cout << "YOU win !" << endl;
        win = true;
    }
        else if (vacancy == 0){
                cout << "\n It is a draw !" << endl;
                win = true;
            }
 // END win or lose
}
return 0;
}
//EE4483 Main
int main() {
    cout<< " /        9 Nov 2014         \\" << endl;
    cout<< " | App developed by Yang Fan |" << endl;
    cout<< " \\        For EE 4483        /" << endl;
    cout<< "                               " << endl;
    cout << "please enter quesiton number:  " << endl;
    cout << "1.Cubic Square   " << endl;
    cout << "2.Tic Tac Toe  " << endl;
    int choice;
    while(1) {
        cin >> choice;
        if ((choice!= 1) && (choice != 2)){
            cout << "Oppps Wrong input, only 1 and 2"<< endl;
        }
        else
            break;
    }
   while (choice ==1) {
       double input;
       cout << "please enter the number( 0 to quit) :" << endl;
       cin >> input;
       if(input == 0)
       {
           break;
       }
           double answer = cubic_root(input, 0.00001);
           cout << "the answer is :" << answer << endl;
   }
    if (choice ==2 )
    {
        tictactoe();
    }
    return 0;
}
