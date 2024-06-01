#include "../Include/BoardDraw.hpp"
/// @brief 보드출력 함수
/// @param board 보드
void BoardDraw::Print(const Board &board)
{
    // Clear the screen
    Common::ClearScreen();

    // Print the welcome message
    std::string space = std::string(3, (char)0x20);
    std::cout << space
              << Common::AnsiColor(207)
              << "\u2681\033[0m" << space;

    // Print column numbers
    for (int i = 0; i < board.size; ++i)
        std::cout << "\033[1;94m" << i << "\033[0m" << space;

    std::cout << "\n\n";

    // Print board
    for (int y = 0; y < board.size; ++y) {
        std::cout << space << "\033[1;94m" << y << "\033[0m" << space;

        for (int x = 0; x < board.size; ++x) {
            std::string symbol =
                (board.grid[y][x] == Player::USER)
                    ? "\033[1;91m\u2716\033[0m"        // red cross
                    : (board.grid[y][x] == Player::COMPUTER
                           ? "\033[1;92m\u25FC\033[0m" // green circle
                           : "\u25E6");
            std::cout << symbol << space;
        }
        std::cout << "\n\n";
    }

    sleep(1);

    int len = board.size * 2 + 1;
    std::string c = "\u2704 ";
    std::cout << space;
    std::cout << "\033[1;95m";
    std::fill_n(std::ostream_iterator<std::string>(std::cout), len, c);
    std::cout << "\033[0m"
              << "\n\n";
}
