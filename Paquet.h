#pragma once

#define PAQUET_H

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>

#include "Card.h"


using namespace::std;

class Paquet{
    private:
        unsigned int size = 54;
        vector<Card*> paquet;
        int* flux;
        int taille;
    public:
        Paquet();   
        void init();
        void initRandom(string fname);
        void initDefault();
        void init(string dname);
        void showPaquet();
        void showList();
        void stepOne();
        void stepTwo();
        void stepThree();
        void stepFour();
        int stepFive();
        void genereFlux();
        string crypteMessage(string message);
        string decrypteMessage(string message);
        void updatePos();

        void melangePaquet();
        char nth_letter(int n);

        Card *find(string name);

        void permut(int pos);
        void permut(int pos1, int pos2);
};