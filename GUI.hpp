// GUI.hpp
#pragma once
#include "SFML/Graphics.hpp"
#include "Board.hpp"
#include <memory>
#include <chrono>

template <typename T>
class GUI {
private:
    std::unique_ptr<Board<T>> board;
    sf::RenderWindow window;
    sf::Font font;

    // Game state and settings
    bool gameOver;
    int mineCount;
    int flagsUsed;
    int hintsRemaining;
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::duration<float> elapsedTime;

    // GUI elements
    sf::Text timerText;
    sf::Text mineCountText;
    sf::Text hintText;
    sf::RectangleShape restartButton;
    sf::RectangleShape hintButton;
    sf::RectangleShape flagButton;

    // Private methods for handling game logic
    void handleInput();
    void updateGame();
    void draw();

public:
    GUI(int width, int height, int mineCount);
    void run();
};


//restart button
//timer: recording time to finish the game
//hint button, can only click 3 times
//flag button
//number of remaining bombs (minecount = total number of mines subtracted by the number of flagged cells (thus the minecount can be negative if too many flags have been placed))
