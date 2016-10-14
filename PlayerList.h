#include <iostream>
#include <vector>
#include <limits>

#ifndef PlayerList_H
#define PlayerList_H

class PlayerList {
    public:
        PlayerList(void);
        int getValidNumber(int,int,char); //done
        int getMemberJersey(int);        //done
        void printAboveRating(void);      //done
        void printRoster(void);          //done
        void addPlayer(void);        //done
        void addMultiPlayer(void);
        void removePlayer(void);
        void updatePlayer(void);
        void runMenu(void);
        void printMenu(void);
    
    private:
        std::vector<int> jerseyNumbers;
        std::vector<int> ratingValues;
};
#endif
