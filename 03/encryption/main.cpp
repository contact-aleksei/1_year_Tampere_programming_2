#include <iostream>
#include <cctype>

using namespace std;

int len,len2,i,j,k,m,t;
char c,cword;
string tex, enk, entin, entout;
int main()
{
    cout << "Enter the encryption key: ";
    cin>>enk;

    len = enk.length();
            k=0;
            for (i=0;i<len;i=i+1) {
                    c=enk[i];
                    if (islower(c)==0){
                    k=k+1; i++;
                    }
            }

            m=1;
            for( char letter = 'a'; letter < 'z'; ++letter ){
                for (i=0;i<len;i=i+1) {
                                    c=enk[i];
                                    if (c==letter){
                                        m=m+1;i=800;
                                    }
                }
            }

//PART WITH AN ENCRYPTION KEY

    if (len < 26){
        cout <<"Error! The encryption key must contain 26 characters.";
        return EXIT_FAILURE;
        }
    else if (k>0){
        cout <<"Error! The encryption key must contain only lower case characters.";
        return EXIT_FAILURE ;
    }

    else if (m>26 or m<26){
        cout <<"Error! The encryption key must contain all alphabets a-z.";
        return EXIT_FAILURE ;
    }

//PART WITH AN ENCRYPTION WORD

    else {
        cout << "Enter the text to be encrypted: ";
        cin>>entin;
        len2 = entin.length();
                for (j=0;j<len2;j=j+1){
                cword=entin[j];
                t=-1;

                    for( char letter = 'a'; letter <='z'; ++letter){
                        t=t+1;
                        if (cword ==letter){
                        i=t;
                        c=enk[i];
                        entin[j]=c;
                        }
                    }

                 }
                cout << "Encrypted text: "<< entin;
                return EXIT_SUCCESS;

        }





}
