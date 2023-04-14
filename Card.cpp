#include "Card.h"

Card::Card(unsigned int val)
{
    this->val = val + 1;
    setName();
}

void Card::setVal(unsigned int val)
{
    this->val = val;
}

unsigned int Card::getVal()
{
    return val;
}

//affecte un nom a la carte en fonction de sa valeur (l’as de trefle a ainsi la valeur 1, le roi de pique a la valeur 52)
void Card::setName()
{
    string n = "";

    if (val == 53)
    {
        n += "JR";

    }
    else if (val == 54)
    {
        n += "JN";
        setVal(53);

    }
    else
    {
        int rVal = val % 13;

        switch (rVal) {
        case 1:
            n += "As";
            break;
        case 11:
            n += "Valet";
            break;
        case 12:
            n += "Dame";
            break;
        case 0:
            n += "Roi";
            break;
        default:
            n += to_string(rVal);
            break;
        }

        if (val <= 13)
            n += " de Trefle";
        else if (val <= 26)
            n += " de Carreau";
        else if (val <= 39)
            n += " de Coeur";
        else
            n += " de Pique";
    }
    this->name = n;
}

//affichage de la carte 
void Card::afficheListe()
{
    if (val == 53)
    {
        cout << this->name;
    }
    else
    {
        cout << this->val;
    }
    cout << "[" << this->pos << "]" << ", ";
}

string Card::getName()
{
    return name;
}

void Card::setPos(unsigned int p)
{
    pos = p;
}

unsigned int Card::getPos()
{
    return pos;
}

//affichage detaillé de la carte
void Card::afficheDetail()
{
    cout << name << "(" << val << ")[" << pos << "]" << endl;
}

