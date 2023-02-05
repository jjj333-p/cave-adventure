//
// Created by joseph on 1/30/23.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "worlditems.h"
#include "rooms.h"
#include "character.h"

//for some reason its easier to do this without error if i use dynamic memory
rooms map[5][5] = {
        {
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty")
        },
        {
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty")
        },
        {
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty")
        },
        {
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty")
        },
        {
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty"),
                rooms("empty", "An empty space. Use your imagination!", 2, "empty", "empty", "empty", "empty")
        }
};

int main(){

    //create character object
    character user = character(map, "name");

    //run loop
    while(true) {

        //grab a pointer to the current room to save computational power
        rooms currentRoom = map[user.get_x()][user.get_y()];

        //output info
        std::cout << "you are in " << currentRoom.get_name() << ". " << currentRoom.get_desc()
                  << " In this room there is:";

        //count how many items were listed
        int roomitemscount = 0;

        //grab list of items in room
        worlditems *roomitems = currentRoom.list_items();

        //iterate through said list
        for (int i = 0; i < 4; i++) {

            //get the name for that item
            std::string itemname = roomitems[i].getID();

            //if its just a placeholder item, skip it
            if (itemname != "empty") {

                roomitemscount++;

                std::cout << "\n - " << itemname;

            }

        }

        //if there were no items to list, inform the user
        if (roomitemscount < 1) { std::cout << " no items here."; }

        //pretty formatting for input
        std::cout << "\n > ";

        //get input
        std::string command;
        std::getline(std::cin, command);

        //convert commands to lower case for easier parcing (as found on the interwebs)
        std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        //help command
        if (command.substr(0, 4) == "help") {

            //idk what to put here yet
            std::cout << "idk, help yourself. i have nothing for you.";

        } else if (command.substr(0, 3) == "inv") {

            //fetch items
            worlditems* inventory = user.list_items();

            //print items
            for (int i = 0; i < 6; i++) {
                std::cout << i << ": " << inventory[i].getID() << "\n";
            }

        } else if (command.substr(0, 4) == "move") {

            int move_result;

            if (command.substr(5, 1) == "n") {

                if (command.substr(6, 1) == "e"){

                    move_result = user.move(1,1);

                } else if (command.substr(6,1) == "w"){

                    move_result = user.move(-1, 1);

                } else {

                    move_result = user.move(0, 1);

                }

            }

            if (command.substr(5, 2) == "s") {

                if (command.substr(7, 1) == "e"){

                    move_result = user.move(1, -1);

                } else if (command.substr(7,1) == "w"){

                    move_result = user.move(-1, -1);

                } else {

                    move_result = user.move(0, -1);

                }

            }

            //Handle the result of the move_result here
            if (move_result == 0) {
                std::cout << "You cannot move there.\n";
            } else if (move_result == 1) {
                std::cout << "you have entered.\n";
            } else if (move_result == 2) {
                std::cout << "successfully moved.\n";
            }

        }

//        else if (command.substr(0, 3) == "use") {
//
//            if (command.substr(4))
//
//        }

    }

}
