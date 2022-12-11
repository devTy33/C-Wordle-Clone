//Ty Anderson

#include "wordle.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Constructor that fills our private vector with '-' at first for the sake of formatting
GameSolve::GameSolve(){
    printGuess.resize(30);
    for(int i = 0; i < 30; i++){
        printGuess[i] = "-";
    }
}

//Prints our new vector with the modified char/strings
void GameSolve::printBoard(){
    for(int i = 0; i < 30; i++){
        if(i % 5 == 0){
            cout << endl << endl;

        }
        cout << printGuess[i] << " ";
    }
    cout << endl;
}

//This gets called by correctCheck
//It places the new strings into the vector that we print out
bool GameSolve::addtoBoard(string s){
    int x = printGuess.size();
    for(int i = 0; i < x; i++){
        if(printGuess[i] == "-"){
            printGuess[i] = s;
            return true;
        }
    }
    return false;
}

bool GameSolve::correctCheck(vector<char> &rightWord, vector<char> &guessWord){
    string s;
    int x = rightWord.size();
    int isWon = 0;
    int count = 0;

    //outer loop
for(int i = 0; i < x; i++){
    //Checks if the character is correct
    if(rightWord[i] == guessWord[i]){
        s.clear();
        s.push_back('|');
        s.push_back(guessWord[i]);
        s.push_back('|');
        addtoBoard(s);
        s.clear();

        isWon++;

    }
    else {
        //inner loop
        //Checks if the character is in the word
        for(int j = 0; j < x; j++){
            if(guessWord[i] == rightWord[j]){
                
                s.clear();
                s.push_back('*');
                s.push_back(guessWord[i]);
                addtoBoard(s);
                s.clear();
                count = 1;
                break;
            }
            
        }
        //If the character is not in the word than it's completely wrong
        if(count != 1){
                
                s = guessWord[i];
                addtoBoard(s);
        }
        count = 0;
    }
    
}

printBoard();
//check if game is over or not
if(isWon == 5) return true;
return false;
}

//Check to see if input is in the list of words and is the right length
bool GameSolve::isValid(string s, vector<string> &words){
    int x = words.size();
    for(int i = 0; i < x; i++){
        if(words[i] == s && s.size() == 5){
            return true;
        }
    }
    return false;
}

int main() {
    GameSolve play; //Class instance

    vector<string> words;
    string input;
    string wordl;
    string data;
    ifstream fin;
    int guessCount = 0;

    //push all words into a vector 
    fin.open("valid-wordle-words.txt");
    while(getline(fin, data)){
        words.push_back(data);
    }

    //random number generator based on how many word possbilities there are 
    srand(time(0));
    int r = rand() % 12971 + 0;

    wordl = words[r];   //this is the word we are trying to guess
    
    cout << wordl << endl;   //!!!!!!(Delete this comment for testing so you can see what the word is before you start guessing)!!!!!!

    //Turn word into vector of chars 
    int s = wordl.size();
    vector<char> rightWord(s);
    for(int i = 0; i < s; i++){
        rightWord[i] = wordl[i];    
    }

    //Play the Game
    cout << "Make your first guess " << endl;
        while(true){
            cin >> input;
            int g = input.size();
            if(play.isValid(input, words) == true){
                guessCount++;
                 vector<char> guessWord(g);
                for(int i = 0; i < g; i++){
                    guessWord[i] = input[i];    
                }
                if(play.correctCheck(rightWord, guessWord) == true){
                    cout << "You Win !";
                    break;
                }
            }
            else{ cout << "Invalid Word. Try Again. " << endl;}
        
        //Make sure the user hasn't guessed 3 times.
            if(guessCount == 6){
                cout << "You Lose. The word was: " << wordl;
                break;
            }


        }


}
//s 3
