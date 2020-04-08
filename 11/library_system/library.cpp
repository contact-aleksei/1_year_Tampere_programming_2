#include "library.hh"
#include <iostream>
using namespace std;
// Let's use the date when the project was published as the first date.
Library::Library():
    today_(new Date(13, 11, 2019)),
    books_({}),
    authors_({}),
    accounts_({}),
    loans_({})
{

}

Library::~Library()
{
    // Free all memory reserved with the keyword new.
    delete today_; today_ = nullptr;
    for ( std::pair<std::string, Book*> book : books_ ){
        delete book.second;
        book.second = nullptr;
    }
    for ( std::pair<std::string, Person*> author : authors_ ){
        delete author.second;
        author.second = nullptr;
    }
    for ( std::pair<std::string, Person*> account : accounts_ ){
        delete account.second;
        account.second = nullptr;
    }

    for ( std::pair<std::string, Loan*> loan : loans_ ){
        delete loan.second;
        loan.second = nullptr;
    }
}

void Library::all_books()
{
    for ( std::pair<std::string, Book*> book : books_ ){
        std::cout << book.first << std::endl;
    }
}

void Library::all_books_with_info()
{
    std::cout << SEPARATOR_LINE << std::endl;
    for ( std::pair<std::string, Book*> book : books_ ){
        book.second->print_info();
        std::cout << SEPARATOR_LINE << std::endl;
    }
}

void Library::all_borrowers()
{
    for ( std::pair<std::string, Person*> borrower : accounts_ ){
        std::cout << borrower.first << std::endl;
    }
}

void Library::all_borrowers_with_info()
{
    std::cout << SEPARATOR_LINE << std::endl;
    for ( std::pair<std::string, Person*> borrower : accounts_ ){
        borrower.second->print_info();
        std::cout << SEPARATOR_LINE << std::endl;
    }
}

bool Library::add_book(const std::string &title, const std::vector<std::string> authors, const std::string &description, const std::set<std::string> genres)
{
    if ( authors.empty() ){
        std::cout << MISSING_AUTHOR_ERROR << std::endl;
        return false;
    }
    std::vector<Person*> author_ptrs;
    for ( std::string author : authors ){
        Person* n_person;
        if ( authors_.find(author) == authors_.end() ){
            n_person = new Person(author, "", "");
            authors_.insert({author, n_person});
        } else {
            n_person = authors_.at(author);
        }
        author_ptrs.push_back(n_person);
    }
    Book* n_book = new Book(title, author_ptrs, description, genres);
    books_.insert({title, n_book});
    return true;
}

void Library::add_borrower(const std::string &name, const std::string &email,
                           const std::string &address)
{
    if ( accounts_.find(name) != accounts_.end()){
        std::cout << DUPLICATE_PERSON_ERROR << std::endl;
        return;
    }

    Person* n_person = new Person(name, email, address);
    accounts_.insert({name, n_person});
}

void Library::set_date(int day, int month, int year)
{
    delete today_;
    today_ = new Date(day, month, year);
    today_->show();
}

void Library::advance_date(int days)
{
    today_->advance_by(days);
    today_->show();
}

void Library::loaned_books()
{
    std::cout << LOAN_INFO << std::endl;
    for ( std::pair<std::string, Loan*> loan: loans_ ){
        loan.second->loaned_books();
    }

//    if (borrowed_books_.empty()){
//        return;
//        }
//    else{
//        cout<<LOAN_INFO<<endl;
//        multimap <string, string> :: iterator itr;
//        for (itr=borrowings_.begin(); itr!= borrowings_.end(); ++itr){
//            cout << itr->second << " : " << itr->first << " : ";
//            cout<<today_->to_string()<< " :";
//            cout<<" 0"<<endl;
//        }
//}
}
void Library::loans_by(const std::string &borrower)
{/*
    if ( accounts_.find(borrower) == accounts_.end()){
        //fine works
        std::cout << CANT_FIND_ACCOUNT_ERROR << std::endl;
        return;
        //fine works
    }
    multimap<string, string>:: iterator itr;
    for (itr = borrowings_.find(borrower); itr != borrowings_.end(); itr++){
        if (itr->first == borrower){
            cout << itr->second << " : ";
            cout<<today_->to_string()<< " :";
            cout<<" 0"<<endl;
          }
        else{
            return;
        }
    }*/
}

void Library::loan(const std::string &book_title, const std::string &borrower_id)
{
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

void Library::renew_loan(const std::string &book_title)
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

void Library::return_loan(const std::string &book_title)
{/*
    if ( books_.find(book_title) == books_.end()){
        std::cout << CANT_FIND_BOOK_ERROR << std::endl;
        return;
    }
    else if ((borrowed_books_.find(book_title))== borrowed_books_.end()){
        std::cout << LOAN_NOT_FOUND_ERROR << std::endl;
        return;
    }
    else{
        borrowings_.erase(book_title);
        borrowed_books_.erase(book_title);
        names_of_borrowers_.erase(book_title);
        return;
    }*/
}
