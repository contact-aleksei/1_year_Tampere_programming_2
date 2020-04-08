#include <iostream>
#include <string>
#include "player.hh"

using namespace std;

Player::Player(string name, int pts):
    name_(name), pts_(pts){
}
string Player::get_name() const{
    return name_;

}
int Player::get_points(){
    return pts_;
}
bool Player::has_won(){
    if (pts_==50){
    return true;
    }
    else{
    return false;
    }
}
void Player::add_points(int pts){
    pts_ += pts;
    if (pts_>50){
        cout<<name_ <<" gets penalty points!"<<endl;
        pts_=25;
    }
}


