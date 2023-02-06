//
// Created by joseph on 2/3/23.
//

#include <iostream>
#include <array>
#include "character.h"

//returns 0 if failed to move, 1 if couldnt move because inside, 2 if moved
int character::move(int right, int up) {

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

bool character::add_item(worlditems & item) {

    //look through the room items until find one that is empty
    for (int i = 0; i < 5; i++) {
//        worlditems* ii = &inventory[i];
//        std::cout << ii->getID() << "\n";

        if(inventory[i].getID() == "empty"){
            inventory[i] = item;
            return true;
        }
    }

    //if the code couldnt find somewhere to put that item, return false
    return false;

}

worlditems character::remove_item( int position) {

    //grab item to return after
    worlditems item = inventory[position];

    //set to empty item
    inventory[position] = worlditems("empty");

    //return the item that was found at that position
    return item;

}

int character::has(const std::string &id) {

    //look for item with a matching id
    for (int i = 0; i < 6; i++) {
        if (inventory[i].getID() == id) {

            //if found return that index and stop code
            return i;

        }
    }

    //if it couldnt find any, return an out of bounds value.
    return -1;

}