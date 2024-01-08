#include <iostream>
#include <unordered_set>
#include "function.h"
using namespace std;

enum instruction{
    Add,
    Remove,
    close
};

void title_printer (){
    cout << "choose what you want to do" << endl;
    cout << "0. Add "<< endl;
    cout << "1. Remove "<< endl;
    cout << "2. close " << endl;
    cout << endl;
}

 
int main (){

    word_test test1;

    //inistialize the data file 
    test1.init_file();
    
    test1.load_set();

    // title_printer();

    // int ins_val;
    // cin >> ins_val;

     

    string english_word_ip;
    string chinese_meaning;
    int etymology_val;

    bool end_program = false;
    while (!end_program){

        cout <<"current word_number is: " << test1.get_word_num() << endl;
        title_printer();
        int ins_val;
        cin >> ins_val;
        instruction ins = static_cast<instruction>(ins_val);


        switch (ins){
     
            case instruction::Add:{
                cout << "--------------------------------------ADD-------------------------------------" << endl;
                cout << "type in the word:   ";
                
                cin >> english_word_ip;

                cout << "type in the chinese_meaning:   ";
                cin >> chinese_meaning;

                cout << "type in the etymology   " << "0.adj 1.v 2.n 3.adv 4.na:   ";
                cin >> etymology_val;

                Etymology etymology_ip = static_cast<Etymology>(etymology_val);

                test1.add_word(english_word_ip, chinese_meaning, etymology_ip);

                break;
            }

            case instruction::close:{
                end_program = true;
                break;
            }

        
            case instruction::Remove:{
                cout << "type in the word:   ";
                cin >> english_word_ip;

                test1.remove_word(english_word_ip);

                break;
            }

            default:{
                cout << "error" << endl;
                break;
            
            }   
        }
    }
     
    cout << "word number is " << test1.get_word_num() << endl;
    // cout << "if it existed: " << test1.if_exist("buy") << endl;

    // test1.remove_word("buy");

    // cout << "word number is " << test1.get_word_num() << endl;
    // cout << "if it existed: " << test1.if_exist("buy") << endl;

    test1.save_set();
    return 0;
}
