// Command version


#include <iostream>


using namespace std;

int table[12];
bool quan0 = true, quan6 = true;
bool game_over = false;
int player1 = 0, player2 = 0;
int turn = 1; // (1 , 2)
int winner = 1; // (1, 2)

void init(){

    for (int i = 1; i <= 5; i++){
        table[i] = 5;
    }
    for (int i = 7; i <= 11; i++){
        table[i] = 5;
    }


}

void ket_thuc(){

    cout << "Winner: " << winner << endl;

    return;

}

void show_table(){
    cout << "-------------------------------------" << endl;
    if (quan0){
        cout << "X ";
    }
    int i;
    for (i = 11; i >= 7; i--){
        cout << table[i] << " ";
    }
    if (quan6){
        cout << "O ";
    }
    cout << endl;

    for (i = 0; i <= 6; i++){
        cout << table[i] << " ";
    }
    cout << endl;


}

bool check_game_over(){
    if (table[0] == 0 && table[6] == 0 && !quan0 && !quan6){
        return false;
    }
    return true;
}

// khi 5 ô quân trống thì tự động rải mỗi ô 1 quân
// nếu số quân < 5 thì thua
bool ban_trong(int turn){
    if (turn == 1){
        for (int i = 1; i <= 5; i++){
            if (table[i] != 0)
                return false;
        }
        return true;
    }
    if (turn == 2){
        for (int i = 7; i <= 11; i++){
            if (table[i] != 0){
                return false;
            }
        }
        return true;
    }
}
void rai_quan(int turn){
    if (turn == 1){
        if (ban_trong(turn)){
            if (player1 < 5){
                game_over = false;
                ketthuc();
            }
        }
        for (int i = 1; i <= 5; i++){
            table[i]++;
            player1--;
        }
    }
    if (turn == 2){
        if (ban_trong(turn)){
            if (player2 < 5){
                game_over = false;
                ketthuc();
            }
        }
        for (int i = 7; i <= 11; i++){
            table[i]++;
            player2--;
        }
    }


}

void play(){

    while (!game_over){ss



        game_over = check_game_over();
    }



}


int main(int argc, char* argv[]){


    init();
    show_table();

    while (true)







    return 0;
}





