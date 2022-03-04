// Command version


#include <iostream>


using namespace std;

int table[12];
bool quan0 = true, quan6 = true;
int player1 = 0, player2 = 0;

void init(){

    for (int i = 1; i <= 5; i++){
        table[i] = 5;
    }
    for (int i = 7; i <= 11; i++){
        table[i] = 5;
    }


}

void show_table(){
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


int main(int argc, char* argv[]){


    init();
    show_table();

    while (true)







    return 0;
}





