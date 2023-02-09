#pragma once

#define CARD_H

#include <cmath>
#include <iostream>
#include <string>

using namespace::std;

class Card{
    private:
        unsigned int val, pos;
        string name;

    public:
        Card(unsigned int val);
        void setVal(unsigned int val);
        unsigned int getVal();
        void setName();
        string getName();
        void setPos(unsigned int p);
        unsigned int getPos();
        void afficheDetail();

        void afficheListe();
};