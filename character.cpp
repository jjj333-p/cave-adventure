//
// Created by joseph on 2/3/23.
//

#include <iostream>
#include "character.h"

character::character(rooms (&m)[5][5], const std::string &n) : name(n) {
//    std::copy(&m[0][0], &m[0][0] + 5 * 5, &map[0][0]);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            this->map[i][j] = map[i][j];
        }
    }
    name = n;
}

//returns 0 if failed to move, 1 if couldnt move because inside, 2 if moved
int character::move(const int &right, const int &up) {

    //can only move one unit in each direction at a time
    if(right > 1 || right < -1 || up > 1 || up < -1){

        std::cout << "movement size exceeded. you should not be seeing this error";

        return 0;

    }

    //if inside a room that can only be exited the way you went in
    if(map[x][y].get_movability() == 1){

        //if going back out the same way, you can exit
        //if not going back out the right way return that it cant move because inside
        if ( !( (x+right== prev_x) && (y+up == prev_y) ) ) { return 1; }

    }

    std::cout << map[x+right][y+up].get_name();

    //if cannot move into the room, return out that it failed to move
    if(map[x+right][y+up].get_movability() == 0) {

        return 0; }

    //if passed error checking then movement procedure

    //set previous coordinates
    prev_x = x;
    prev_y = y;

    //set new current coordinates
    x = x+right;
    y = y+up;

    return 2;

}

bool character::add_item(const worlditems& item) {

    //look through the room items until find one that is empty
    for (auto & i : inventory) {

        if(i.getID() == "empty"){

            //set found item slot to the item given
            i = item;

            //return true that a slot was found and the item was put there
            return true;

        }

    }

    //if the code couldnt find somewhere to put that item, return false
    return false;

}

worlditems character::remove_item(const int& position) {

    //grab item to return after
    worlditems item = inventory[position];

    //set to empty item
    inventory[position] = worlditems((std::string &) "empty");

    //return the item that was found at that position
    return item;

}