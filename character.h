//
// Created by joseph on 2/3/23.
//

#ifndef PROJECT1_CHARACTER_H
#define PROJECT1_CHARACTER_H

#include "worlditems.h"
#include "rooms.h"


class character {

private:
    int x = 0 ,y = 0, prev_x = 0, prev_y = 0, score = 0;
    worlditems inventory[6];
    rooms map[5][5];
    std::string name;
    bool inside;

public:
    character(rooms (&m)[5][5], const std::string& n);

    //returns 0 if failed to move, 1 if couldnt move because inside, 2 if moved
    int move(const int& right, const int& up);

    bool add_item(const worlditems& item);
    worlditems remove_item(const int& position);

    int get_x () { return x; }
    int get_y () { return y; }
    worlditems* list_items() { return inventory; } //no time to make this a safer function

};


#endif //PROJECT1_CHARACTER_H
