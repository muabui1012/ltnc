#include <iostream>

using namespace std;

int table[12];
int quan0 = 0, quan6 = 0; /*
                                0: đang ở trong bàn
                                1: đang ở trong player1
                                2: đang ở trong player2

                                        */
bool game_over = false;
int player1 = 0, player2 = 0;
int turn = 1; // (1 , 2)
int winner = 1; // (1, 2)
int mode = 0; // 0: nguoi vs nguoi  || 1: nguoi vs may



void init(){

    for (int i = 1; i <= 5; i++){
        table[i] = 5;
    }
    for (int i = 7; i <= 11; i++){
        table[i] = 5;
    }


}

void ket_thuc(){
    cout << "Het quan toan dan vo ve: " << endl;
    cout << "Winner: " << winner << endl;

    return;

}

void choose_mode(){

}

void show_score(){
    cout << endl;
    cout << "Player1: " << player1 << endl;
    cout << "Player2: " << player2 << endl;
    cout << endl;
}

void show_table(){

    cout << "----------------------" << endl;
    if (quan0 == 0){
        cout << "| X |";
    }
    else {
        cout << "|   |";
    }

    int i;
    for (i = 11; i >= 7; i--){
        cout << table[i] << " |";
    }
    if (quan6 == 0){
        cout << "Z |";
    }
    else {
        cout << "|   |";
    }
    cout << endl;
    cout << "    ---------------" << endl;
    cout << "| ";
    for (i = 0; i <= 6; i++){
        cout << table[i] << " |";
    }
    cout << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

bool check_game_over(){
    if (table[0] == 0 && table[6] == 0 && quan0 != 0 && quan6 != 0){
        return true;
    }
    return false;
}

bool ban_trong(int turn){


    // khi 5 ô quân trống thì tự động rải mỗi ô 1 quân
    // nếu số quân < 5 thì thua
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
void rai_quan(){
    if (turn == 1){
        if (ban_trong(turn)){
            if (player1 < 5){
                game_over = false;
                ket_thuc();
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
                ket_thuc();
            }
        }
        for (int i = 7; i <= 11; i++){
            table[i]++;
            player2--;
        }
    }


}

int get_position(int turn){
    int p = -1;
    if (turn == 1){
            cout << "chon cac o 1, 2, 3, 4, 5" << endl;
            while ( !(p == 1 || p == 2 || p == 3 || p == 4 || p == 5) ){
                cout << "Chon o: ";
                cin >> p;
            }
    }
    if (turn == 2){
            cout << "chon cac o 7, 8, 9, 10, 11" << endl;
            while ( !(p == 7 || p == 8 || p == 9 || p == 10 || p == 11) ){
                cout << "Chon o: ";
                cin >> p;
            }
    }

    return p;
}

int get_new_position(int position, int direction){
    position += direction;

    if (position >= 0){
        return position % 12;
    } else {
        return position + 12;
    }

    return position;
}

int get_next_turn(int turn){
    if (turn == 1)
        return 2;
    return 1;
}

void di_quan(int position, int so_quan_hien_tai, int direction){
    // đi quân

    while (true){
        cout << "p: " << position << endl;
        if (so_quan_hien_tai == 0){
            break;
        }

        position = get_new_position(position, direction);
        table[position]++;
        so_quan_hien_tai--;

        if (so_quan_hien_tai == 0){
            position = get_new_position(position, direction);
            // phải khác 2 ô quan mới được lấy tiếp
            if (position != 0 && position != 6){
                so_quan_hien_tai = table[position];
                table[position] = 0;
            }
        }


        show_table();
        cout << endl;
        system("pause");
        cout << endl;

    }
    cout << "Xong " << position << endl;

    int so_quan_an_duoc = 0; // số quân ăn được
    while (table[position] == 0){
        int p1 = get_new_position(position, direction);
        cout << p1 << endl;
        if (table[p1] != 0){
            so_quan_an_duoc += table[p1];
            table[p1] = 0;
            position = get_new_position(position, 2*direction);
            if (p1 == 0){
                if (quan0 == 0){
                    quan0 == turn;
                }
                if (quan6 == 0){
                    quan6 == turn;
                }
            }
        }
        //show_table();
    }
    if (turn == 1){
        player1 += so_quan_an_duoc;
        so_quan_an_duoc = 0;
    }
    if (turn == 2){
        player2 += so_quan_an_duoc;
        so_quan_an_duoc = 0;
    }

}

void play_mode_1(){

    turn = 1;
    int position, direction;
    int so_quan_hien_tai;

    while (!game_over){

        show_table();
        cout << "Luot: " << turn << endl;
        if (ban_trong(turn)){
            rai_quan();
        }
        if (turn == 1){
            cout << "chon cac o 1, 2, 3, 4, 5" << endl;
        }
        else {
            cout << "chon cac o 7, 8, 9, 10, 11" << endl;
        }

        cout << "Chon o: ";
        cin >> position;

        //position = get_position(turn);

        cout << "Chon huong +1/-1: ";
        cin >> direction;
        // +1 la sang phai, -1 la sang trai
        // luu y turn 2
        /* if (turn == 2){
            direction *= -1;
        } */

        so_quan_hien_tai = table[position];
        table[position] = 0;
        di_quan(position, so_quan_hien_tai, direction);

        game_over = check_game_over();
        turn = get_next_turn(turn);
    }



}
