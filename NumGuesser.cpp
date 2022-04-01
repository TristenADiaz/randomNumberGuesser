#include <iostream>
#include <string> 
#include <cstdlib>
/**
*@author Leviathan
*/
using namespace std;
    
  
    string name;
    int nToGuess;
    int nGuessed;
    int totalGuesses = 0;
    void resetGame();
    void setPlayerVars();
    void pGuess();
    void start();
    void gameThread();
    void gRules();
    void restartGame();
    string setPlayerName(string N);
    string getPlayerName();

int main(){
    gameThread();
}

void resetGame(){
    name = "unknown";
    nToGuess = 1000;
    nGuessed = 0;
    totalGuesses = 0;
}

string setPlayerName(string N){
    return name = N;
}

void setPlayerVars(){
        string n = "unknown";
        cin >> n;
        if(cin.fail() || n.length() > 16){
                cin.clear();
                cin.ignore(16, '\n');
                cout << "Your name cannot exceed 16 characters, nicknames work too! \n" ;
                 setPlayerVars();
                 return;
            }
         setPlayerName(n);
}

string getPlayerName(){
    return name;
}

int setPlayerGuess(int guess){
   return nGuessed = guess;
}

int getPlayerGuess(){
    return nGuessed;
}

int setGameVars(){
    return nToGuess = (rand() % 100)+ 1;
}

int getNtoGuess(){
    return nToGuess;
}


void pGuess(){
    int n = 0;
    cout << "\nYour Guess: ";
    cin >> n;

    if(cin.fail() || n > 100){
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<  "Your guess must be a number from 1 - 100 \n";
        pGuess();
    }
    setPlayerGuess(n);
   totalGuesses++;
}

void gRules(){
    cout << "\nRules of the Game: \nPlayers get unlimited trys! \n"
         << "Valid guesses are done in numbers, please don't use words. \n" 
         << "Lastly, Dont do drugs and have fun!\n"
         << "------------------------------------------------------------------- \n"
         << "Objective: "<< getPlayerName() << " is suppose to guess our Hidden number, which ranges from 1 to 100 \n"
         << "Once you've guessed it correctly, the game ends, and you win! Have Fun!"
         << "------------------------------------------------------------------- "
          << endl;
}

void start(){
    cout << "Welcome to GUESS! THAT! NUMBER!!!!!!!! \nLet's start with your name! " << endl;
    setPlayerVars();
    setGameVars();
    cout << "I wish you the best of luck " <<  getPlayerName() << "!\n";
    gRules();

}
void restartGame(){
    char c;

    cin >> c;
    cout << cin.fail() << c << endl;
    
    if(c == 'y'){
        gameThread();
        return;
    }
    if(c == 'n')
        return;

        
    if(cin.fail() || c != 'n' || c != 'y' ){
        cin.clear();
        cin.ignore(2, '\n');
        cout << "Its literally 1 character, y or n... dont be this way T_T \n" << "P.S. it must be lowercase or u bad. \n";
        cin >> c;


        if(cin.fail() || c != 'n' || c != 'y' ){
            cin.clear();
            cin.ignore(2, '\n');
            cout << "I cant believe you've doen this... i'll take my leave now. YEEEEEEEEEEEEEEEEEEEET!" << endl;
        }

    }


}

void gameThread(){
    start();
    while(getPlayerGuess() != getNtoGuess()){
        pGuess();

        if(getPlayerGuess() != getNtoGuess()){
            if(getPlayerGuess() > getNtoGuess())
                cout << "Incorrect! Your Guess, " << getPlayerGuess() << ", is higher than our Hidden number!";

            if(getPlayerGuess() < getNtoGuess())
                cout << "Incorrect! Your Guess, " << getPlayerGuess() << ", is less than our Hidden number!"; 
        } else{
                cout << "Congrats to "<< getPlayerName() << "! You've guessed our number! Our Hidden Number was " << getNtoGuess() << "!\n"
                 << "Total Guesses made: " << totalGuesses << "\n"
                    << "Thanks for Playing! \n\n" << endl;
                    resetGame();
                cout << "Would you like to play again? Y / N " << endl;
                restartGame();
            break;
        }

    }
}




