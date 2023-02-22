#include <iostream>
#include <vector>


#include "Card.h"
#include "Paquet.h"

using namespace::std;




int main(int argc, char *argv []) 
{
    
  Paquet* p = new Paquet();
  p->showList();
  p->stepOne("JN");
  p->stepTwo();

}
