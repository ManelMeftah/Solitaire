#include <iostream>
#include <vector>


#include "Card.h"
#include "Paquet.h"

using namespace::std;

Paquet* p;


//fonction qui supprime les espaces. peux etre etendues pour la suppression d'autres caracteres speciaux
string removeSpaces(string input) {
    string output = "";
    cout << "input = " << input << endl;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            output += input[i];
        }
        cout << input[i] << ' ';

    }
    cout << output << endl;
    return output;
}

//fonction qui appel crypteMessage qui cripte le message saisi par l'user
void crypter()
{
    string message = "";
    cout << "Veuillez saisir le message a crypter: " << endl;

     std::getline(std::cin >> std::ws, message); //saisie utilisateur
     message = removeSpaces(message); //suppression des espaces

    string messageC = p->crypteMessage(message);
}

//pareil pour decrypter
void decrypter()
{
    string message = "";
    cout << "Veuillez saisir le message a decrypter: " << endl;

    std::getline(std::cin >> std::ws, message);
    message = removeSpaces(message);

    string messageC = p->decrypteMessage(message);
}

//menu 2 de selection d'option de chargement de paquet
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
         //p->initDefault();
        p->init();
        break;
    default:
        cout << "Choix invalide" << endl;
        break;
    }

}

//menu 1 pour selection option cryptage/decryptage
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

//fonction test quelconque
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

//main run qui appel les menus
void run()
{
    p = new Paquet();
    char choix='o';
    do
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SOLITAIRE CYPHER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        afficheMenu1();
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Recommencer? (o/n)" << endl;
        cin >> choix;
    } while (choix == 'o');

    cout << "Au revoir!" << endl;
}


int main(int argc, char* argv[])
{
    // string message = "";

    run();
    // test();

}
 