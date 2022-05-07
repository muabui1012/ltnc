// bug ở đoạn ăn quân
// hàm kết thúc ván: thua do hết quân hoặc hết quan vơ quân về
//
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "mySDLfunction.hpp"
#include "myfunction.hpp"


using namespace std;

int table[12];

int quan0 = 0, quan6 = 0;

bool game_over = false;
int player1 = 0, player2 = 0;
int turn = 1; // (1 , 2)
int winner = 1; // (1, 2)
//int mode = 1; // 1: nguoi vs nguoi  || 2: nguoi vs may
SDL_Event e;
#define DELAY 50
int center_x, center_y;

void select_mode(int &mode){
    cout << "Select mode: ";
    cin >> mode;
}

void init(int arr[12]){

    for (int i = 1; i <= 5; i++){
        arr[i] = 5;
    }
    for (int i = 7; i <= 11; i++){
        arr[i] = 5;
    }
    arr[0] = 0;
    arr[6] = 0;

    /* quan6 = 1;
    quan0 = 0;
    a[3] = 1;
    */



}

void init(){

    for (int i = 1; i <= 5; i++){
        table[i] = 3;
    }
    for (int i = 7; i <= 11; i++){
        table[i] = 3;
    }


    /* quan6 = 1;
    quan0 = 0;
    table[3] = 1;
    */



}

int get_next_turn(int turn){
    if (turn == 1)
        return 2;
    return 1;
}

void end_round(int end_case, int turn){
    /*
        end_case:
        1: bàn trống và ko đủ quân để rải
        2: hết quan toàn dân vơ về

    */

    if (end_case == 1){
        cout << "Player 1: " << player1 << endl;
        cout << "Player 2: " << player2 << endl;
        int winner = get_next_turn(turn);
        cout << "Winner: " << winner << endl;
        return;
    }



    cout << "Het quan toan dan vo ve: " << endl;
    for (int i = 1; i <= 5; i++){
        player1 += table[i];
        table[i] = 0;
    }
    if (quan0 == 1){
        player1 += 5;
    }
    if (quan6 == 1){
        player1 += 5;
    }
    for (int i = 7; i <= 11; i++){
        player2 += table[i];
        table[i] = 0;
    }
    if (quan0 == 2){
        player2 += 5;
    }
    if (quan6 == 2){
        player2 += 5;
    }
    cout << "Player 1: " << player1 << endl;
    cout << "Player 2: " << player2 << endl;
    if (player1 > player2){
        cout << "Winner: " << 1 << endl;
    }
    else if (player1 < player2){
        cout << "Winner: " << 2 << endl;
    }
    else {
        cout << "Draw" << endl;
    }


    game_over = true;

    return;

}

int choose_mode(){
    int temp;
    cout << "Select_mode: ";
    cin >> temp;
    return temp;

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
        cout << "|  |";
    }

    int i;
    for (i = 11; i >= 7; i--){
        cout << table[i] << " |";
    }
    if (quan6 == 0){
        cout << "Z |";
    }
    else {
        cout << "  |";
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

bool now_empty(int position){
    if (position == 0){
        if (quan0 != 0 && table[position] == 0){
            return true;
        }
        else
            return false;
    }
    if (position == 6){
        if (quan6 != 0 && table[position] == 0){
            return true;
        }
        else
            return false;
    }
    if (table[position] == 0){
        return true;
    }
    else {
        return false;
    }

}

void rai_quan(){
    if (game_over)
        return;
    if (turn == 1){
        if (ban_trong(turn)){
            if (player1 < 5){
                game_over = false;
                end_round(1, turn);
            }
        }
        for (int i = 1; i <= 5; i++){
            table[i]++;
            SDL_draw_pieces(table[i], i);
            player1--;
        }
    }
    if (turn == 2){
        if (ban_trong(turn)){
            if (player2 < 5){
                game_over = false;
                end_round(2, turn);
        }
        for (int i = 7; i <= 11; i++){
            table[i]++;
            SDL_draw_pieces(table[i], i);
            player2--;
        }
    }


    }
}

int get_position(int turn){
    int p = -1;
//    if (turn == 1){
//            cout << "chon cac o 1, 2, 3, 4, 5" << endl;
//            while ( !(p == 1 || p == 2 || p == 3 || p == 4 || p == 5) ){
//                cout << "Chon o: ";
//                cin >> p;
//            }
//    }
//    if (turn == 2){
//            cout << "chon cac o 7, 8, 9, 10, 11" << endl;
//            while ( !(p == 7 || p == 8 || p == 9 || p == 10 || p == 11) ){
//                cout << "Chon o: ";
//                cin >> p;
//            }
//    }

    Uint32 buttons;
    int x, y;
    bool ok = false;
    while (!ok){
        SDL_PumpEvents();
        buttons = SDL_GetMouseState(&x, &y);
        if ((buttons & SDL_BUTTON_LMASK) != 0){
            SDL_Log("Mouse cursor is at %d, %d", x, y);
            p = SDL_find_i(x, y);
            //break;
            if (turn == 1 && table[p] != 0){
                if (p == 1 || p == 2 || p ==3 || p == 4 || p == 5){
                    ok = true;
                    break;
                }

            }
            if (turn == 2 && table[p] != 0){
                if (p == 7 || p == 8 || p ==9 || p == 10 || p == 11){
                    ok = true;
                    break;
                }

            }
        }
    }
    //p = SDL_find_i(x, y);
    return p;
}

int get_direction(int position, int turn, int center_x, int center_y){
    cout << "center: " << center_x << " " << center_y << endl;
    int x, y;
    Uint32 buttons;
    bool stop = false;
    while (true){
        SDL_PumpEvents();
        buttons = SDL_GetMouseState(&x , &y);
        if ((buttons & SDL_BUTTON_LMASK) != 0){
            break;
        }
        //cout << "current mouse: " << x << " " << y << endl;
    }
    cout << "mouse: " << x << " " << y << endl;
    //waitUntilKeyPressed();
    if (turn == 1){
        if (x > center_x)
            return 1;
        if (x < center_x)
            return -1;
    }
    if (turn == 2){
        if (x > center_x)
            return -1;
        if (x < center_x)
            return 1;
    }
}

int get_new_position(int position, int direction){

    position += direction;

    if (position >= 0){
        return position % 12;
    } else {
        return (position + 12) % 12;
    }

    return position;
}


void di_quan(int position, int so_quan_hien_tai, int direction){
    // đi quân
    //position = get_new_position(position, direction);
    while (so_quan_hien_tai != 0){
        position = get_new_position(position, direction);
        cout << "p: " << position << " " << so_quan_hien_tai - 1 << " " << endl;
        so_quan_hien_tai--;
        table[position]++;
        SDL_Delay(DELAY);
        SDL_draw_pieces(table[position], position);
        if (so_quan_hien_tai == 0){
            int temp_position = get_new_position(position, direction);
            if (temp_position != 0 && temp_position != 6){
                if (table[temp_position] != 0){
                    so_quan_hien_tai = table[temp_position];
                    table[temp_position] = 0;
                    SDL_draw_pieces(0, temp_position);
                    position = temp_position;
                }
            }
        }


    }


    // ăn quân
    int current_position = position;
    int next_position = get_new_position(current_position, direction);
    int second_next_position = get_new_position(next_position, direction);
    while (now_empty(next_position) && !(now_empty(second_next_position))){
        if (turn == 1)
            player1 += table[second_next_position];
        else
            player2 += table[second_next_position];
        table[second_next_position] = 0;
        SDL_Delay(DELAY);
        SDL_draw_pieces(0, second_next_position);
        if (second_next_position == 0){
            quan0 = turn;
            SDL_clear_quan0();
        }
        if (second_next_position == 6){
            quan6 = turn;
            SDL_clear_quan6();
        }
        current_position = second_next_position;
        next_position = get_new_position(current_position, direction);
        second_next_position = get_new_position(next_position, direction);

    }

}
void play_mode_1(){

    turn = 1;
    int position, direction;
    int so_quan_hien_tai;
    SDL_show_table();
    for (int i = 1; i <= 5; i++){
        SDL_draw_pieces(table[i], i);
    }
    for (int i = 7; i <= 11; i++){
        SDL_draw_pieces(table[i], i);
    }
    SDL_draw_quan0();
    SDL_draw_quan6();

    while (game_over == false){


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

//        cout << "Chon o: ";
//        cin >> position;

        position = get_position(turn);
        cout << "pos: " << position << endl;
        SDL_direction_arrow(position, turn, &center_x, &center_y);
        SDL_Delay(500);
        direction = get_direction(position, turn, center_x, center_y);
        cout << direction << endl;

        SDL_clear_direction_arrow(position, turn);
        //cout << "Chon huong +1/-1: ";
        //cin >> direction;
        // +1 la sang phai, -1 la sang trai
        // luu y turn 2
        /* if (turn == 2){
            direction *= -1;
        } */

        so_quan_hien_tai = table[position];
        table[position] = 0;
        SDL_draw_pieces(0, position);
        di_quan(position, so_quan_hien_tai, direction);

        game_over = check_game_over();
        turn = get_next_turn(turn);
    }

    end_round(2, turn);
}

void get_best_choice(int *position, int *direction){

    int len = 0;
    int a[5];
    for (int i = 7; i <= 11; i++){
        if (table[i] != 0){
            a[len] = i;
            len++;
        }
    }

    srand(time(NULL));
    int ran = rand()%len;

    *position = a[ran];

    int ran1 = rand()%2;

    if (ran1 == 0){
        *direction = 1;
    }
    else {
        *direction = -1;
    }



    return;
}

void play_mode_2(){

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

            cout << "Chon o: ";
            cin >> position;

            cout << "Chon huong +1/-1: ";
            cin >> direction;

            so_quan_hien_tai = table[position];
            table[position] = 0;
            di_quan(position, so_quan_hien_tai, direction);

            game_over = check_game_over();
            turn = get_next_turn(turn);
        }
        else {

            get_best_choice(&position, &direction);
            cout << position << " " << direction << "//" << endl;
            so_quan_hien_tai = table[position];
            table[position] = 0;
            di_quan(position, so_quan_hien_tai, direction);

            game_over = check_game_over();
            turn = get_next_turn(turn);
        }


    }
    end_round(2, turn);

    return;
}

string int_to_string(int n){
    if (n == 0)
        return "0";
    string res = "";
    while (n != 0){
        int digit = n % 10;
        char c_digit;
        c_digit = digit + '0';
        res = c_digit + res;
        n /= 10;
    }
    return res;
}

void SDL_test(){
    //SDL_Init();
    SDL_show_table();
//    SDL_draw_pieces(1, 1);
//    SDL_draw_pieces(1, 2);
//    waitUntilKeyPressed();
//    SDL_draw_pieces(0, 1);
//    SDL_draw_pieces(2, 2);
//    SDL_Delay(500);
    int i;
    int x, y;
    Uint32 buttons;
    bool stop = false;
    while (!stop){
        SDL_PumpEvents();
        SDL_find_mouse(&x, &y, stop);
        cout << "current mouse: " << x << " " << y << endl;
    }
    cout << "mouse: " << x << " " << y << endl;
    waitUntilKeyPressed();
}

