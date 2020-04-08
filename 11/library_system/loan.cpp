#include "loan.hh"
#include <iostream>

using namespace std;
Loan::Loan(const std::string& names_of_borrowers, std::vector<Loan*> borrowed_books,
            std::string borrowings, std::set<std::string> update_of_borrowed_books) :
    names_of_borrowers_ (names_of_borrowers),
    borrowed_books_(borrowed_books),
    borrowings_(borrowings),
    update_of_borrowed_books_(update_of_borrowed_books)
{
}
Loan::~Loan()
{
}
std::string Loan::get_names() const
{
    return names_of_borrowers_ ;
}

std::vector<Loan*> Loan::get_books() const
{
    return borrowed_books_;
}

void Loan::print_info_loan() const
{
    for ( auto authors : names_of_borrowers_ ){
        std::cout << authors->get_names();
        if ( names_of_borrowers != names_of_borrowers_.back() ){
            std::cout << ": ";
        }
    }
    std::cout << std::endl;
}


void Loan::loaned_books()
{/*


    if (borrowed_books.empty()){
        return;
        }
    else{
        cout<<LOAN_INFO<<endl;
        multimap <string, string> :: iterator itr;
        for (itr=borrowings_.begin(); itr!= borrowings_.end(); ++itr){
            cout << itr->second << " : " << itr->first << " : ";
            cout<<today_->to_string()<< " :";
            cout<<" 0"<<endl;
        }*/
    return borrowed_books_;
}

void Loan::loans_by(const std::string &borrower)
{
//    if ( accounts_.find(borrower) == accounts_.end()){
//        //fine works
//        std::cout << CANT_FIND_ACCOUNT_ERROR << std::endl;
//        return;
//        //fine works
//    }
//    multimap<string, string>:: iterator itr;
//    for (itr = borrowings_.find(borrower); itr != borrowings_.end(); itr++){
//        if (itr->first == borrower){
//            cout << itr->second << " : ";
//            cout<<today_->to_string()<< " :";
//            cout<<" 0"<<endl;
//          }
//        else{
//            return;
//        }
//    }
//}

//void Loan::loan(const std::string &book_title, const std::string &borrower_id)
//{
//    if ( accounts_.find(borrower_id) == accounts_.end()){
//        std::cout << CANT_FIND_ACCOUNT_ERROR << std::endl;
//        return;
//    }
//    else if ( books_.find(book_title) == books_.end()){
//        std::cout << CANT_FIND_BOOK_ERROR << std::endl;
//        return;
//    }
//    else if ((borrowed_books_.find(book_title))!= borrowed_books_.end()){
//        std::cout << ALREADY_LOANED_ERROR<< std::endl;
//        return;
//    }
//    else {
//        borrowings_.insert(make_pair(borrower_id,book_title));
//        names_of_borrowers_ .insert(borrower_id);
//        borrowed_books_.insert(book_title);
//        return;
//    }
}

void Loan::renew_loan(const std::string &book_title)
{
//    if ( books_.find(book_title) == books_.end()){
//        std::cout << CANT_FIND_BOOK_ERROR << std::endl;
//        return;
//    }
//    else{
//        if ((borrowed_books_.find(book_title))!= borrowed_books_.end()){
//            int k=0;
//            multimap<string, int>:: iterator itr;
//            for (itr = update_of_borrowed_books_.find(book_title); itr != update_of_borrowed_books_.end(); itr++){
//                if (itr->first == book_title){
//                    k++;
//                }
//            }
//            if (k==3){
//                cout <<OUT_OF_RENEWALS_ERROR<<endl;
//            }
//            else{
//                cout <<RENEWAL_SUCCESSFUL;
//                today_->advance_by_loan_length();
//                cout<<today_->to_string()<<endl;
//                update_of_borrowed_books_.insert(make_pair(book_title,1));
//            }
//        }
//        else{
//            cout<<LOAN_NOT_FOUND_ERROR<<endl;
//            return;
//        }
//    }
}

void Loan::return_loan(const std::string &book_title)
{
//    if ( books_.find(book_title) == books_.end()){
//        std::cout << CANT_FIND_BOOK_ERROR << std::endl;
//        return;
//    }
//    else if ((borrowed_books_.find(book_title))== borrowed_books_.end()){
//        std::cout << LOAN_NOT_FOUND_ERROR << std::endl;
//        return;
//    }
//    else{
//        borrowings_.erase(book_title);
//        borrowed_books_.erase(book_title);
//        names_of_borrowers_.erase(book_title);
//        return;
//    }
}
