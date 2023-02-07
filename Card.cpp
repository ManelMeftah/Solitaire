#include "Card.h"

#include <string>

using namespace::std;

Card::Card(unsigned int val)
{
    this->val = val+1;
    setName();
}

unsigned int Card::getVal()
{
    return this->val;
}

void Card::setVal(unsigned int val)
{
    this->val = val;
}
void Card::setName()
{
    string n = "";
    int rVal = val%13;
    switch(rVal){
        case 1:
            n+="As";
            break;
        case 11:
            n+="Valet";
            break;
        case 12:
            n+="Dame";
            break;
        case 0:
            n+="Roi";
            break;
        default : 
            n+= to_string(rVal);
            break;
    }

    if(val<=13)
        n += " de Trèfle";
    else if(val<=26)
        n+=" de Carreau";
    else if(val<=39)
        n+=" de Coeur";
    else
        n+=" de Pique";
    this->name = n;
}


void Card::affiche()
{
    // cout << "Carte n°" << getVal() << endl;
    cout << this->name << endl;
}

