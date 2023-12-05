// Cell.hpp
#ifndef CELL_HPP
#define CELL_HPP

template<typename T>
// template for how cell is generated
class Cell {
public:
    enum class State {
        Unopened,
        Opened,
        Flagged,
        Questioned
    };

    T value;
    State state;

    Cell() : value(T()), state(State::Unopened) {}

    void open();
    void toggleFlag();
};

#endif

//Possible states:
//1. unopened tiles: blank and clickable (cover the board at the start of the game, can also be made by removing flags)
//2. opened tiles: exposed and unclickable
//2.1 numbered tiles (can show 1-8)
//2.2 blank tiles(no mines are on the diagonal/adjacent to the tile)
//3. flagged tiles: unopened cells marked by the player to indicate a potential mine location, unclickable
//4. (?) Question marked tiles (appear after right-clicking a flagged tile; only exists in certain implementations)
