// SDL2 version
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

#include "myfunction.hpp"
#include "mySDLfunction.hpp"


using namespace std;

int mode = 1;


int main(int argc, char* argv[]){

    /* init();
    show_menu();
    select_mode(mode);
    if (mode == 1){

        play_mode_1();

    }
    else {
        play_mode_2();
    }
    */

    //int a[12];
    init();
    SDL_Init();
    play_mode_1();

    return 0;
}





