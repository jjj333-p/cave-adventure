//
// Created by joseph on 1/30/23.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
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
        rooms* currentRoom = &map[user.get_x()][user.get_y()];

        //output info
        std::cout << "you are in " << currentRoom->get_name() << " (" << user.get_x() << ", " << user.get_y() << "). " << currentRoom->get_desc()
                  << " In this room there is:";

        //count how many items were listed
        int roomitemscount = 0;

        //grab list of items in room
        worlditems *roomitems = currentRoom->list_items();

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

            int move_result, up, right;

            if (command.substr(5, 1) == "n") {

                if (command.substr(6, 1) == "e") {

                    right = 1;
                    up = 1;

                    move_result = user.move(right, up);

                } else if (command.substr(6, 1) == "w") {

                    right = -1;
                    up = 1;

                    move_result = user.move(right, up);

                } else {

                    right = 0;
                    up = 1;

                    move_result = user.move(right, up);

                }

            }
            if (command.substr(5, 2) == "s") {

                if (command.substr(6, 1) == "e") {

                    right = 1;
                    up = -1;

                    move_result = user.move(right, up);

                } else if (command.substr(6, 1) == "w") {

                    right = -1;
                    up = -1;

                    move_result = user.move(right, up);

                } else {

                    right = 0;
                    up = -1;

                    move_result = user.move(right, up);

                }

            } else if (command.substr(5, 2) == "w") {

                right = -1;
                up = 0;

                move_result = user.move(right, up);

            } else if (command.substr(5, 2) == "e") {

                right = 1;
                up = 0;

                move_result = user.move(right, up);

            }

            if(user.get_x()+right < 0 || user.get_x()+right > 4 || user.get_y()+up < 0 || user.get_y()+up > 4){

                std::cout << "That is out of bounds!\n";

            } else {

                //what room did it attempt to jump to for error checking
                rooms *attemptedroom = &map[user.get_x() + right][user.get_y() + up];

                //Handle the result of the move_result here
                switch (move_result) {
                    case 0:
                        std::cout << "You cannot move there. There is a " << attemptedroom->get_name() << " there. "
                                  << attemptedroom->get_desc() << "\n";
                        break;
                    case 1:
                        std::cout << "you have entered.\n";
                        break;
                    case 2:
                        std::cout << "successfully moved.\n";
                        break;
                    default:
                        std::cout << "Ï dont know what happened, but it was clearly disastrous. Result code "
                                  << move_result << ".\n";
                        break;
                }

            }

        } else if (command.substr(0, 3) == "use") {

            std::istringstream iss(command);
            std::string first, second;
            iss >> second >> first >> second;
            // first and second now contain the next two words after the "use" command

            //check if first item is specified
            if (first.empty()) {

                std::cout << "And what exactly are you planning to use??";

            } else  if (first == "empty") {

                std::cout << "What do you plan to do with a whole lot of nothingness?";

            } else {

                int inv_pos = user.has(first);

                //error return
                if (inv_pos < 0) {

                    std::cout << "You dont have " << first << "!\n";

                //check if second item is specified
                } else if (second.empty()) {

                    std::cout << "What are you going to use " << first << " on?";

                } else if (second == "empty") {

                    std::cout << "What is " << first << " supposed to do to nothing?";

                } else {

                    int room_item_pos = currentRoom->has(second);

                    //error return
                    if (room_item_pos < 0) {

                        std::cout << "There is no " << second << " to use " << first << " on.";

                    }

                }

            }

        }

        //make nicer
        std::cout << "\n";

    }

}
