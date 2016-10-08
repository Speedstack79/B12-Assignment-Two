#include <iostream>
#include <vector>
using namespace std;

class PlayerList {
    public:
        PlayerList(void);
        int getValidJersey(void);
        int getValidRating(void);
        int getMemberJersey(int);
        void printAboveRating(int);
        void printRoster(void);
        void addPlayer(int, int);
        void advAddPlayer(int);
        void removePlayer(int);
        void updatePlayer(int, int);
        void runMenu(void);
    
    private:
        vector<int> jerseyNumbers();
        vector<int> ratingValues();
    
};

PlayerList::PlayerList(){
    vector<int> jerseyNumbers(0);
    vector<int> ratingValues(0);
}
/*
PlayerList::PlayerList(vector<int>& initJerseyNumbers, vector<int>& initRatingValues){
    vector<int> jerseyNumbers = initJerseyNumbers;
    vector<int> ratingValues = initRatingValues;
}
*/
int PlayerList::getValidJersey(){
    return 0;
}
int PlayerList::getValidRating(){
    return 0;
}
int PlayerList::getMemberJersey(int fndJerseyNumber){
    int retIndex = -1;
    
    return retIndex;
}
void PlayerList::printAboveRating(int ratingAbove){
    
}
void PlayerList::printRoster(){
    
}
void PlayerList::addPlayer(int newJerseyNumber, int newRatingValue){
    
}
void PlayerList::removePlayer(int delJerseyNumber){
    
}
void PlayerList::updatePlayer(int jerseyNumber, int newRatingValue){
    
}
void PlayerList::advAddPlayer(int numPlayers){
    
}
void PlayerList::runMenu(){
    
}