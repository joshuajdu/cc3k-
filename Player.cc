#include <string>
#include <stdlib.h>
#include <iostream>
#include "Player.h"
#include "Posn.h"
#include "Enemy.h"

using namespace std;

Player::Player(int hp, int atk, int def, string race):
	       maxhp{hp}, hp{hp}, baseatk{atk}, atk{atk}, basedef{def}, def{def},
               race{race}, barrier_suit{false}, compass{false} {}

string Player::get_race(){
    return race;
}

int Player::get_maxhp(){
    return maxhp;
}
int* Player::get_hp(){
    return &hp;
}
int Player::get_baseatk(){
    return baseatk;
}
int* Player::get_atk(){
    return &atk;
}
int Player::get_basedef(){
    return basedef;
}
int* Player::get_def(){
    return &def;
}

void Player::Move(string direction){
    if (direction == "no"){
        p.y++;
    }
    else if (direction == "so"){
        p.y--;
    }
    else if (direction == "ea"){
        p.x++;
    }
    else if (direction == "we"){
        p.x--;
    }
    else if (direction == "ne"){
        p.x++;
        p.y++;
    }
    else if (direction == "nw"){
        p.y++;
        p.x--;
    }
    else if (direction == "se"){
        p.x++;
        p.y--;
    }
    else if (direction == "sw"){
        p.x--;
        p.y--;
    }
    else{
        //error
    }
}

void Player::Position(){
    cout << "x: " << p.x << " y: " << p.y << endl;
}


void Player::CalculateDamage(Enemy &enemy){

}




Dwarf::Dwarf(): Player(100, 20, 30, "Dwarf") {}

Elf::Elf(): Player(140,20,10,"Elf") {}

Orc::Orc(): Player(180,30,25,"Orc"){}



