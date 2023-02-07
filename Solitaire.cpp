#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "Card.h"

using namespace::std;

vector<Card*> cardList;


void showPaquet()
{
    for(int i=0; i<cardList.size(); i++)
    {
        cout<<"Carte numero " << to_string(i+1) << " " ;
        cardList[i]->affiche();
    }
}

int main(int argc, char *argv []) 
{
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    //-------------------------INIT------------------------
    for(int i=0; i<52; i++)
        cardList.push_back(new Card(i));

    showPaquet();

    //-------------------------SHUFFLE------------------------
    shuffle(cardList.begin(), cardList.end(), default_random_engine(seed));
    cout<<"SUFFLE----------------------------------"<<endl<<endl;
    showPaquet();        




}
