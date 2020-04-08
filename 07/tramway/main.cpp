// Aleksei Sapozhnikov AND Olayinka Akande Gold
//please, check his commits

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

vector<std::string> split_command(const string &s, const char delimiter, bool ignore_empty = false)
{
    vector<string> result;
    string tmp = s;

    while (tmp.find(delimiter) != string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if (not(ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if (not(ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

vector<string> split(const string &s, const char separator)
{
    vector<string> result;
    string tmp = s;

    while (tmp.find(separator) != string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(separator));
        tmp = tmp.substr(tmp.find(separator) + 1, tmp.size());
        if (not new_part.empty())
        {
            result.push_back(new_part);
        }
    }
    if (
        not tmp.empty())
    {
        result.push_back(tmp);
    }
    return result;
}
// The most magnificent function in this whole program.
// Prints a RASSE
void print_rasse()
{
    std::cout <<
                    "=====//==================//===\n"
                    "  __<<__________________<<__   \n"
                    " | ____ ____ ____ ____ ____ |  \n"
                    " | |  | |  | |  | |  | |  | |  \n"
                    " |_|__|_|__|_|__|_|__|_|__|_|  \n"
                    ".|                  RASSE   |. \n"
                    ":|__________________________|: \n"
                    "___(o)(o)___(o)(o)___(o)(o)____\n"
                    "-------------------------------" << std::endl;
}

// Short and sweet main.
int main()

{
    print_rasse();
    multimap<string, string> lineId;    // mutlimap to handle key and value: LINES, STATIONS
    set<string> linesOnly;              // set to handle keys: LINES
    multimap<string, string> stationId; // mutlimap tohandle keys: STATIONS, LINES
    set<string> stationsOnly;           // set to handle keys: STATIONS

    string filename;
    cout << "Give a name for input file: ";
    getline(cin, filename);

    // Open file object and read content
    ifstream file_object(filename);
    if (not file_object)
    {
        cout << "Error: File could not be read." << endl;
        return EXIT_FAILURE;
    }
    string line; // this prints the line in the file
    while (getline(file_object, line))
    {
        //spliting to check the right format and avoid invalid format
        vector<string> parts = split(line, ';');
        if (parts.size() != 2)
        {
            cout << "Error: Invalid format in file." << endl;
            file_object.close();
            return EXIT_FAILURE;
        }

        //looping through the file to check for duplicate lines
        for (multimap<string, string>::iterator itr = lineId.begin(); itr != lineId.end(); itr++)
        {
            if (itr->first == parts.at(0) && itr->second == parts.at(1))
            {
                cout << "Error: Invalid data in the file" << endl;
                file_object.close();
                return EXIT_FAILURE;
            }
        }

        // make_pair constructs a pair object with its first element set to x and its second element to y
        lineId.insert(make_pair(parts.at(0), parts.at(1)));
        linesOnly.insert(parts.at(0));
        stationId.insert(make_pair(parts.at(1), parts.at(0)));
        stationsOnly.insert(parts.at(1));
    }
    //file_object.close();
    while (true)
    {
        string commandLine; // takes command from the console
        cout << "tramway> ";
        getline(cin, commandLine);
        vector<string> parts = split_command(commandLine, ' ', true);
        string command = parts.at(0);

        transform(command.begin(), command.end(), command.begin(), ::toupper); // handles case from user input

        //if command consists of a single word: QUIT, LINES, STATIONS
        if (parts.size() == 1)
        {
            //QUIT command
            if (command == "QUIT"){
                return EXIT_SUCCESS;
            }

            //printing LINES
            else if (command == "LINES"){
                cout << "All tramlines in alphabetical order:" << endl;
                for (set<string>::iterator itr = linesOnly.begin(); itr != linesOnly.end(); itr++){
                    cout << *itr << endl;
                }
            }

            //printing STATIONS
            else if (command == "STATIONS"){
                cout << "All stations in alphabetical order: " << endl;
                //Iterating through and printing the stations only
                for (set<string>::iterator itr = stationsOnly.begin(); itr != stationsOnly.end(); itr++){
                    cout << *itr << endl;
                }
            }

            //if one-word command was not found
            else{
                cout << "Error: Invalid input. " << endl;
            }
        }

        // Here we are printing the lines against the stations
        else if (command == "LINE")
        {
            multimap<string, string>::iterator search = lineId.find((parts.at(1)));
            set<string>::iterator search2 = linesOnly.find(parts.at(1));
            if (search == lineId.end() and search2 == linesOnly.end()){
                    cout << "Error: Line could not be found." << endl;
            }


            else{
                cout << "Line " << parts.at(1) << " goes through these stations in the order they are listed:" << endl;
               for (multimap<string, string>::iterator itr = lineId.find(parts.at(1)); itr != lineId.end(); itr++){
                    if (itr->first == parts.at(1)){
                        cout << " - " << itr->second << endl;
                    }
                }
            }
        }

        // Printing information about any station
        else if (command == "STATION")
        {
            string check;
            if (parts.size() == 2)
            {
                check = parts.at(1);
                if (check[0] == '"')
                {
                    check.pop_back();
                    check.erase((check.begin()));
                }
            }
            else if (parts.size() > 2)
            {
                vector<string> parts2 = split(commandLine, '"');
                if (parts2.size() == 2)
                {
                    check = parts2.at(1);
                }
                else
                {
                    cout << "Invalid input " << endl;
                }
            }
            multimap<string, string>::iterator search = stationId.find(check);
            if (search == stationId.end())
            {
                cout << "Error: Station could not be found." << endl;
            }
            else
            {
                cout << "Station " << check << " can be found on the following lines: " << endl;

                //check_stations map implemented to sort printed stations alphabetically
                multimap<string, string> check_stations;
                for (multimap<string, string>::iterator itr = stationId.find(check); itr != stationId.end(); itr++){
                    if (itr->first == check){
                        check_stations.insert({ itr->second, itr->second });
                      }
                }

                //actual printing of the found stations
                for (map<string, string>::iterator iter = check_stations.begin(); iter != check_stations.end(); iter++)
                cout << " - " << iter->first << endl;
            }
        }

        else if (command == "ADDLINE"){
            // Here we add line and check if line already exist
            set<string>::iterator search = linesOnly.find(parts.at(1));
            if (search == linesOnly.end()){
                linesOnly.insert(parts.at(1));
                cout << "Line was added. " << endl;
            }
            else{
                cout << "Error: Station/line already exists. " << endl;
            }
        }

        // adding station procedure
        else if (command == "ADDSTATION"){
            string check,check1,check2,check3;
            int counter;

            // command should consist of more than 2 words
            if (parts.size() ==2){
                cout << "Error: Invalid input." << endl;
            }

            // if command consists of 3 words
            else if (parts.size() ==3){
                counter=0;

                //if stations are not found, print error
                for (multimap<string, string>::iterator it = lineId.find(parts.at(1)); it != lineId.end(); it++){
                    if (it->first == parts.at(1) && it->second == parts.at(2)){
                     counter++;
                    }
                }
                if (counter==1){
                        cout << "Error: Station/line already exists. " << endl;
                }
                //if stations found, add input station
                else{
                    check1 = parts.at(1);
                    check = parts.at(2);
                    stationId.insert(pair <string, string> (check,check1));
                    lineId.insert(pair <string, string> (check1,check));
                    stationsOnly.insert(check);
                    cout << "Station was added." << endl;
                    if (check[0] == '"'){
                        check.pop_back();
                        check.erase(check.begin());
                    }
                }
            }
            // if command consists of 4 words
            else if (parts.size() == 4)
                {
                    int k=0;
                    // if command consist of 4 words and the last word-station exists
                    for (multimap<string, string>::iterator it = lineId.find(parts.at(1)); it != lineId.end(); it++){
                        if (it->first == parts.at(1) && it->second == parts.at(3)){
                          lineId.insert( it, {parts.at(1), parts.at(2)});
                          stationId.insert( it, {parts.at(2), parts.at(1)});
                          stationsOnly.insert(parts.at(2));
                          k=1;
                        }
                     }
                    // if command consist of 4 words and the last word-station does not exist
                    if (k==0) {
                      lineId.insert(pair <string, string> (parts.at(1), parts.at(2)));
                      stationId.insert(pair <string, string> (parts.at(2),parts.at(1)));
                      stationsOnly.insert(parts.at(2));
                    }
                cout << "Station was added." << endl;
            }
            //if command includes more than 4 words, then conduct printing ERROR
            else if (parts.size() > 4){
                vector<string> parts2 = split(commandLine, '"');
                if (parts2.size() == 2){
                    check = parts2.at(1);
                }

                else{
                    cout << "Error: Invalid input" << endl;
                }
            }
        }
        else if (command == "REMOVE"){
            string check;
            //if input: REMOVE "STATION name" and +more words, then print out Error
            if (parts.size() > 2){
                cout << "Error: Invalid input." << endl;
                vector<string> parts2 = split(commandLine, '"');
                if (parts2.size() == 2){
                    check = parts2.at(1);
                }
                else {
                    continue;
                }
            }

            //if input: REMOVE STATION, then continue
            else if (parts.size() == 2){
                check = parts.at(1);
                if (check[0] == '"'){
                    check.pop_back();
                    check.erase(check.begin());
                }
            }

            //REMOVING command
            set<string>::iterator search = stationsOnly.find(check);
            if (search != stationsOnly.end()){
                stationsOnly.erase(check);
                for (multimap<string, string>::iterator it = stationId.find(check); it != stationId.end(); it++){
                    if (it->first == check){
                        stationId.erase(check);
                    }
                    for (multimap<string, string>::iterator it = lineId.begin(); it != lineId.end(); it++){
                        if (it->second == check){
                            lineId.erase(it);
                        }
                    }
                }
                cout << "Station was removed from all lines. " << endl;
            }
            else{
                cout << "Error: Station could not be found." << endl;
            }
        }
        //if command consists of two words and command has not been recognised, print ERROR
        else if (parts.size() ==2){
            if ((parts.at(0) != "ADDSTATION") || (parts.at(0) != "LINE") || (parts.at(0) != "STATION")
                        || (parts.at(0) != "REMOVE") )
            {
                    cout << "Error: Invalid input." << endl;
                }
            else
                continue;
        }
    }
    return EXIT_SUCCESS;
}
