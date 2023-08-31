#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



int main()
{

    int a, i = 0;
    string text, old, password1, password2;
    string pass, name, password0, age, user;
    string word, word1;

    //string array
    string creds[2], cp[2];

    cout<<"          Security System            "<<endl;
    cout<<"_____________________________________"<<endl<<endl;
    cout<<"             1.Register               "<<endl;
    cout<<"             2.Login               "<<endl;
    cout<<"             3.change Password      "<<endl;
    cout<<"             4.End Program          "<<endl;
    cout<<"_____________________________________"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter Your choice: ";
        cin>>a;
        switch(a) {
        case 1: {
            cout<<"__________________________"<<endl;
            cout<<" -------- Register ------ "<<endl;
            cout<<"__________________________"<<endl;
            cout<<"Please enter username: ";
            cin>>name;
            cout<<"Please enter the Password: ";
            cin>>password0;
            cout<<"Please Enter your Age:";
            cin>>age;

            ofstream of1;
            of1.open("file.txt");
            if(of1.is_open()) {
                of1<<name<<"\n";
                of1<<password0<<"\n";
                cout<<"Registration Succesfull"<<endl;
            }
            break;
        }
        case 2: {
            i = 0;
            cout<<"__________________________"<<endl;
            cout<<" --------- Login -------- "<<endl;
            cout<<"__________________________"<<endl;

            ifstream of2;
            of2.open("file.txt");
            cout<<"Please enter the username: ";
            cin>>user;
            cout<<"Please enter the Password: ";
            cin>>pass;

            if(of2.is_open()) {
                while(!of2.eof()) {
                    while(getline(of2, text)) {
                        istringstream iss(text);
                        iss>>word;
                        creds[i] = word;
                        i++;
                    }
                    if(user == creds[0] && pass == creds[1]) {
                        cout<<"--Login Succesfull!---";
                        cout<<endl<<endl;
                        cout<<"Details: "<<endl;
                        cout<<"Username: " + name<<endl;
                        cout<<"Password: "+ pass<<endl;
                        cout<<"Age: " + age<<endl;
                    }
                    else{
                        cout<<endl<<endl;
                        cout<<"Incorrect credentials"<<endl;
                        cout<< "1. Press 2 to Login"<<endl;
                        cout<<" 3. Press 3 to Reset password"<<endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3: {
            i = 0;
            cout<<"____________________________________"<<endl;
            cout<<" --------- change Password -------- "<<endl;
            cout<<"____________________________________"<<endl;

            ifstream of0;
            of0.open("file.txt");
            cout<<"Enter the old Password: ";
            cin>>old;
            if(of0.is_open()) {
                    while(getline(of0, text)) {
                        istringstream iss(text);
                        iss>>word1;
                        cp[i] = word1;
                        i++;
                    }
                    if(old == cp[1]) {
                        of0.close();

                        ofstream of1("file.txt");
                        if(of1.is_open()) {
                            cout<<"Enter your new Password:";
                            cin>>password1;
                            cout<<"Enter your password Again:";
                            cin>>password2;

                            if(password1 == password2) {
                                of1<<cp[0]<<"\n";
                                of1<<password1;
                                cout<<"Password changed Succesfully"<<endl;
                            }

                            else{
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"Password do not match"<<endl;
                            }
                        }
                    }
                    else{
                        cout<<"Enter a valid password"<<endl;
                        break;
                    }

            }
            break;


        }
        case 4: {
            cout<<"----------Thank You!----------";
            break;
        }
        default: {
            cout<<"Enter a valid Choice";
        }

        }
    }while(a != 4);


    return 0;
}
