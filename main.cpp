#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include "head.hpp"
using namespace std;
int main(){
    time_t tp=time(NULL);
    /*string word=choose_word((tp/86400)-19116);
    cout<<"WORDLE CLI\n"<<'['<<display_color(' ',"white")<<']'<<'['<<display_color(' ',"white")<<']'<<'['<<display_color(' ',"white")<<']'<<'['<<display_color(' ',"white")<<']'<<'['<<display_color(' ',"white")<<']'<<"\n";
    string guess;
    cin>>guess;
    dguess(guess,word);*/
    cout<<choose_word((tp/86400)-19116);
}