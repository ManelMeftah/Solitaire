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

    shuffle(paquet.begin(), paquet.end(), default_random_engine(seed));
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
    cout << endl;
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
        // Trouver les positions des deux jokers


    Card* jA = find("JN");
    Card* jB = find("JR");

    if(jA->getPos()>jB->getPos())
    {
        Card* tmp = jA;
        jA = jB;
        jB = tmp;
    }
    int posA = jA->getPos();
    int posB = jB->getPos();
    cout << "pos a "<< posA << " pos b " << posB << endl;

    
    if (posA == -1 || posB == -1) {
        // Les deux jokers ne sont pas présents dans le paquet
        cout << "ERREUR JOKER NON TROUVE" << endl;
        return;
    }

    // Extraire les trois sections de cartes
    vector<Card*> section1;
    vector<Card*> section2;
    vector<Card*> section3;
    for (int i = 0; i < size; i++) {
        if (i < posA) {
            section1.push_back(paquet[i]);
        } else if (i >= posA && i <= posB) {
            section2.push_back(paquet[i]);
        } else {
            section3.push_back(paquet[i]);
        }
    }

    // Reconstituer le paquet en intercalant les sections
    int index = 0;
    for (Card* c : section3) {
        paquet[index] = c;
        index++;
    }
    for (Card* c : section2) {
        paquet[index] = c;
        index++;
    }
    for (Card* c : section1) {
        paquet[index] = c;
        index++;
    }
    updatePos();
    showList();

}

void Paquet::stepFour()
{
    Card* last = paquet[size-1];
    cout <<endl << "derniere carte a valeur " << last->getVal() << " nom " << last->getName() << endl;
    int n = last->getVal();
        // Extraire les trois sections de cartes
    vector<Card*> section1;
    vector<Card*> section2;
    for (int i = 0; i < size; i++) {
        if (i < n)
        {
            section1.push_back(paquet[i]);
        } 
        else if (i>=n && i<size-1)
        {
            section2.push_back(paquet[i]);
        } 
    }
for (int i = 0; i < section1.size(); i++) {
    section1[i]->afficheListe();
}
    cout<<endl;

for (int i = 0; i < section2.size(); i++) {
    section2[i]->afficheListe();

}
        cout<<endl;

// Reconstituer le paquet en intercalant les sections
    int index = 0;
    for (Card* c : section2) {
        paquet[index] = c;
        index++;
    }
    for (Card* c : section1) {
        paquet[index] = c;
        index++;
    }
    paquet[index] = last;
    updatePos();

    showList();


}

//int stepFive()
void Paquet::stepFive()
{
    // Récupérer le numéro de la première carte
    int n = paquet[0]->getVal();
     Card* c = paquet[n];
    int m = c->getVal();
    if(m == 53)
    {
        //erreur joker
        // melangePaquet();
        // return stepFive();
    }
    else
    {
        if(m>26)
            m = m-26;

        char lettre = 'A' + m - 1;
        cout << "valeur " << m << " lettre " << lettre;
    }
}

void Paquet::updatePos()
{
    for(int i=0; i<size; i++)
        paquet[i]->setPos(i);
}

void Paquet::melangePaquet()
{
    stepOne();
    stepTwo();
    stepThree();
    stepFour();
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


void Paquet::permut(int pos1, int pos2)
{
    Card* tmp = paquet[pos1];
    paquet[pos1] = paquet[pos2];
    paquet[pos2] = tmp;

    paquet[pos1]->setPos(pos1);
    paquet[pos2]->setPos(pos2);

}

// void Paquet::shift(Card* j)
// {
//     paquet.insert(paquet.begin(), j);
// }

