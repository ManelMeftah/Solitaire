#include "Paquet.h"

using namespace::std;


Paquet::Paquet()
{
    init();
}

//initialise un deck ordonné de 1 a 54
void Paquet::init()
{
    unsigned seed = std::chrono::system_clock::now()
        .time_since_epoch()
        .count();
    //-------------------------INIT------------------------
    paquet.clear();
    for (int i = 0; i < size; i++)
        paquet.push_back(new Card(i));

    // shuffle(paquet.begin(), paquet.end(), default_random_engine(seed));
    for (int i = 0; i < size; i++)
    {
        paquet[i]->setPos(i);
    }


}

//cree un deck aleatoir nommé fname et le sauvegarde 
void Paquet::initRandom(string fname)
{
    unsigned seed = std::chrono::system_clock::now()
        .time_since_epoch()
        .count();
    //-------------------------INIT------------------------
    paquet.clear();
    for (int i = 0; i < size; i++)
        paquet.push_back(new Card(i));

    shuffle(paquet.begin(), paquet.end(), default_random_engine(seed));
    for (int i = 0; i < size; i++)
    {
        paquet[i]->setPos(i);
    }
    //sauvegarde l'etat initial du deck
    ofstream fichier(fname);

    if (fichier) {
        for (int i = 0; i < size; i++) {
            fichier << paquet[i]->getVal() << endl;
        }
        fichier.close();
    }
    else {
        cout << "Erreur: impossible d'ouvrir le fichier deck.txt" << endl;
    }
    init(fname);
    showPaquet();
}

//charge un deck par defaut ici c'est le deck ordonné de 1 a 54
void Paquet::initDefault()
{
    paquet.clear();
    for (int i = 1; i < size; i++)
        paquet.push_back(new Card(i));

    // shuffle(paquet.begin(), paquet.end(), default_random_engine(seed));
    for (int i = 0; i < size; i++)
    {
        paquet[i]->setPos(i);
    }
}


//charge le deck appelé dname
void Paquet::init(string dname)
{
    paquet.clear();
    ifstream file(dname);
    if (file.is_open()) {
        int val;
        while (file >> val) {
            paquet.push_back(new Card(val));
        }
        file.close();
    }
    for (int i = 0; i < size; i++)
    {
        paquet[i]->setPos(i);
    }
    // showList();
    showPaquet();

}

//affichahe detaillé du paquet
void Paquet::showPaquet()
{
    cout << "VOTRE PAQUET:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Carte numero " << to_string(paquet[i]->getPos() + 1) << " du paquet ";
        paquet[i]->afficheDetail();
    }
}

//affichage compacte du paquet en mode liste
void Paquet::showList()
{
    cout << "LISTE : " << endl;
    for (int i = 0; i < size; i++)
    {
        paquet[i]->afficheListe();
    }
    cout << endl;
}

void Paquet::stepOne()
{
    Card* jn = find("JN");

    cout << endl << "JOKER NOIR TROUVE A POSITION " << jn->getPos() << endl;
    permut(jn->getPos());
    showList();
}

void Paquet::stepTwo()
{
    Card* jr = find("JR");
    cout << endl << endl << endl;
    cout << endl << "JOKER ROUGE TROUVE A POSITION " << jr->getPos() << endl;
    permut(jr->getPos());
    permut(jr->getPos());

    showList();
}

void Paquet::stepThree()
{
    // Trouver les positions des deux jokers

    Card* jA = find("JN");
    Card* jB = find("JR");

    if (jA->getPos() > jB->getPos())
    {
        Card* tmp = jA;
        jA = jB;
        jB = tmp;
    }
    int posA = jA->getPos();
    int posB = jB->getPos();
    cout << "position joker a = " << posA << " posisiton joker b = " << posB << endl;

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
        }
        else if (i >= posA && i <= posB) {
            section2.push_back(paquet[i]);
        }
        else {
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
    Card* last = paquet[size - 1];
    cout << endl << "derniere carte a valeur " << last->getVal() << " nom " << last->getName() << endl;
    int n = last->getVal();
    // Extraire les trois sections de cartes
    vector<Card*> section1;
    vector<Card*> section2;
    for (int i = 0; i < size; i++) {
        if (i < n)
        {
            section1.push_back(paquet[i]);
        }
        else if (i >= n && i < size - 1)
        {
            section2.push_back(paquet[i]);
        }
    }

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

int Paquet::stepFive()
{
    // Récupérer le numéro de la première carte
    int n = paquet[0]->getVal();
    Card* c = paquet[n];
    int m = c->getVal();
    if (m == 53)
    {
        cout << endl << "Joker trouve, pas pris en compte, on remelange" << endl;
        melangePaquet();
        return stepFive();
    }
    else
    {
        if (m > 26)
        {
            m = m - 26;
        }


        return m;
    }
}

//fonction de generation de flux/ clé
void Paquet::genereFlux()
{
    for (int i = 0; i < taille; i++)
    {
        melangePaquet();
        flux[i] = stepFive();
        cout << "flux de " << i << " = " << flux[i];
    }

    cout << endl << "FLUX GENERE :" << endl;
    for (int i = 0; i < taille; i++) {
        char c = nth_letter(flux[i]);
        cout << c;
    }
}


//fonction qui crypte le message passé en paramètre -> effectue stepOne a stepFive autant de fois qu'il faut pour générer toute la clé
string Paquet::crypteMessage(string message)
{
    taille = message.length();
    flux = new int[taille]; //tableau flux contiens les numéros des lettres de l'alphabet 

    //on converti le message en majuscules
    for (size_t i = 0; i < taille; ++i) {
        if (islower(message[i])) {
            message[i] = toupper(message[i]);
        }
    }

    int* messageNum = new int[taille]; //tableau qui contiens les lettres du message converties en chiffres (A=1, B=2...)
    genereFlux(); //generation de la clé
    for (int i = 0; i < taille; i++) {
        messageNum[i] = message[i] - 'A' + 1;
    }
    cout << endl << "Flux en chiffres : ";
    for (int i = 0; i < taille; i++)
    {
        cout << flux[i] << " ";
    }
    cout << endl << "Message " << message << " en chiffres : ";
    for (int i = 0; i < taille; i++)
    {
        cout << messageNum[i] << " ";
    }
    cout << endl << "Message crypte " << " en chiffres : ADDITION" << endl;
    int* messageCrypteNum = new int[taille]; //tableau qui contiens les lettres du message crypté converties en numéros
    for (int i = 0; i < taille; i++)
    {

        messageCrypteNum[i] = messageNum[i] + flux[i];

        if (messageCrypteNum[i] > 26)
        {
            messageCrypteNum[i] -= 26;
        }
        cout << messageCrypteNum[i] << " = " << messageNum[i] << " + " << flux[i] << endl;


    }
    string messageCrypte = "";
    for (int i = 0; i < taille; i++) {
        char c = nth_letter(messageCrypteNum[i]);
        messageCrypte += c;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << endl <<endl << "Message crypte : " << endl << messageCrypte;
    //suppression des tableaux
    delete[] flux;
    delete[] messageCrypteNum;
    delete[] messageNum;
    return messageCrypte;

}


//meme principe que crypteMessage mais on soustrait au lieu d'additionner
string Paquet::decrypteMessage(string message)
{
    taille = message.length();
    flux = new int[taille];

    for (size_t i = 0; i < taille; ++i) {
        if (islower(message[i])) {
            message[i] = toupper(message[i]);
        }
    }

    int* messageNum = new int[taille];
    genereFlux();
    cout << endl << "Flux en chiffres : ";
    for (int i = 0; i < taille; i++)
    {
        cout << flux[i] << " ";
    }
    for (int i = 0; i < taille; i++) {
        messageNum[i] = message[i] - 'A' + 1;
    }
    cout << endl << "Message " << message << " en chiffres : ";
    for (int i = 0; i < taille; i++)
    {
        cout << messageNum[i] << " ";
    }
    cout << endl << "Message crypte " << " en chiffres : SOUSTRACTION";
    int* messageCrypteNum = new int[taille];
    for (int i = 0; i < taille; i++)
    {
        if (messageNum[i] < flux[i])
        {
            messageCrypteNum[i] = (messageNum[i] + 26) - flux[i];
        }
        else
        {
            messageCrypteNum[i] = messageNum[i] - flux[i];

        }
        if (messageCrypteNum[i] == 0)
            messageCrypteNum[i] = 26;
        cout << messageCrypteNum[i] << " = " << messageNum[i] << " - " << flux[i] << endl;


    }
    string messageCrypte = "";
    cout << endl << "Message decrypte en chars ";
    for (int i = 0; i < taille; i++) {
        char c = nth_letter(messageCrypteNum[i]);
        messageCrypte += c;
        cout << c;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    cout << endl << endl << "Message decrypte : " << endl << messageCrypte;
    delete[] flux;
    delete[] messageCrypteNum;
    delete[] messageNum;
    return messageCrypte;

}

//fonction qui renvoie la n ième lettre de l'alphabet
char Paquet::nth_letter(int n)
{
    return "abcdefghijklmnopqrstuvwxyz"[n - 1];
}

//met a jour les positions des cartes
void Paquet::updatePos()
{
    for (int i = 0; i < size; i++)
        paquet[i]->setPos(i);
}


//etapes 1 a 4 : melange le paquet
void Paquet::melangePaquet()
{
    stepOne();
    stepTwo();
    stepThree();
    stepFour();
}

//renvoie la carte nommée name 
Card* Paquet::find(string name)
{
    int i = 0;
    Card* c = nullptr;
    bool flag = false;
    do
    {
        if (paquet[i]->getName() == name)
        {
            c = paquet[i];
            flag = true;
        }
        i++;
    } while (!flag && i < size);
    return c;
}

//permute la carte en position pos avec celle qui est en dessous
void Paquet::permut(int pos) {
    if (pos < 0 || pos >= size) { // vérifier si pos est valide
        cout << "ERREUR: position de la carte invalide : " << pos << endl << endl;
        return;
    }
    if (pos == size - 1) { // si la carte est à la dernière position
        Card* tmp = paquet[pos];
        paquet[pos] = paquet[0];
        paquet[0] = tmp;

        paquet[pos]->setPos(pos);
        paquet[0]->setPos(0);
    }
    else {
        Card* tmp = paquet[pos];
        paquet[pos] = paquet[pos + 1];
        paquet[pos + 1] = tmp;

        paquet[pos]->setPos(pos);
        paquet[pos + 1]->setPos(pos + 1);
    }
}

//echange les cartes en positions pos1 et pos2
void Paquet::permut(int pos1, int pos2)
{
    Card* tmp = paquet[pos1];
    paquet[pos1] = paquet[pos2];
    paquet[pos2] = tmp;

    paquet[pos1]->setPos(pos1);
    paquet[pos2]->setPos(pos2);

}
