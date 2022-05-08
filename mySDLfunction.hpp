#ifndef MYSDLFUNCTION_HPP_INCLUDED
#define MYSDLFUNCTION_HPP_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "mySDLfunction.hpp"
#include "myfunction.hpp"

using namespace std;

// General SDL functions

void load_SDL_and_Images();
void unload_SDL_and_Images();
void clear_cell(int x, int y);
void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
void close();


//--------
// custom functions

void SDL_Init();

int SDL_select_mode();

void SDL_show_menu();

void SDL_show_end(int player);

void SDL_show_score();

void SDL_show_table(int table[12]);

void SDL_show_table();

void SDL_draw_pieces(int num, int i);

void SDL_clear_pieces(int i);

void SDL_draw_pieces(int num, int x, int y);

void SDL_clear_pieces(int x, int y);

void SDL_direction_arrow(int i, int turn, int *center_x, int *center_y);

void SDL_clear_direction_arrow(int i, int turn);

void SDL_find_mouse(int *x, int *y, bool &stop);

int SDL_find_i(int x, int y);

void SDL_clear_quan0();

void SDL_clear_quan6();

void SDL_draw_quan0();

void SDL_draw_quan6();

void SDL_draw_quan(int turn, int quan);

void SDL_draw_score(int score, int turn);

void SDL_draw_turn(int turn);

void SDL_clear_turn(int turn);

void SDL_draw_hand(int turn);

void SDL_clear_hand(int turn);

void SDL_msg();
#endif // MYSDLFUNCTION_HPP_INCLUDED
