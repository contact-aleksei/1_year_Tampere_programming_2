#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> split(string getstring, char separator, bool k=false){
            vector<string> parts;vector<string> parts_no_empty ;
            size_t position = 0;
            string part;



            while ((position = getstring.find(separator)) != string::npos) {//Maximum value for size_t
                                                                     //npos is a static member constant value with the greatest
                                                                          //possible value for an element of type size_t
                part = getstring.substr(0, position);                       //position Number of characters to include in the substring
                getstring.erase(0, position+1);                               //s.erase(0, pos + delimiter.length());
                parts.push_back(part);


                if (part==""){
                    continue;
                }
                else{parts_no_empty.push_back(part);
                }

            }

            if (k==true){
            parts_no_empty.push_back(getstring);
            return parts_no_empty;
            }
            else {
            parts.push_back(getstring);
            return parts;
            };

}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
