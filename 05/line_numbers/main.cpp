#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    string inputfilename = ""; cout << "Input file: ";  getline(cin, inputfilename);
    string outpufilename = ""; cout << "Output file: "; getline(cin, outpufilename);
    ifstream file_object(inputfilename); int counter=1;
    if (file_object) {
        string line; string lineoutput;
        ofstream file_subject;
        file_subject.open (outpufilename);


        while (getline(file_object, line)) {
            file_subject <<counter;
             file_subject<<" ";
             file_subject <<line;
            file_subject<<"\n";
            counter++;
        }
        file_subject.close();
        file_object.close();
return 0;
        // Opening was successful, next we will do something to the file
    } else {
        // Opening was unsuccessful, the stream is invalid
        cout<< "Error! The file "<<inputfilename<<" cannot be opened."<< endl;
        return 1;
    }

}
