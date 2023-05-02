#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "myHeader.hpp"

// Mostra as opções do menu de atendente e recebe a escolha do usuario
void escolhaAtendente(){
  string command;
  while (true){
    cout << "\n[1]Listar médicos\n[2]Listar especialidades disponíveis\n[3]Agendar horário\n[4]Visualizar agendamentos de médico\n[5]Voltar\n";
    cin >> command;
    if (command == "1"){
      lerListaMedicos("medicos.txt");
    }else if(command == "2"){
      lerListaEspecialidades("medicos.txt");
    }else if(command == "3"){
      agendarHorario("horarios.txt");
    }else if(command == "4"){
      verAgendamentos("horarios.txt");
    }else if(command == "5"){
      return;
    }else{
      cout << "\nargumento \"" << command << "\" inválido\n";
    }
  }
}

// Mostra as opções do menu de admin e recebe a escolha do usuario
void escolhaAdmin(){
  // Pede pela senha de admin para acessar os comandos de admin
  string senha = "1234";
  string senhaInput = " ";
  while (true){
    cout << "\nDigite a senha de admin: ";
    cin.ignore();
    getline(cin, senhaInput);
    if (senha == senhaInput){
      cout << "\nAcesso permitido\n";
      break;
    }else{
      cout << "\nSenha incorreta\n";
      return;
    }
  }
  string command;
  while (true){
    cout << "\n[1]Listar médicos\n[2]Listar especialidades disponíveis\n[3]Adicionar médico\n[4]Visualizar agendamentos de médico\n[5]Alterar especialidade de médico\n[6]Excluir médico\n[7]Voltar\n";
    cin >> command;
    if (command == "1"){
      lerListaMedicos("medicos.txt");
    }else if(command == "2"){
      lerListaEspecialidades("medicos.txt");
    }else if(command == "3"){
      adicionarMedico("medicos.txt");
    }else if(command == "4"){
      verAgendamentos("horarios.txt");
    }else if(command == "5"){
      alterarEspecialidade("medicos.txt");
    }else if(command == "6"){
      excluirMedico("medicos.txt");
    }else if(command == "7"){
      return;
    }else{
      cout << "\nargumento \"" << command << "\" inválido\n";
    }
  }
}
