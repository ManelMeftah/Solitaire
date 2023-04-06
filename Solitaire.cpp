#include <iostream>
#include <vector>


#include "Card.h"
#include "Paquet.h"

using namespace::std;

Paquet* p;



void crypter()
{
    string message = "";
    cout << "Veuillez saisir le message a crypter: " << endl;
    cin >> message;

    string messageC = p->crypteMessage(message);
}

void decrypter()
{
    string message = "";
    cout << "Veuillez saisir le message a decrypter: " << endl;
    cin >> message;

    string messageC = p->decrypteMessage(message);
}

void afficheMenu2()
{
    int choix;
    string fname = "";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menu:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "1. Charger un deck" << endl;
    cout << "2. Generer un deck aleatoirement" << endl;
    cout << "3. Selectionner un deck pre-melange" << endl;
    cout << "Entrez votre choix: ";
    cin >> choix;

    switch (choix) {
        case 1:
            cout << "Saisir nom fichier : " << endl;
            cin >> fname;
            p->init(fname);
            break;
        case 2:
            // code pour generer un deck aleatoirement
            cout << "Donnez un nom a votre deck : " << endl;
            cin >> fname;
            p->initRandom(fname);
            break;
        case 3:
            // code pour selectionner un deck pre-melange
            p->initDefault();
            break;
        default:
            cout << "Choix invalide" << endl;
            break;
    }

}

void afficheMenu1()
{
    int choix;
    // string fname = "";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menu:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "1. Crypter" << endl;
    cout << "2. Decrypter" << endl;
    cout << "Entrez votre choix: ";
    cin >> choix;

        switch (choix) {
        case 1:
            afficheMenu2();
            crypter();
            break;
        case 2:
            afficheMenu2();
            decrypter();
            break;
        default:
            cout << "Choix invalide" << endl;
            break;
    }

}

void test()
{
    p = new Paquet();

    // p->melangePaquet();
    // p->stepFive();
    string message = "abcd kjegf"; //icup
    string messageCrypte = p->crypteMessage(message);
    p->init();
    string messageDecrypte = p->decrypteMessage(messageCrypte);
}

void run()
{
    p = new Paquet();
    char choix;
    do
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SOLITAIRE CYPHER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        afficheMenu1();
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Recommencer? (o/n)" << endl;
    }while(choix != 'n');

    cout << "Au revoir!" << endl;
}


int main(int argc, char *argv []) 
{
    run();
    // test();



}
