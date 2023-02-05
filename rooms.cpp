//
// Created by joseph on 2/3/23.
//

#include <string>
#include <utility>
#include "rooms.h"


rooms::rooms(
        std::string nombre, //name
        std::string desc, //description
        int mvblty, //movability
        std::string item1,
        std::string item2,
        std::string item3,
        std::string item4
    ) {

    //define all the items in the room
    items[0] =  worlditems(item1);
    items[1] =  worlditems(item2);
    items[2] =  worlditems(item3);
    items[3] =  worlditems(item4);

    //(0,1,2) where 0 is a full block, 1 it can be entered, 2 it can be moved through, no restrictions
    movability = mvblty;

    //descriptors
    name = std::move(nombre);
    description = std::move(desc);

}

//{ rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"); }
rooms::rooms() {

    //define all the items in the room
    items[0] =  worlditems((std::string &) "empty");
    items[1] =  worlditems((std::string &) "empty");
    items[2] =  worlditems((std::string &) "empty");
    items[3] =  worlditems((std::string &) "empty");

    //(0,1,2) where 0 is a full block, 1 it can be entered, 2 it can be moved through, no restrictions
    movability = 2;

    //descriptors
    name = "empty";
    description = "An empty space. Use your imagination!";

}

bool rooms::add_item(const worlditems& item) {

    //look through the room items until find one that is empty
    for (auto & i : items) {

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

worlditems rooms::remove_item(const int& position) {

    //grab item to return after
    worlditems item = items[position];

    //set to empty item
    items[position] = worlditems((std::string &) "empty");

    //return the item that was found at that position
    return item;

}