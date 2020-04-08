#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

std::vector <std::string> splitting_into_parts(std::string lines_){
    vector <std::string> vectorOFstrings;
    string v_; string::size_type lenghtOFtheline ;
    int starting_position= 0; int counting_space_char = 0;

    lenghtOFtheline = lines_.length();
    vectorOFstrings.empty();
    for (unsigned int a = 0; a < lenghtOFtheline ; ++a){

        //if the first char is not "spacebar"
        if (lines_.substr(a,1) != " "){
            counting_space_char += 1;

                    // if given char is not at the end of the line
                    if (a != lenghtOFtheline -1){
                            // if the next char is a "spacebar"
                            // it is the end of the word, push it in the vector
                            if (lines_.substr(a+1,1) == " "){
                            vectorOFstrings.push_back(lines_.substr(starting_position,counting_space_char));
                            }

                    }
            // however if it is a "spacebar"
            // then put into the vector
            else{
                vectorOFstrings.push_back(lines_.substr(starting_position,counting_space_char));
            }
        }

        // otherwise, in case "spacebar"
        else{

            // if this char is not at the end of the line,
            // point to the next char
            if (a != lenghtOFtheline -1){
                starting_position = a+1;
            }
            counting_space_char = 0;

        }
    }
    return vectorOFstrings;
}








int main()
{
    //variables
    string filename = ""; string lines;
    map <string, vector<int> > word_list;
    int line_number = 0;
    //opening a file
    cout << "Input file: "; getline(cin, filename);
    ifstream file_object(filename);

    if (file_object ) {
        while ( getline(file_object, lines) ){
            std::vector< std::string > line_parts  = splitting_into_parts(lines);
            line_number +=1;
            for( auto i : line_parts ) {

                  if ( word_list.find(i) != word_list.end() ) {

                    // The word was found in the map
                    if (line_number != word_list[i].back()){
                        word_list.at(i).push_back(line_number);
                    }

                } else {
                     //The word was not found in the map
                    word_list[i].push_back(line_number);
                }
            }
        }
    }
    else {
        cout << "Error! The file " << filename << " cannot be opened." << endl;
        return 1;}



    map <string, vector<int>> :: iterator iterator= word_list.begin();
    for (; iterator != word_list.end(); iterator++){
        cout << iterator -> first <<  " " << iterator -> second.size() << ": ";
        int row_length = iterator -> second.size();
        for(int another_iterator = 0; another_iterator < row_length; another_iterator++){
            if (row_length == 1){
                cout << iterator -> second.at(another_iterator) << endl;
            }
            else if (row_length != 1 && another_iterator != row_length-1){
                cout << iterator -> second.at(another_iterator) << ", ";
            }
            else if (row_length != 1 && another_iterator == row_length-1){
                cout << iterator -> second.at(another_iterator) << endl;
            }
        }
    }
    return 0;
}
