#ifndef CELL_H
#define CELL_H

#include "Item.h"
#include "Posn.h"

enum cellType { hWall, vWall, door, passage, tile, empty };
enum occType { Player, Enemy, Item, Gold, None };

/// general purpose storage for relevant game pointers

struct Occupier {
    bool occupied;
    occType occupierType;
    Player *p;
    Enemy *e;
    Item *i;
};

class Cell {
    private:
    cellType cellT;
    Occupier occ = {false, occType::None, nullptr, nullptr, nullptr};
    Posn pos;

public:
    /// CONSTRUCTORS
    Cell(Posn p, cellType c);
    Cell(Posn p, cellType c, Player &pl);
    Cell(Posn p, cellType c, Enemy &e);
    Cell(Posn p, cellType c, Item &i);

    /// INFORMATION-BASED FUNCTIONS

    Posn getPosn();
    bool occupied();
    occType getOccupierType();

    cellType type();

    Item* getItem();
    Enemy* getEnemy();

    bool playerCanMove();
    bool enemyCanMove();

    void print();

    /// INTERACTION WITH OTHER OBJECTS

    void addOccupant(Player &p);
    void addOccupant(Enemy &e);
    void addOccupant(Item &i);
    void transfer(Cell &c);
};

#endif
