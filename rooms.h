//
// Created by joseph on 2/3/23.
//

#ifndef PROJECT1_ROOMS_H
#define PROJECT1_ROOMS_H

#include "worlditems.h"

class rooms {

private:
    worlditems items[4];
    int movability; //(0,1,2) where 0 is a full block, 1 it can be entered, 2 it can be moved through, no restrictions
    std::string name, description;

public:
    rooms(std::string nombre, //name
          std::string desc, //description
          int mvblty, //movability
          std::string item1,
          std::string item2,
          std::string item3,
          std::string item4
            );

    //default constructor
    rooms();

    bool add_item(const worlditems& item);
    worlditems remove_item(const int& position);
    int get_movability(){ return movability; }
    std::string get_name() { return name; }
    std::string get_desc() { return description; }
    worlditems* list_items() { return items; } //no time to make this a safer function


    rooms& operator[](const int& index) {
        return this[index];
    }

};

#endif //PROJECT1_ROOMS_H
