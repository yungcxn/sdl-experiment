#include "./game.h"

int main(int argc, char* argv[]) {
    game_setup();
    game_mainloop();
    game_destroy();
    return 0;
}