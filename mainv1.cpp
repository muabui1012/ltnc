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


    mode = 0;
    bool stop = false;
    SDL_Event e;
    while (!stop){
        SDL_Init();
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT){
                stop = true;
                //SDL_Quit();
            }
            init();
            //SDL_Init();
            //SDL_PumpEvents();

            while (mode == 0){
                mode = SDL_select_mode();

            }
            cout << mode << endl;
            if( e.type == SDL_QUIT )
                return 0;

            if (mode == 1){
                play_mode_1();
                //waitUntilKeyPressed();
            }
            else {
                play_mode_2();
                //waitUntilKeyPressed();
            }
            SDL_Quit();
            mode = 0;

        }
    }
    //play_mode_1();
    //SDL_test();
    //unload_SDL_and_Images();
    return 0;
}





