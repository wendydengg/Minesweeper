// Cell.tpp

template <typename T>
class Cell {
    T value;
    bool revealed;
    bool flagged;

public:
    Cell() : value(T()), revealed(false), flagged(false) {}

    // Methods for setting and getting cell properties
};
