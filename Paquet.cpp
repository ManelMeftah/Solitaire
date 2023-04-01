#include "Paquet.h"

using namespace::std;

Paquet::Paquet()
{
    init();
}

void Paquet::init()
{
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    //-------------------------INIT------------------------
    for(int i=0; i<size; i++)
        paquet.push_back(new Card(i));

    // shuffle(paquet.begin(), paquet.end(), default_random_engine(seed));
    for(int i=0; i<size; i++)
    {
        paquet[i]->setPos(i);
    }
    // showPaquet();
    
}

void Paquet::showPaquet()
{
    cout<<"VOTRE PAQUET:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"Carte numero " << to_string(paquet[i]->getPos()+1) << " du paquet " ;
        paquet[i]->afficheDetail();
    }
}

void Paquet::showList()
{
    cout<<"LISTE : " << endl;
    for(int i=0; i<size; i++)
    {
        paquet[i]->afficheListe();
    }
}

void Paquet::stepOne()
{
    Card* jn = find("JN");
    
    cout << endl << "JOKER NOIR TROUVE A POSITION " << jn->getPos()<< endl; 
    permut(jn->getPos());
    showList();
}

void Paquet::stepTwo()
{
    Card* jr = find("JR");
    cout<<endl<<endl<<endl;
    cout << endl << "JOKER ROUGE TROUVE A POSITION " << jr->getPos()<< endl; 
    permut(jr->getPos());
    permut(jr->getPos());

    showList();
}

void Paquet::stepThree()
{
    
}

Card* Paquet::find(string name)
{
    int i=0;
    Card* c = nullptr;
    bool flag = false;
    do
    {
        if (paquet[i]->getName()==name)
        {
            c = paquet[i];
            flag=true;
        } 
        i++;
    }while(!flag && i < size);
    return c;
}

void Paquet::permut(int pos) {
    if (pos < 0 || pos >= size) { // vérifier si pos est valide
        cout<<"ERREUR: position de la carte invalide : " << pos <<endl <<endl;
        return;
    }
    if (pos == size - 1) { // si la carte est à la dernière position
        Card* tmp = paquet[pos];
        paquet[pos] = paquet[0];
        paquet[0] = tmp;

        paquet[pos]->setPos(pos);
        paquet[0]->setPos(0);
    } else {
        Card* tmp = paquet[pos];
        paquet[pos] = paquet[pos+1];
        paquet[pos+1] = tmp;

        paquet[pos]->setPos(pos);
        paquet[pos+1]->setPos(pos+1);
    }
}


// void Paquet::permut(int pos1, int pos2)
// {
//     Card* tmp = paquet[pos1];
//     paquet[pos1] = paquet[pos2];
//     paquet[pos2] = tmp;

//     paquet[pos1]->setPos(pos1);
//     paquet[pos2]->setPos(pos2);

// }

// void Paquet::shift(Card* j)
// {
//     paquet.insert(paquet.begin(), j);
// }

