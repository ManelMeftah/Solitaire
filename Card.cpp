// #include "Card.h"

// #include <string>

// using namespace::std;

// Card::Card(unsigned int val)
// {
//     this->val = val+1;
//     setName();
// }

// unsigned int Card::getVal()
// {
//     return this->val;
// }

// void Card::setVal(unsigned int val)
// {
//     this->val = val;
// }



// string Card::getName()
// {
//     return this->name;
// }

// void Card::setPos(unsigned int p)
// {
//     this->pos = p;
// }

// unsigned int Card::getPos()
// {
//     return this->pos;
// }

// void Card::afficheDetail()
// {
//     // cout << "Carte n°" << getVal() << endl;
//     cout << this->name << " a valeur de " << this->val << endl;
// }




#include "Card.h"

Card::Card(unsigned int val)
{
    this->val = val+1;
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


void Card::setName()
{
    string n = "";

    if(val==53)
    {
        n+="JR";        

    }
    else if(val==54)
    {
        n+="JN";
        setVal(53);

    }
    else
    {
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
    }
    this->name = n;
}

void Card::afficheListe()
{
    if(val==53)
    {
        cout << this->name ;
    }
    else
    {
        cout << this->val ;
    }
    cout << "[" << this->pos << "]" << ", ";
}


// void Card::setName()
// {
//     int suit = (val - 1) / 13;
//     int rank = (val - 1) % 13;

//     switch (suit)
//     {
//     case 0:
//         name = "C";
//         break;
//     case 1:
//         name = "D";
//         break;
//     case 2:
//         name = "H";
//         break;
//     case 3:
//         name = "S";
//         break;
//     }

//     switch (rank)
//     {
//     case 0:
//         name += "A";
//         break;
//     case 9:
//         name += "T";
//         break;
//     case 10:
//         name += "J";
//         break;
//     case 11:
//         name += "Q";
//         break;
//     case 12:
//         name += "K";
//         break;
//     default:
//         name += to_string(rank + 1);
//         break;
//     }
// }

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

void Card::afficheDetail()
{
    cout << name << "(" << val << ")[" << pos << "]" << endl;
}

// void Card::afficheListe()
// {
//     cout << name << " ";
// }
