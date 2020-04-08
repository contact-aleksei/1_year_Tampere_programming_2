#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <sstream>

using namespace std;

int main()
{
      map<string, int> points;
      string filename = ""; cout << "Input file: ";  getline(cin, filename);
      ifstream file_object(filename);
      int counter=1; string line="";
      std::size_t found = line.find(":");
      string part="";
      if (file_object){
          cout<<"Final scores:"<<endl;
            while (getline(file_object, line)) {
                found=line.find(':');

                if ( found!=std::string::npos){
                    part= line.substr(0,found);
                    line.erase(0, found+1);

                    // converting string "line" to integer
                    stringstream geek(line);
                    int x = 0;
                    geek >> x;



                    //assigning data "part (name)" and "line (number or points)" to "map"

                    if ( points.find(part) != points.end() ) {

                       points.at(part) += x;



                    } else {
                        points.insert({part, x} );
                    }





                    }
                counter++;
             }
          file_object.close();

          //printing map
          map<string, int>::iterator iter;
             iter = points.begin();
             while ( iter != points.end() ) {
                 cout << iter->first << ": "<< iter->second << endl;
                 ++iter;
             }


          return EXIT_SUCCESS;
      }

        else {
        // Opening was unsuccessful, the stream is invalid
        cout<< "Error! The file "<<filename<<" cannot be opened."<< endl;
        return 1;
    }

}
