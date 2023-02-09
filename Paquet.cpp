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
        cout<<"Carte numero " << to_string(i+1) << " du paquet " ;
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
    // int i=0;
    // Card* jn;
    // bool flag = false;
    // do
    // {
    //     if (paquet[i]->getName()=="JN")
    //     {
    //         jn = paquet[i];
    //         jn->setPos(i);
    //         flag=true;
    //     }
    //     else
    //     {  
    //         i++;
    //     }
    // }while(!flag);

    Card* jn = find("JN");
    cout << endl << "JOKER NOIR TROUVE A POSITION " << jn->getPos()+1<< endl; 
    if(jn->getPos()==size-1)
    {
        permut(1, size-1);
        jn->setPos(0);
    }
    else
    {
        permut(jn->getPos()+1, jn->getPos());
        jn->setPos(jn->getPos()+1);
    }
    showList();
    
}

void Paquet::stepTwo()
{
    Card* jr = find("JR");
    cout<<endl<<endl<<endl;
    cout << endl << "JOKER ROUGE TROUVE A POSITION " << jr->getPos()+1<< endl; 
    if(jr->getPos()==size-1)
    {
        permut(1, size-1);
        jr->setPos(0);
    }
    else if(jr->getPos()==size-2)
    {
        // permut(2, size-2);
        //Not a permutation,,, JN goes in pos 3 and cards
        // of pos 4 and above shift to pos+1
        jr->setPos(1);
    }
    else
    {
        permut(jr->getPos()+2, jr->getPos());
        jr->setPos(jr->getPos()+2);
    }
    showList();

}

Card* Paquet::find(string name)
{
    int i=0;
    Card* c;
    bool flag = false;
    do
    {
        if (paquet[i]->getName()==name)
        {
            c = paquet[i];
            flag=true;
        }
        else
        {  
            i++;
        }
    }while(!flag);
    return c;
}

void Paquet::permut(int pos1, int pos2)
{
    Card* tmp = paquet[pos1];
    paquet[pos1] = paquet[pos2];
    paquet[pos2] = tmp;

}

