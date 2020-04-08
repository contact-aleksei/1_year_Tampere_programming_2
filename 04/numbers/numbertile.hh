#ifndef NUMBERTILE_HH
#define NUMBERTILE_HH
#include <utility>
#include <vector>

class NumberTile
{
public:
    // Public part contains variables and methods that can be used outside the
    // class itself.

    /* About pairs: the elements in a pair can be accessed with pair.first
    * and pair.second. If you do not wish to use pairs, you can modify the
    * given code to work without. Just replace the pair-parameter here & in the
    * source file with "int y, int x" and then modify the main.cpp in the
    * indicated spot.
    * */
    // Constructor that takes in a value, a location and the board the tile is on.
    NumberTile(int value);
    //, std::pair<int, int> coords,  std::vector<std::vector<NumberTile>> *board);

    // Prints the tile in the desired width.
    void print(int width);

    // Tries to set a new value to the tile. Returns true if successful, false
    // if the tile already contains some value.
    bool setValue(int value);

    int getValue() const;

private:
    // Private part contains variables and methods that shouldn't be usable
    // outside the class.

    // Value of the tile.
    int value_;
};

using Tiles = std::vector<NumberTile>;
using Board = std::vector<Tiles>;

#endif // NUMBERTILE_HH
