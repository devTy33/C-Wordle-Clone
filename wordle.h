//Ty Anderson
//the code works with the "valid-wordl-words.text" file 


#ifndef WORDLE_H
#define WORDLE_H
#include <iostream>
#include <vector>
using namespace std;


class GameSolve{
    private:
        //contains resulting string after user guess so it can be neatly printed to the console
        vector<string> printGuess;

    public: 
        //Checks how correct the guess is compared to the correct word
        bool correctCheck(vector<char> &rightWord, vector<char> &guessWord);
        //Prints to console 
        void printBoard();
        //Checks if user inputs a valid word
        bool isValid(string input, vector<string> &words);
        //Adds modified strings to "printGuess" vector
        bool addtoBoard(string s);
        //resizes "printGuess" vector and sets every element to "-"
        GameSolve();


};

#endif
