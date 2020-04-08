#include <iostream>
#include <memory>
#include "cards.hh"


Cards::Cards(): top_( nullptr ),bottom_( nullptr )  {

}

bool Cards::empty(){
    if (top_ != nullptr){
        return false;
    }
    else{
        return true;
    }
}
void Cards::add(int id) {
    if (empty()){
        std::shared_ptr<Card_data> new_card
                = std::make_shared<Card_data>(Card_data{id, nullptr,nullptr});
        top_ = new_card;
        bottom_ = new_card;
    }
    else{
        std::shared_ptr<Card_data> new_card
                    = std::make_shared<Card_data>(Card_data{id, top_, nullptr});
        top_->previous=new_card;
        top_=new_card;
        }

}

void Cards::print(std::ostream& s) {
   std::shared_ptr<Card_data> to_be_printed = top_;
   int nr = 1;

   while( to_be_printed != 0 ) {
      s << nr << ": " << to_be_printed->data << std::endl;
      to_be_printed = to_be_printed->next;
      ++nr;
   }
}
bool Cards::remove(int &id)
{
    if (not empty()){
        id=top_->data;
        top_=top_->next;
        top_->previous=nullptr;
        return true;
    }
    else{
        return false;
    }
}

void Cards::reverse(){
    if (not empty()){
        std::shared_ptr<Card_data> reversed = bottom_;
        bottom_=top_;
        top_=reversed;
        bottom_->next = nullptr;
        while(reversed != 0 ){
            reversed->next=reversed->previous;
            reversed=reversed->next;
        }
            top_->previous=nullptr;
    }
}



// Do not write the stubs of the methods remove and reverse by yourself here,
// but open the file reverse.hh and click the declaration of the method
// by the right mouse button and select
// Refactor > Add definition in reverse.cpp
