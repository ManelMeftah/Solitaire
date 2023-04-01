#pragma once

#define PAQUET_H

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "Card.h"


using namespace::std;

class Paquet{
    private:
        unsigned int size = 54;
        vector<Card*> paquet;
    public:
        Paquet();   
        void init();
        void showPaquet();
        void showList();
        void stepOne();
        void stepTwo();
        void stepThree();

        Card *find(string name);

        void permut(int pos);
};