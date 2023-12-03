// Cell.hpp
#ifndef CELL_HPP
#define CELL_HPP

class Cell {
public:
    enum class State {
        Unopened,
        Opened,
        Flagged,
        Questioned
    };

    bool isMine;
    State state;
    int adjacentMines;

    Cell() : isMine(false), state(State::Unopened), adjacentMines(0) {}

    void open() {
        if (state == State::Unopened || state == State::Questioned) {
            state = State::Opened;
        }
    }

    void toggleFlag() {
        if (state == State::Unopened) {
            state = State::Flagged;
        } else if (state == State::Flagged) {
            state = State::Questioned;
        } else if (state == State::Questioned) {
            state = State::Unopened;
        }
    }
};

#endif

//Possible states:
//1. unopened tiles: blank and clickable (cover the board at the start of the game, can also be made by removing flags)
//2. opened tiles: exposed and unclickable
//2.1 numbered tiles (can show 1-8)
//2.2 blank tiles(no mines are on the diagonal/adjacent to the tile)
//3. flagged tiles: unopened cells marked by the player to indicate a potential mine location, unclickable
//4. (?) Question marked tiles (appear after right-clicking a flagged tile; only exists in certain implementations)
