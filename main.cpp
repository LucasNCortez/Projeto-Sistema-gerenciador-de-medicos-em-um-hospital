#include <iostream>

using namespace std;

#include "myHeader.hpp"

int main(){
  int command;
  while (true){
    cout << "\n[1]Entrar como atendente\n[2]Entrar como administrador\n[3]Sair\n";
    cin >> command;
    if (command == 1){
      escolhaAtendente();
    }else if(command == 2){
      escolhaAdmin();
    }else if(command == 3){
      cout << "\nPrograma encerrado\n\n";
      return 0;
    }else{
      cout << "\nargumento \"" << command << "\" inválido\n";
    }
  }
}