#include "function.h"

#include <iostream>
#include <unordered_set>
using namespace std;

std::ostream& operator<<(std::ostream& os, Etymology etym) {
    switch (etym) {
        case Etymology::adj:
            os << "adj.";
            break;
        case Etymology::v:
            os << "v.";
            break;
        case Etymology::n:
            os << "n.";
            break;
        case Etymology::adv:
            os << "adv.";
            break;
        default:
            os << "unknown";
            break;
    }
    return os;
}

Etymology S2E(string eytmology_ip){
    if (eytmology_ip == "adj."){
        return Etymology::adj;
    }
    else if (eytmology_ip == "v."){
        return Etymology::v;
    }
    else if (eytmology_ip == "n."){
        return Etymology::n;
    }
    else if (eytmology_ip == "adv."){
        return Etymology::adv;
    }
    else{
        return Etymology::na;
    }
}
//functoin0; 
word_test::word_test():word_num(0){}

//function1: check if a word is existed in the word_set
bool word_test::if_exist(string english_word_ip){
    auto it = word_unordered_set.find(Word{english_word_ip});
    if (it != word_unordered_set.end()) {
        return true;
    } 
    else {
        return false;
    }
     
}

//function2: add a new word into the set 
void word_test::add_word (string english_word_ip, string chinese_word_ip, Etymology entymology_ip){
    //check if this word is already existed 
    if (if_exist(english_word_ip) == true){
        cout << "this word is already exist in the set" << endl;
        return;
    }
    

    word_unordered_set.insert({english_word_ip, chinese_word_ip, entymology_ip, 0, 0});

    //update the word_num 
    word_num++;

}

void word_test::add_word (Word word_ip){
   add_word(word_ip.english_word,word_ip.chinese_word,word_ip.etymology);

}

//function3: get the word_num 
int word_test::get_word_num(){
    return word_num;
    // return word_unordered_set.size();
}

//function4: remove a word from the set
void word_test::remove_word(string english_word_ip){
    auto it = word_unordered_set.find(Word{english_word_ip});
    if (it != word_unordered_set.end()) {
        // Word found, erase it from the set
        word_unordered_set.erase(it);

        // Update the word_num
        word_num--;

        cout << "Word '" << english_word_ip << "' removed from the set." << endl;
    } 
    else {
        cout << "Word '" << english_word_ip << "' not found in the set." << endl;
    }
}

void word_test::save_set(){
    ofstream out_file(file_name);
    for (const auto word : word_unordered_set){ 
        out_file << std::left << setw(20) << word.english_word 
        << setw(50) << word.etymology 
        << word.chinese_word << endl;
         
    }
    out_file.close();
}

void word_test::load_set(){
    ifstream in_file(file_name);
    if (!in_file){
        cout<< "the file can't be open correctly!!!" << endl;
    }
    //the file open correctly
    else {
        string line;
        int line_num = 0;
        while(getline(in_file,line)){
            Word word;
            istringstream iss(line);
            iss >> word.english_word;
             
            string temp_etymology;
            iss >> temp_etymology;
            word.etymology = S2E(temp_etymology);

            iss >> word.chinese_word;

            add_word(word);
            line_num++;

        }

        cout << "---> Total " << line_num << endl;
        remove(file_name.c_str());
    }
}

void word_test::init_file(){
    string file_name = "word_data.dat";
    ifstream check_file (file_name);
    if (!check_file.is_open()){
        cout << "initialize the data file" << endl;
        ofstream out_file(file_name);
    }
    
}




    
 