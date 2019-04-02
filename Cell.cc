#include "Cell.h"

using namespace std;

/// various overloaded constructors for each possibility

Cell::Cell(Posn p, cellType c): pos{p}, cellT{c} {}
Cell::Cell(Posn p, cellType c, Player &pl): pos{p}, cellT{c} {
    occ.occupied = true;
    occ.p = p1;
}
Cell::Cell(Posn p, cellType c, Enemy &e): pos{p}, cellT{c} {
    occ.occupied = true;
    occ.e = e;
}
Cell::Cell(Posn p, cellType c, Item &i): pos{p}, cellT{c} {
    occ.occupied = true;
    occ.i = i;
}

void Cell::setStairs() {stairs = true; occ.occupied = true;}

/// information-based functions

Posn Cell::getPosn() {return pos;}

bool Cell::isStairs() {return stairs;}

bool Cell::occupied() {return occ.occupied;}

occType Cell::getOccupierType() {return occ.occupierType;}

cellType Cell::type() {return cellT;}

Item* Cell::getItem() {return occ.i;}

Enemy* Cell::getEnemy() {return occ.e;}

bool Cell::playerCanMove() {
    if (!occupied() || occ.occupierType == occType::Gold_ || stairs) {
        if (cellT >= 2 && cellT <= 4) return true;
    }
    return false;
}

bool Cell::enemyCanMove() {
    return (!occupied() && cellT == cellType::tile);
}

void Cell::print(){
    if (this.occcupied()) {
        switch (occ.occupierType) {
        case occType::Player_: cout << "@"; break;
        case occType::Enemy_: occ.e->print(); break;
        case occType::Item_: occ.i->print(); break;
        case occType::Gold_: occ.i->print(); break;
        case occType::None_:
            if (stairs && compassFound) cout << "\\";
            else cout << ".";
        }
    } else {
        switch (cellT) {
        case cellType::hWall:     cout << "-"; break;
        case cellType::vWall:     cout << "|"; break;
        case cellType::door:      cout << "+"; break;
        case cellType::passage:   cout << "#"; break;
        case cellType::tile:      cout << "."; break;
        case cellType::empty:     cout << " "; break;
        }
    }

}

/// object interaction

void Cell::addOccupant(Player &p) {
    occ.p = p;
    occ.occupied = true;
    occ.occupierType = occType::Player_;
}
///### [[ add in win condition if Cell is staircase ]] ###
void Cell::addOccupant(Enemy &e) {
    occ.e = e;
    occ.occupied = true;
    occ.occupierType = occType::Enemy_;
}
void Cell::addOccupant(Item &i) {
    occ.i = i;
    occ.occupied = true;
    if (i->isGold()) occ.occupierType = occType::Gold_;
    else occ.occupierType = occType::Item_;
}

void Cell::transfer(Cell &c) {
    if (this.occupied() && !c->occupied()) {
        c->addOccupant(occ.p);
        c->addOccupant(occ.i);
        c->addOccupant(occ.e);
        occ.occupied = false;
        occ.e = nullptr; occ.i = nullptr; occ.p = nullptr;
    }
}

void Cell::compassFound() {compassFound = true;}

bool Cell::compassFound = false;
