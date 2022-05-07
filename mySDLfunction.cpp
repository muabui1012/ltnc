#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "mySDLfunction.hpp"
#include "myfunction.hpp"


using namespace std;


//
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;
    const string WINDOW_TITLE = "Oquan SDL2";
//
SDL_Window* window = NULL;
SDL_Renderer* renderer;
SDL_Texture *table_Img, *pieces_Img,
            *menu_Img, *quan0_Img, *quan6_Img, *arrow_Img, *clear_arrow_Img,
            *clear_quan0_Img, *clear_quan6_Img;

SDL_Texture *Img_ar[51];

struct cell{
    int x;
    int y;
    init(int m, int n){
        x = m;
        y = n;

    }
};

cell cell_pos[12];
cell cell_down_right_pos[12];

void SDL_Init(){
    load_SDL_and_Images();

    //cout << cell_pos[1].x << " " << cell_pos[1].y;
    cell_pos[0].init(155, 365);
    cell_pos[1].init(260, 410);
    cell_pos[2].init(380, 410);
    cell_pos[3].init(500, 410);
    cell_pos[4].init(620, 410);
    cell_pos[5].init(740, 410);
    cell_pos[6].init(860, 365);
    cell_pos[7].init(740, 300);
    cell_pos[8].init(620, 300);
    cell_pos[9].init(500, 300);
    cell_pos[10].init(380, 300);
    cell_pos[11].init(260, 300);



}

void SDL_show_table(int a[12]){
    SDL_RenderClear(renderer);
    renderTexture(table_Img, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);
    for (int i = 0; i <= 11; i++){
        SDL_draw_pieces(a[i], i);
    }


}

void SDL_show_table(){
    SDL_RenderClear(renderer);
    renderTexture(table_Img, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);

}

void load_SDL_and_Images(){
    initSDL(window, renderer);
    table_Img = loadTexture("Image/table.png", renderer);
    if (table_Img == nullptr){
        unload_SDL_and_Images();
        exit(1);
    }
    for (int i = 0; i <= 25; i++){
        string name;
        name = "Image/" + int_to_string(i) + ".png";
        Img_ar[i] = loadTexture(name, renderer);
        if (Img_ar[i] == nullptr){
            unload_SDL_and_Images();
            cout << "SDL error";
            exit(1);
            return;
        }
    }

    quan0_Img = loadTexture("Image/quan0.png", renderer);
    quan6_Img = loadTexture("Image/quan6.png", renderer);
    clear_quan0_Img = loadTexture("Image/clear_quan.png", renderer);
    clear_quan6_Img = loadTexture("Image/clear_quan.png", renderer);

    arrow_Img = loadTexture("Image/direction.png", renderer);
    clear_arrow_Img = loadTexture("Image/direction_empty.png", renderer);

}


void unload_SDL_and_Images(){
    SDL_DestroyTexture(table_Img);
    SDL_DestroyTexture(menu_Img);
    for (int i = 0; i <= 25; i++){
        SDL_DestroyTexture(Img_ar[i]);
    }

    SDL_DestroyTexture(quan0_Img);
    SDL_DestroyTexture(quan6_Img);
    SDL_DestroyTexture(arrow_Img);
    SDL_DestroyTexture(clear_arrow_Img);
    SDL_DestroyTexture(clear_quan0_Img);
    SDL_DestroyTexture(clear_quan6_Img);
    quitSDL(window, renderer);

}

void SDL_draw_pieces(int num, int i){
    //waitUntilKeyPressed();
    if (i != 0 && i != 6){
        renderTexture(Img_ar[num], renderer, cell_pos[i].x, cell_pos[i].y);
        SDL_RenderPresent(renderer);
    }
    else {
        renderTexture(Img_ar[num], renderer, cell_pos[i].x, cell_pos[i].y, 80, 80);
        SDL_RenderPresent(renderer);
    if (i == 0){

    }
//        if (i == 0 && quan0 == 0){
//            renderTexture(quan0_Img, renderer, 200, 310, 45, 45);
//            SDL_RenderPresent(renderer);
//        }
//        if (i == 6 && quan6 == 0){
//            renderTexture(quan6_Img, renderer, 860, 450, 45, 45);
//            SDL_RenderPresent(renderer);
//        }


    }

}


void SDL_clear_pieces(int i){
    if (i == 0){
        renderTexture(clear_quan0_Img, renderer, 200, 310, 45, 45);
        SDL_RenderPresent(renderer);
    }
    if (i == 6){
        renderTexture(clear_quan6_Img, renderer, 860, 450, 45, 45);
        SDL_RenderPresent(renderer);
    }
    renderTexture(Img_ar[0], renderer, cell_pos[i].x, cell_pos[i].y);
    //SDL_RenderClear(renderer);

}



void SDL_find_mouse(int *x, int *y, bool &stop){
    if (stop){
        return;
    }
    Uint32 buttons;
    int xx, yy;
    buttons = SDL_GetMouseState(&xx, &yy);
    *x = xx;
    *y = yy;
    if ((buttons & SDL_BUTTON_LMASK) != 0){
        /* *x = xx;
        *y = yy; */
		stop = true;
    }

    //
}

#define arrow_Img_size_x 96
#define arrow_Img_size_y 39
void SDL_direction_arrow(int i, int turn, int *center_x, int *center_y){
    int m;
    if (turn == 1)
        m = 120;
    else
        m = -50;
    renderTexture(arrow_Img, renderer, cell_pos[i].x + 3, cell_pos[i].y + m);
    SDL_RenderPresent(renderer);
    *center_x = cell_pos[i].x + 3 + (arrow_Img_size_x /2);
    *center_y = cell_pos[i].y + m;
}

int SDL_find_i(int x, int y){
    int p = -1;
    for (int i = 1; i <= 5; i++){
        if ( x >= cell_pos[i].x && y >= cell_pos[i].y && x <= (cell_pos[i].x + 100) && y <= (cell_pos[i].y + 100) )
            return i;
    }
    for (int i = 7; i <= 11; i++){
        if ( x >= cell_pos[i].x && y >= cell_pos[i].y && x <= (cell_pos[i].x + 100) && y <= (cell_pos[i].y + 100) )
            return i;
    }
    return p;
}

void SDL_clear_direction_arrow(int i, int turn){
    int m;
    if (turn == 1)
        m = 120;
    else
        m = -50;
    renderTexture(clear_arrow_Img, renderer, cell_pos[i].x + 3, cell_pos[i].y + m);
    SDL_RenderPresent(renderer);
}

void SDL_clear_quan0(){
    renderTexture(clear_quan0_Img, renderer, 200, 310, 45, 45);
    SDL_RenderPresent(renderer);
}


void SDL_clear_quan6(){
    renderTexture(clear_quan6_Img, renderer, 860, 450, 45, 45);
    SDL_RenderPresent(renderer);
}

void SDL_draw_quan0(){
    renderTexture(quan0_Img, renderer, 200, 310, 45, 45);
    SDL_RenderPresent(renderer);
}


void SDL_draw_quan6(){
    renderTexture(quan6_Img, renderer, 860, 450, 45, 45);
    SDL_RenderPresent(renderer);
}

//**********************************
// Các hàm chung về khởi tạo và huỷ SDL
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

/**
* Nạp một ảnh bitmap (BMP) vào một texture trên thiết bị hiện thị (rendering device)
* @param file: đường dẫn và tên file ảnh BMP
* @param ren: renderer để nạp texture lên
* @return trả về texture đã nạp, hoặc nullptr nếu có lỗi.
*/
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	//Khởi tạo là nullptr để tránh lỗi 'dangling pointer'
	SDL_Texture *texture = nullptr;
	//Nạp ảnh từ tên file (với đường dẫn)
	SDL_Surface *loadedImage = IMG_Load(file.c_str());
	//Nếu không có lỗi, chuyển đổi về dạng texture and và trả về
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Đảm bảo việc chuyển đổi không có lỗi
		if (texture == nullptr){
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP");
	}
	return texture;
}

/**
* Vẽ một SDL_Texture lên một SDL_Renderer tại toạ độ (x, y), trong khi
* giữ nguyên chiều rộng và cao của ảnh
* @param tex: texture nguồn chúng ta muốn vẽ ra
* @param ren: thiết bị renderer chúng ta muốn vẽ vào
* @param x: hoành độ
* @param y: tung độ
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	//Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Truy vẫn texture để lấy chiều rộng và cao (vào chiều rộng và cao tương ứng của hình chữ nhật đích)
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    //Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
* Vẽ một SDL_Texture lên một SDL_Renderer tại toạ độ (x, y), với
* chiều rộng và cao mới
* @param tex: texture nguồn chúng ta muốn vẽ ra
* @param ren: thiết bị renderer chúng ta muốn vẽ vào
* @param x: hoành độ
* @param y: tung độ
* @param w: chiều rộng (mới)
* @param h: độ cao (mới)
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	//Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
    dst.w = w;
    dst.h = h;
    //Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
    //(ảnh sẽ co dãn cho khớp với kích cỡ mới)
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
//**************************************************************
