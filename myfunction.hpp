#ifndef MYFUNCTION_HPP_INCLUDED
#define MYFUNCTION_HPP_INCLUDED

void init();

void ket_thuc();

int choose_mode();

void show_score();

void show_table();

bool check_game_over();

bool ban_trong();

bool now_empty(int position);

void rai_quan();

int get_position(int turn);

int get_new_position(int position, int direction);

int get_next_turn();

void di_quan();

void play_mode_1();

void play_mode_2();

void get_best_choice(int *position, int *direction);



#endif // MYFUNCTION_HPP_INCLUDED

