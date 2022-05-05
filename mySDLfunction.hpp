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



//--------
// custom functions

void SDL_Init();

void SDL_show_menu();

void SDL_ket_thuc();

void SDL_end_round(int end_case);

void SDL_show_score();

void SDL_show_table(int table[12]);

void SDL_show_table();

void SDL_draw_pieces(int num, int i);

void SDL_clear_pieces(int i);

#endif // MYSDLFUNCTION_HPP_INCLUDED
