#include "Mario.h"
/*
EXERCISE #5A
Finish the declaration of the constructor
*/
Mario::Mario(int playerNum, int numStars, int numCoins, int numLives, int levelsCleared){
    this->playerNum = playerNum;
    this->numStars = numStars;
    this->numCoins = numCoins;
    this->numLives = numLives;
    this->levelsCleared = levelsCleared;
}

/*
EXERCISE #5B
Finish the declaration of the copy constructor
*/
Mario::Mario(Mario &p2) {
    this->playerNum = p2.getPlayerNum();
    this->numStars = p2.getNumStars();
    this->numCoins = p2.getNumCoins();
    this->numLives = p2.getNumLives();
    this->levelsCleared = p2.getLevelsCleared();
}

/*
EXERCISE #6
WARNING: To run the test cases in VSC, you will need to have finished the constructor in this file, 
in Moodle you will be able to run the test cases without completing the constructor

Return the Mario object that is making the decisions between the target Mario and the paremeter Mario
The Mario that makes the decisions is the one with the LOWEST number.  If both Mario's have the same
number, the target Mario should be returned.
*/
Mario Mario::decisionPlayer(Mario p2){
    if(this->getPlayerNum() > p2.getPlayerNum()){
        return p2;

    }
    else{
        return *this;
    }

}

/*
EXECISE #7
Add one to the amount of levels cleared if target Mario has at least 10 stars and 25 coins.
HINT: MUST USE GETTERS AND SETTERS
*/
void Mario::passedLevel() {
    if(this->getNumStars() >= 10 && this->getNumCoins() >= 25){
        setLevelsCleared(this->getLevelsCleared() + 1);
    }
}

/*
EXERCISE #8
Return true if target Mario has cleared enough levels to move to the next world.
Mario has to have cleared at least 5 levels.
*/
bool Mario::readyForNewWorld() {
    
    return (this->getLevelsCleared() >= 5);
}

/*
EXERCISE #9
Return true if Mario has at least 10 coins to buy a new star.
If Mario has enough coins, add one to the amount of stars Mario has
and reduce the number of coins by 10.
HINT: USE THE GETTERS AND SETTERS
*/
bool Mario::buyStar(){
    bool isAbleToBuy = false;

    if(this->getNumCoins() >= 10){
        isAbleToBuy = true;
        setNumCoins(this->getNumCoins() - 10);
        setNumStars(this->getNumStars() + 1);
    }
    return isAbleToBuy;
}

/*
EXERCISE #10
Return -1 if Mario will only survive one attack from Bowser
0 if Mario will survive two attacks from Bowser
1 if Mario will survive three or more attacks from Bowser
HINT: Mario will lose one live for every attack it survives
*/
int Mario::surviveBowser() {
    setNumLives(this->getNumLives() - 1);
    if(this->getNumLives() == 0){
        return -1;
    }
    else if(this->getNumLives() == 1){
        return 0;
    }
    else{
        return 1;
    }
}