#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>

using namespace std;

class Player
{
    public:
        Player(string name, int pts=0);
        string get_name() const;
        void add_points(int pts);
        bool has_won();
        int get_points();

    private:
        string name_;
        int    pts_;

};

#endif // PLAYER_HH
