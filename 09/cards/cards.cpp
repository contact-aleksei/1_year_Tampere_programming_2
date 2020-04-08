#include "cards.hh"

using namespace std;

// inititaor as top .. and bottom
Cards::Cards(): top_(nullptr), bottom_(nullptr){
}

Cards::~Cards(){
    while (top_ != nullptr){
        Card_data* delete_card = top_;
        top_ = top_ -> next_;
        // if you remove top, nearby card will become top
        // for destructor
        delete delete_card;
        // emptying the deck
    }
}

void Cards::add(int id){
    Card_data* new_card = new Card_data{id, nullptr};
    // if empty
    if (top_ == nullptr){
        top_ = new_card;
        bottom_ = new_card;
    }
    //if not
    else {
        new_card -> next_ = top_;
        top_ = new_card;
    }
}
bool Cards::remove(int& id){
    if ( is_deck_empty() ) {
       return false;
    }
    // remove card from the top
    Card_data* removed_card = top_;
    id = removed_card -> data_;
    // if there is the  only one card
    if ( top_ == bottom_ ) {
       top_ = nullptr;
       bottom_ = nullptr;
    } else {
       top_ = top_->next_;
    }
    delete removed_card;
    return true;
}

void Cards::print_from_top_to_bottom(std::ostream& s){
    Card_data* printing_card = top_;
    int counter=1;
    while ( printing_card != nullptr){
       s<<counter<< ": "<< printing_card->data_ << std::endl;
       counter+=1;
       printing_card = printing_card->next_;
    }

}

bool Cards::bottom_to_top(){
    if ( is_deck_empty() || top_ == bottom_) {
       return false;
    }
    Card_data* moving_card = bottom_;
    Card_data* to_the_bottom_c= top_;
    while (to_the_bottom_c != nullptr ){
        if (to_the_bottom_c-> next_ == moving_card){
            bottom_ =to_the_bottom_c;
        }
        to_the_bottom_c = to_the_bottom_c -> next_;
    }
    bottom_ -> next_ = nullptr;

    //pointer to the next card
    moving_card-> next_ = top_;
    // making a top
    top_ = moving_card;
    return true;
}

bool Cards::top_to_bottom(){
    if (top_ == bottom_||is_deck_empty()){
        return false;
    }
    bottom_->next_=top_;
    bottom_=top_;
    top_=bottom_->next_;
    bottom_->next_= nullptr;
    return true;
}

void Cards::print_from_bottom_to_top(std::ostream& s){
    int i = 1;
    s<<i<<": "<<bottom_->data_ <<endl;
    //we take bottom data and print .. going backwards
    i++;
    recursive_print(bottom_, s,i);
}

int Cards::recursive_print(Card_data* top, std::ostream& s, int& i){
    Card_data* check_card=top_;
    while (check_card  -> next_ != top){
        check_card  = check_card -> next_;
        if(top == top_){
            return 0;
        }
    }
    //printing until it reaches up
    top=check_card;
    s << i<<": "<<top->data_<<endl;
    ++i;
    return recursive_print( top, s, i);
}


// if there are no cards deck is empty
bool Cards::is_deck_empty() const {
    //if pointer is nullptr, deck is empty
    if (top_==nullptr){
      return true;
    }
    else {
      return false;
    }
}
