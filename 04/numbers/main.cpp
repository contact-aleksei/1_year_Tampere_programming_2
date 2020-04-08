#include "numbertile.hh"
#include <iostream>
#include <vector>
#include <random>
#include <string>

const int SIZE = 4;
const int NEW_VALUE = 2;
const int PRINT_WIDTH = 5;
const int DEFAULT_GOAL = 2048;

// Key commands
const std::string RIGHT = "d";
const std::string LEFT = "a";
const std::string UP = "w";
const std::string DOWN = "s";
const std::string QUIT = "q";

/**
 * @brief get       Fetch a specific value from game board.
 * @param board     Game board where we retrieve value.
 * @param y         Y axis of the game board to fetch.
 * @param x         X axis of the row to fetch.
 * @return          Integer located at ( y, x ).
 */
int get(const Board &board,
        int y, int x)
{
    return board.at(y).at(x).getValue();
}

void set(Board &board,
         int y, int x, int value)
{
    board.at(y).at(x).setValue(value);
}

// Adds a single new value to board using rEng and distr for random positioning.
void newValue(Board &board,
              std::default_random_engine &rEng,
              std::uniform_int_distribution<int> &distr)
{
    // Tries to assign NEW_VAl to randomly selected tile. Continues trying until
    // newVal() returns true.
    while (true)
    {
        int x = distr(rEng);
        int y = distr(rEng);

        if (get(board, y, x) == 0)
        {
            board.at(y).at(x).setValue(NEW_VALUE);
            return;
        }
    }
}

// Initializes the board to size SIZE x SIZE and adds SIZE tiles with NEW_VALUE
// to it through new_value() func after initializing the random engine with
// a seed value.
void initBoard(Board &board,
               std::default_random_engine &rEng,
               std::uniform_int_distribution<int> &distr)
{

    // Initialize the board with SIZE x SIZE empty numbertiles.
    for (auto y = 0; y < SIZE; y++)
    {
        board.push_back({});
        for (auto x = 0; x < SIZE; x++)
        {
            // If you don't want to use pairs, replace "std::make_pair(y, x)"
            // with "y, x".
            board.at(y).push_back(NumberTile(0));
        }
    }

    // Ask user for the seed value and initialize rEng.
    std::cout << "Give a seed value or an empty line: ";
    std::string seed = "";
    getline(std::cin, seed);

    if (seed == "")
    {
        // If the user did not give a seed value, use computer time as the seed
        // value.
        rEng.seed(time(NULL));
    }
    else
    {
        // If the user gave a seed value, use it.
        rEng.seed(stoi(seed));
    }

    // Add some tiles to the board.
    for (int i = 0; i < SIZE; ++i)
    {
        newValue(board, rEng, distr);
    }
}

/**
 * @brief isNumber  Check if the user inputs an integer.
 * @param s         User input string.
 * @return          If user input else than number, false.
 *                  Otherwise, true.
 */
bool isNumber(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

/**
 * @brief setGoal   Set final goal for winning the game.
 * @param goal      Reference for goal value.
 */
void setGoal(int &goal)
{
    std::string goal_value = "";
    do
    {
        std::cout << "Give a goal value or an empty line: ";
        getline(std::cin, goal_value);
    }
    // Ask again, if the user inputs not number.
    while (!isNumber(goal_value) and goal_value != "");

    if (goal_value == "")
    {
        // If the user did not give a goal value,
        // use the default goal value.
        goal = DEFAULT_GOAL;
    }
    else
    {
        // If the user gave a goal value, use it.
        goal = std::stoi(goal_value);
    }
}
// Prints the board.
void print(Board &board)
{
    // The y isn't actually the y coordinate or some int, but an iterator that
    // is like a vector of NumberTiles.
    for (auto y : board)
    {
        // Prints a row of dashes.
        std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
        // And then print all cells in the desired width.
        for (auto x : y)
        {
            x.print(PRINT_WIDTH);
        }
        // And a line after each row.
        std::cout << "|" << std::endl;
    }
    // Print a last row of dashes so that the board looks complete.
    std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
}

/**
 * @brief removeZeros   Remove all zeros from the game board before compressing.
 * @param board         Game board where we want to remove zeros.
 * @param isRow         If the command is related to horizontal movement, true.
 *                      If it is related to vertical movement, false.
 * @return              Game board after removing zeros.
 */
Board removeZeros(const Board &board, const bool &isRow)
{
    Board removedBoard;
    for (auto y = 0; y < SIZE; ++y)
    {
        removedBoard.push_back({});
        for (auto x = 0; x < SIZE; ++x)
        {
            int value = 0;
            // If the command is horizontal movement, get value by row.
            if (isRow)
            {
                value = get(board, y, x);
            }
            // If the command is vertical movement, get value by column.
            else
            {
                value = get(board, x, y);
            }

            // Push value only if it is not 0.
            if (value != 0)
            {
                removedBoard.at(y).push_back(value);
            }
        }
    }
    return removedBoard;
}

void mirrorNumbers(Board &board, const bool &isRow)
{
    Board copied = board;
    for (auto y = 0; y < SIZE; ++y)
    {
        for (auto x = 0; x < SIZE; ++x)
        {
            // Mirror in vertical.
            // Means flipping left side to right.s
            if (isRow)
            {
                auto value = get(copied, y, SIZE - 1 - x);
                set(board, y, x, value);
            }
            // Mirorr in horizontal.
            // Menas flipping up side down.
            else
            {
                auto value = get(copied, SIZE - 1 - y, x);
                set(board, y, x, value);
            }
        }
    }
}

/**
 * @brief compressNumbers   Compress number tiles, if there is sequence of same numbers.
 * @param board             Game board to compress numbers.
 * @return                  Game board after compressing.
 */
Board compressNumbers(const Board &board)
{
    Board compressedBoard;
    for (Board::size_type y = 0; y < board.size(); ++y)
    {
        compressedBoard.push_back({});
        Tiles::size_type rowSize = board.at(y).size();
        // If the vector is empty, skip the stage.
        if (rowSize == 0)
            continue;
        // If the vector contains only one value, just add it.
        else if (rowSize == 1)
        {
            auto current = get(board, y, 0);
            compressedBoard.at(y).push_back(current);
            continue;
        }

        // If the vector has more than one element.
        for (Tiles::size_type x = 0; x < rowSize; ++x)
        {
            auto current = get(board, y, x);
            int next = 0;
            // Get next value, only if x is in range of the vector.
            if (x < rowSize - 1)
            {
                next = get(board, y, x + 1);
            }

            // Compare numbers next each other.
            if (current == next)
            {
                compressedBoard.at(y).push_back(current + next);
                // If current and next have same value, skip one more step.
                ++x;
            }
            else
            {
                compressedBoard.at(y).push_back(current);
            }
        }
    }
    return compressedBoard;
}

void reassignNumbers(Board &original, const Board &compressedBoard, const bool &isRow)
{
    // Create new board with value 0.
    Board newBoard;
    for (auto y = 0; y < SIZE; ++y)
    {
        newBoard.push_back({});
        for (auto x = 0; x < SIZE; ++x)
        {
            newBoard.at(y).push_back(0);
        }
    }

    // Assign values from compressed board to new board.
    for (Board::size_type y = 0; y < compressedBoard.size(); ++y)
    {
        for (Tiles::size_type x = 0; x < compressedBoard.at(y).size(); ++x)
        {
            if (isRow)
            {
                // If the movement is related to horizontal, fill the value in row.
                newBoard.at(y).at(x) = compressedBoard.at(y).at(x);
            }
            else
            {
                // If the movement is related to vertical, fill the value in column.
                newBoard.at(x).at(y) = compressedBoard.at(y).at(x);
            }
        }
    }
    original = newBoard;
}

void moveNumbers(Board &board, const bool &isRow, const bool &isNormal)
{
    // Mirror the board if the command is either right or down.
    if (!isNormal)
        mirrorNumbers(board, isRow);

    // Remove number tiles having 0.
    Board refinedBoard = removeZeros(board, isRow);

    // Compress numbers
    refinedBoard = compressNumbers(refinedBoard);

    // Reassign to new matrix
    reassignNumbers(board, refinedBoard, isRow);

    // Mirror back after movement.
    if (!isNormal)
        mirrorNumbers(board, isRow);
}

bool isEqual(Board &oldBoard, Board &updatedBoard)
{
    for (auto y = 0; y < SIZE; ++y)
    {
        for (auto x = 0; x < SIZE; ++x)
        {
            if (get(oldBoard, y, x) != get(updatedBoard, y, x))
            {
                return false;
            }
        }
    }
    return true;
}

bool hasWon(const Board &board, const int &goal)
{
    for (auto y = 0; y < SIZE; ++y)
    {
        for (auto x = 0; x < SIZE; ++x)
        {
            if (get(board, y, x) == goal)
            {
                return true;
            }
        }
    }
    return false;
}

bool hasLose(Board &board)
{
    bool isLose = true;
    // Check all possible movement.
    for (unsigned int i = 0; i < 2; ++i)
    {
        for (unsigned int j = 0; j < 2; ++j)
        {
            Board copied = board;
            moveNumbers(copied, i, j);
            // Compare change.
            // If there is change, it means the game can be continued.
            if (!isEqual(board, copied))
            {
                isLose = false;
            }
        }
    }
    return isLose;
}

int main()
{
    // Declare the board and randomengine.
    Board board;
    std::default_random_engine randomEng;
    // And initialize the disrt to give numbers from the correct
    std::uniform_int_distribution<int> distr(0, SIZE - 1);

    int goal_value = 0;

    initBoard(board, randomEng, distr);
    setGoal(goal_value);

    // Start game
    std::string direction = "";

    /** Stop the game, if :
     * - the user entered QUIT key.
     * - the game is no longer able to continue.
     * - the user won the game by reaching the goal value.
     */
    while (true)
    {
        print(board);
        Board oldBoard = board;

        // Ask user for a direction
        std::cout << "Dir> ";
        std::getline(std::cin, direction);
        if (direction == QUIT)
        {
            // End game.
            return EXIT_SUCCESS;
        }
        else if (direction == LEFT)
        {
            moveNumbers(board, true, true);
        }
        else if (direction == RIGHT)
        {
            moveNumbers(board, true, false);
        }
        else if (direction == UP)
        {
            moveNumbers(board, false, true);
        }
        else if (direction == DOWN)
        {
            moveNumbers(board, false, false);
        }
        else
        {
            std::cout << "Error: unknown command." << std::endl;
        }
        // Winning condition
        if (hasWon(board, goal_value))
        {
            print(board);
            std::cout << "You reached the goal value of " << goal_value << "!" << std::endl;
            return EXIT_SUCCESS;
        }
        // Losing condition
        if (hasLose(board))
        {
            std::cout << "Can't add new tile, you lost!" << std::endl;
            return EXIT_SUCCESS;
        }

        // If the board has been changed,
        // Add value
        if (!isEqual(oldBoard, board))
        {
            newValue(board, randomEng, distr);
        }
    }
}
