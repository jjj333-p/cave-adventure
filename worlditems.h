//
// Created by joseph on 2/3/23.
//

#ifndef PROJECT1_WORLDITEMS_H
#define PROJECT1_WORLDITEMS_H

class worlditems {

private:
    std::string identifier;
    bool activated = false;

public:
    //dont want the identifier to be changeable
    std::string getID() { return identifier; }

    //written like this because i feel like if i allow direct bool access
    //i will inevitably screw the code all kinds of up
    bool is_activated() { return activated; }
    void activate() { activated = true; }
    void deactivate() { activated = false; }

    //default constructor
    worlditems() = default;

    //constructor
    explicit worlditems(std::string& id) { identifier = id; }

};

#endif //PROJECT1_WORLDITEMS_H
