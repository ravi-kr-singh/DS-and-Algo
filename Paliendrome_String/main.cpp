#include <iostream>
#include <string>
using namespace std;

string reverse_the_string(string given) {
    string temp;


    //Will complete it later

}

int main()
{
    string given_str,rev_str;
    cout << "Enter String : ";
    getline(cin,given_str);
    rev_str=reverse_the_string(given_str);
    if(given_str==rev_str) {
        cout<<"Given string is paliendrome.";
    }
    else {
        cout<<"Given string is not paliendrome as reversed string is \""<<rev_str<<"\".";
    }
    return 0;
}
