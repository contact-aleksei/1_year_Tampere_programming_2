#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const std::string HELP_TEXT = "S = store id1 i2\n P = print id\n"
                              "C = count id\n D = depth id";


std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void print(string ID_, map <string,vector<string>>& the_network_list_, int counter_=0){
    int length = the_network_list_[ID_].size();
    counter_ += 1;
    //going through the members
    for (int member_number=0; member_number<length; member_number++){

            //printing out dots
            for (int dots_times = 0; dots_times <= counter_-1; dots_times++){
                cout << "..";
            }

            //printing ID network member
            cout<<the_network_list_[ID_].at(member_number)<<endl;

            if (the_network_list_.find(the_network_list_[ID_].at(member_number))!= the_network_list_.end()) {

                // If the name is in the map then start printing other members at member_number
                print(the_network_list_[ID_].at(member_number), the_network_list_, counter_);
            }
    }
}

int count(string ID_, map <string, vector<string>>& the_network_list_, int counter_=0){
    if ( the_network_list_.find(ID_)!= the_network_list_.end()) {
        // If the name is in the map then
        int length = the_network_list_[ID_].size();
        for (int member_number=0; member_number<length; member_number++){

            //adding number of members to subnetwork counter
            counter_ = count(the_network_list_[ID_].at(member_number), the_network_list_, counter_) + 1;
        }
    }
    return counter_;
}

int depth(string ID_, map <string, vector<string>>& the_network_list_){
    int length = the_network_list_[ID_].size();
    for (int member_number=0; member_number<length; member_number++){
        if (the_network_list_.find(ID_)!=the_network_list_.end()) {
            // If the name is in the map

            return depth(the_network_list_[ID_].at(member_number), the_network_list_) + 1;
        }
    }
    return 1;
}

int main()
{
    // TODO: Implement the datastructure here
    map <string, vector<string>> the_network_list;

    while(true){
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        std::string command = parts.at(0);

        if(command == "S" or command == "s"){
            if(parts.size() != 3){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // TODO: Implement the command here!
            // SAVING DATA

            if (the_network_list.find(id1)!= the_network_list.end()) {
                // If the name is already in the map, then add id2..
                the_network_list.at(id1).push_back(id2);
            } else {
                // If the name is not in the map, then add both id1 and id2..
                the_network_list[id1].push_back(id2);
            }

        } else if(command == "P" or command == "p"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);



            // TODO: Implement the command here!
            // PRINTING DATA
            if (the_network_list.find(id)!=the_network_list.end()){
                // If the name is in the map, then print
                cout<<id<<endl;
                print(id, the_network_list, 0);
            }
            else {
                //The name is not recruiter.
                cout<<id<<endl;
            }



        } else if(command == "C" or command == "c"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            cout<<to_string(count(id, the_network_list, 0))<<endl;


        } else if(command == "D" or command == "d"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            cout<<to_string(depth(id, the_network_list))<<endl;

        } else if(command == "Q" or command == "q"){
           return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
