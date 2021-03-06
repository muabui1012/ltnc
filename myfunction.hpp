#ifndef MYFUNCTION_HPP_INCLUDED
#define MYFUNCTION_HPP_INCLUDED
using namespace std;

void init();

void show_menu();

void get_mode_from_main(int &mode);

void select_mode(int &mode);

void ket_thuc();

void end_round(int end_case, int turn);

int choose_mode();

void show_score();

void show_table();

bool check_game_over();

bool ban_trong();

bool now_empty(int position);

void rai_quan();

int get_position(int position, int turn);

int get_direction(int position, int turn, int center_x, int center_y);

int get_new_position(int position, int direction);

int get_next_turn(int turn);

void di_quan();

void play_mode_1();

void play_mode_2();

void get_best_choice(int *position, int *direction);

string int_to_string(int n);

void SDL_test();

#endif // MYFUNCTION_HPP_INCLUDED

