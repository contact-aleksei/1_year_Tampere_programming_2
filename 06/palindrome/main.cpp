#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

bool palindrome_recursive(std::string s)
{
  RECURSIVE_FUNC
  // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
  // ------------
          // ------------
                  unsigned int length_of_s;
                  length_of_s=s.length();

                  if (length_of_s == 1 or length_of_s == 0 ){
                   return 1;}


                  if (s.at(0)==s.at(length_of_s-1)){
                      if (length_of_s>2){
                          return palindrome_recursive(s.substr(1,length_of_s-2));

                      }

                  return 1;}

                  else
                  return 0;
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    if(palindrome_recursive(word)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }
}
#endif
