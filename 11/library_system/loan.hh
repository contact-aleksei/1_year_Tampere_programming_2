/* Module: Loan
 * ------------
 * This class and its bahaviour should be defined by the student.
 *
 * TIE-0220x S2019
 * */
#ifndef LOAN_HH
#define LOAN_HH

const int DEFAULT_RENEWAL_AMOUNT = 6;

#include <string>
#include <set>
#include <map>
#include <vector>

class Loan
{
public:
    Loan(const std::string& names_of_borrowers,
         std::vector<Loan*> borrowed_books,
         std::string borrowings = "",
         std::set<std::string> update_of_borrowed_books = {});
    ~Loan();



    // Self-descriptive getters
    std::string get_names() const;
    std::vector<Loan*> get_books() const;
    std::set<std::string> get_borrowings() const;

    void print_info_loan() const;
    void loaned_books();
    void loans_by(const std::string &borrower);
    void loan(const std::string &book_title, const std::string &borrower_id);
    void renew_loan(const std::string &book_title);
    void return_loan(const std::string &book_title);

private:

    std::string names_of_borrowers_;
    std::vector<Loan*> borrowed_books_;
    std::string borrowings_;
    std::set<std::string> update_of_borrowed_books_;


};

#endif // LOAN_HH
