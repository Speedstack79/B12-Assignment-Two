/*
Author:     Halpin, Sean
Group:      Hernandez, Andrea; Hernandez, Antonio; 
            Hernandez, Enrique;
Assignment: Programming Assignment 2
Course:     COMP B12
Instructor: Richard Miles
Date Sub.:  2016/10/(Day Submitted)
*/

#include <vector>
#include "Menu_Include.h"
using namespace std;


int main(){
    vector<int> playerJerseys(0); 
    vector<int> playerRatings(0);/*
    for(int i = 0; i < playerJerseys.size(); ++i){
        playerJerseys[i] = i;
    }
    for(int i = 0; i <playerRatings.size(); ++i){
        playerRatings[i] = i;
    }*/
    vector<int>* players[] = {&playerJerseys, &playerRatings};
    runInit(players);
    //runInit(playerJerseys, playerRatings);
    return 0;
}