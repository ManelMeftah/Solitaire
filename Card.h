#pragma once

#define CARD_H

#include <cmath>
#include <iostream>
#include <string>

using namespace::std;

class Card{
    private:
        unsigned int val;
        string name;

    public:
        Card(unsigned int val);
        unsigned int getVal();
        void setVal(unsigned int val);
        void setName();
        void affiche();

};