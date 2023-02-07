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
    std::string name;

public:
    character(const std::string& n) : name(n){}

    //returns 0 if failed to move, 1 if couldnt move because inside, 2 if moved
    int move(int right, int up);

    bool add_item(worlditems& item);
    worlditems remove_item(int position);

    //returns index that it found that item, returns -1 if not found
    int has(const std::string& id);

    int get_x () const { return x; }
    int get_y () const { return y; }

    //no time to make this a safer function
    worlditems* list_items() { return inventory; }

    worlditems* use_item(int i) { return &(inventory[i]); } //at this point idk any better way

    int get_score() { return score; }

    void increase_score(int i) { score += i; }


};


#endif //PROJECT1_CHARACTER_H
