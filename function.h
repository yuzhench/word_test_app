#include <iostream>
#include <sstream>
#include <unordered_set>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;


enum class Etymology{
    adj,
    v,
    n,
    adv,
    na
};

// Overload << for Etymology enum
std::ostream& operator<<(std::ostream& os, Etymology etym);


struct Word{
    string english_word;
    string chinese_word;
    Etymology etymology;
    int test_time;
    int wrong_time;

    
    // Define a hash function for the struct using only the english_word member
    struct hash_function {
        std::size_t operator()(const Word& word) const {
            // Combine hash values for each member
            std::size_t hashEnglish = std::hash<std::string>{}(word.english_word);
            // std::size_t hashChinese = std::hash<std::string>{}(word.chinese_word);
            // std::size_t hashEtymology = std::hash<int>{}(static_cast<int>(word.etymology));
            // std::size_t hashTestTime = std::hash<int>{}(word.test_time);
            // std::size_t hashWrongTime = std::hash<int>{}(word.wrong_time);

            // Combine hash values using bitwise XOR
            return hashEnglish /* ^ hashChinese ^ hashEtymology ^ hashTestTime ^ hashWrongTime */;
        }
    };

   
    bool operator==(const Word& other) const {
        return (english_word == other.english_word) /* && (chinese_word == other.chinese_word) && (etymology == other.etymology)
            && (test_time == other.test_time) && (wrong_time == other.wrong_time)*/;
    }

    bool operator!=(const Word& other) const {
        return !(*this == other);
    }

    Word& operator=(const Word& other){
        english_word = other.english_word;
        chinese_word = other.chinese_word;
        etymology = other.etymology;
        test_time = other.test_time;
        wrong_time = other.wrong_time;
        return *this;
    }   

    bool operator<(const Word& other){
        if (english_word < other.english_word){
            return true;
        }
        else{
            return false;
        }
    }
   
};


class word_test{
    private:
        // //define an unordered set to store all the words
        // unordered_set<Word, Word::hash_function, Word::compared_by_english> word_unordered_set; 
        // int word_num;
        const string file_name = "word_data.dat";

    public:

        //define an unordered set to store all the words
        unordered_set<Word, Word::hash_function /*, Word::compared_by_english */> word_unordered_set; 
        int word_num;
        
        //function0: constructor 
        word_test();
        //function1: check if a word is existed in the word_set
        bool if_exist(string english_word_ip);

        //function2: add a new word into the set 
        void add_word (string english_word_ip, string chinese_word_ip, Etymology entymology_ip);

        void add_word (Word word_ip);

        //function3: get the word_num 
        int get_word_num();
       
       //function4: remove a word from the set
       void remove_word(string english_word_ip);

       //function5: save the set to the file 
       void save_set();

       //function6: load the file data to the set 
       void load_set();

       //function7: check of we need to initialize the data function 
       void init_file();

    

};