// Command version
#include <iostream>
#include "myfunction.hpp"
#include "mySDLfunction.hpp"


using namespace std;

int mode = 1;

int main(int argc, char* argv[]){

    init();
    show_menu();
    select_mode(mode);
    if (mode == 1){
        play_mode_1();

    }
    else {
        play_mode_2;
    }


    return 0;
}





