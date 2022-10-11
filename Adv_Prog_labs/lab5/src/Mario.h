#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Mario{

private:
    int playerNum;
    int numStars;
    int numCoins;
    int numLives;
    int levelsCleared;


public:
    //Constructor
    Mario(int playerNum, int numStars, int numCoins, int numLives, int levelsCleared);

    //Copy Constructor 
    Mario(Mario &p2);

    // Getters
    int getPlayerNum() { return playerNum; }
    int getNumStars() { return numStars; }
    int getNumCoins() { return numCoins; }
    int getNumLives() { return numLives; }
    int getLevelsCleared() { return levelsCleared; }

    // Setters
    void setPlayerNum(int playerNum) { this->playerNum = playerNum; }
    void setNumStars(int numStars) { this->numStars = numStars; }
    void setNumCoins(int numCoins) { this->numCoins = numCoins; }
    void setNumLives(int numLives) { this->numLives = numLives; }
    void setLevelsCleared ( int levelsCleared ) { this->levelsCleared = levelsCleared; }


    string toString(){
    return "{Player: " + to_string(getPlayerNum()) + "," 
            + "Stars: " + to_string(getNumStars()) + ", "
            + "Coins: " + to_string(getNumCoins()) + ", "
            + "Lives: " + to_string(getNumLives()) + ", "
            + "Lvl Cleared: " + to_string(getLevelsCleared()) + "}";
    }

    //EXERCISES
    Mario decisionPlayer(Mario p2);
    void passedLevel();
    bool readyForNewWorld();
    bool buyStar();
    int surviveBowser();
};