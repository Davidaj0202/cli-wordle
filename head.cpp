#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include "head.hpp"
using namespace std;
void clear(){
    cout << "\033[2J\033[1;1H";
}
int rng(int i){
    srand(time(0));
    return rand()%i;
}
string choose_word(int i){
    string tmp;
    fstream word_list;
    word_list.open("wordlist(updated).txt",ios::in);
    for(int j=0;j<i;j++){
        getline(word_list,tmp);
    }
    return tmp;
}
string display_color(char i,string color){
    string j(1,i);
    if(color=="red"){
        string tmp = "\033[41m\033[30m"+j;
        tmp=tmp+"\033[0m";
        return tmp;
    }
    else if(color=="white"){
        string tmp = "\033[107m\033[30m"+j;
        tmp=tmp+"\033[0m";
        return tmp;
    }
    else if(color=="green"){
        string tmp = "\033[102m\033[30m"+j;
        tmp=tmp+"\033[0m";
        return tmp;
    }
    else if(color=="yellow"){
        string tmp = "\033[103m\033[30m"+j;
        tmp=tmp+"\033[0m";
        return tmp;
    }
    else{
        return "";
    }
}
void dguess(string i,string word){
    vector<string> past;
    string tmp,tmpt;
    clear();
    for(int s=0;s<past.size();s++){
        cout<<past[s];
    }
    cout<<"\n";
    if(i.length()!=5){
        cout<<"Only 5 Letters Please!\n";
    }
    for(int d=0;d<6;d++){
    clear();
    if(i.length()!=5){
        d++;
    }
    else{
        for(int f=0;f<5;f++){
            if(i[d]==word[d]){
                tmp='['+display_color(i[d],"green")+']';
            }
            else if(i[d]==word[0]||i[d]==word[1]||i[d]==word[2]||i[d]==word[3]||i[d]==word[4]){
                tmp='['+display_color(i[d],"yellow")+']';
            }
            else{
                tmp='['+display_color(i[d],"red")+']';
            }
            tmpt=tmpt+tmp;
        }
    }
        clear();
        past.push_back(tmpt);
        for(int s=0;s<past.size();s++){
            cout<<past[s]<<"\n";
        }
        if(i==word){
            break;
        }
        else if(i.length()!=5){
            cout<<"5 Letters Please!";
            cin>>i;
        }
        else{
            cin>>i;
        }
    }
}