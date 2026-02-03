#include "../Headers/Game.hpp"
#include "../Headers/Exceptions.hpp"
Game* Game::instance=nullptr;
int main() {
    srand(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    try {
        Game* game=Game::getInstance();
        while (game->isRunning()) {
            game->update();
            game->render();

        }
        game->afis();
    }
    catch (const std::exception& e) {
        std::cerr << "Valeu" << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
