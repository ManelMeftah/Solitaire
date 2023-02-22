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

void Paquet::stepOne(string jname)
{
    Card* jn = find(jname);
    
    cout << endl << jname <<"TROUVE A POSITION " << jn->getPos()+1<< endl; 
    int newPos = jn->getPos();
    if(jn->getPos()==size-1)
    {
        shift(jn);
        newPos=0;
    }
    permut(newPos, newPos+1);

    // if(jn->getPos()==size-1)
    // {
    //     permut(1, size-1);
    //     // jn->setPos(0);
    // }
    // else
    // {
    //     permut(jn->getPos()+1, jn->getPos());
    //     // jn->setPos(jn->getPos()+1);
    // }
    showList();
    // showPaquet();
}

void Paquet::stepTwo()
{
    stepOne("JR");
    stepOne("JR");
    // Card* jr = find("JR");
    // cout<<endl<<endl<<endl;
    // cout << endl << "JOKER ROUGE TROUVE A POSITION " << jr->getPos()+1<< endl; 
    
    // int newPos;
    // if (jr->getPos() == size-2) {
    //     newPos = 1;
    // } else if (jr->getPos() == size-1) {
    //     newPos = 2;
    // } else {
    //     newPos = jr->getPos() + 2;
    // }
    // permut(jr->getPos(), newPos);
    // for (int i = jr->getPos(); i < size-1; i++) {
    //     paquet[i]->setPos(i+1);
    // }
    // paquet[size-1]->setPos(0);

    showList();
    // showPaquet();
    // cout << endl << "JOKER ROUGE TROUVE A POSITION " << jr->getPos()+1<< endl; 

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

void Paquet::permut(int pos1, int pos2)
{
    Card* tmp = paquet[pos1];
    paquet[pos1] = paquet[pos2];
    paquet[pos2] = tmp;

    paquet[pos1]->setPos(pos1);
    paquet[pos2]->setPos(pos2);

}

void Paquet::shift(Card* j)
{
    paquet.insert(paquet.begin(), j);

}

