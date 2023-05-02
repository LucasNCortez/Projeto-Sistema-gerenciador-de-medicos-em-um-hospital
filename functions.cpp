#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "myHeader.hpp"

typedef struct especialidade{
  string especialidade;
  int count;
}ESPECIALIDADE;

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
      cout << "argumento \"" << command << "\" inválido";
    }
  }
}

void escolhaAdmin(){
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
      cout << "argumento \"" << command << "\" inválido";
    }
  }
}

void appendArquivo(string linhaEscrita, string arquivoNome){
  fstream arquivo;
  linhaEscrita += "\n";
  arquivo.open(arquivoNome, ios::app);
  arquivo << linhaEscrita;
  arquivo.close();
}

void lerListaMedicos(string arquivoNome){
  string medico, especialidade;
  fstream arquivo;
  arquivo.open(arquivoNome, ios::in);
  cout << "\nMédicos:\n";
  while (getline(arquivo, medico)){
    getline(arquivo, especialidade);
    cout << "\n-> " << medico << " - " << especialidade;
  }
  arquivo.close();
  cout << endl;
}

void lerListaEspecialidades(string arquivoNome){
  fstream arquivo;
  vector<ESPECIALIDADE> especialidades;
  string linhaLeitura;

  arquivo.open(arquivoNome, ios::in);

  while (getline(arquivo, linhaLeitura)){
    getline(arquivo, linhaLeitura);
    int check = 1;
    for(int i = 0; i < especialidades.size(); i++){
      if (linhaLeitura == especialidades[i].especialidade){
        especialidades[i].count++;
        check = 0;
        break;
      }
    }
    if (check == 1){
      ESPECIALIDADE novaEspecialidade = {linhaLeitura, 1};
      especialidades.push_back(novaEspecialidade);
    }
  }

  cout << "\nEspecialidades:\n";

  for(int i = 0; i < especialidades.size(); i++){
    cout << "\nEspecialidade - " << especialidades[i].especialidade << " - (quant: " << especialidades[i].count << ")";
  }
  cout << endl;
}

void agendarHorario(string arquivoNome){
  string horario;
  fstream arquivoMedicos, arquivoHorarios;
  string medico;
  string linhaLeitura;
  int check = 0;

  while (true){
    arquivoMedicos.open("medicos.txt", ios::in);
    cout << "\nDigite o médico que você quer marcar um horário: ";
    cin.ignore();
    getline(cin, medico);

    while(getline(arquivoMedicos, linhaLeitura)){
      if (medico == linhaLeitura){
        arquivoMedicos.close();
        appendArquivo(medico ,"horarios.txt" );
        check = 1;
        break;
      }
      getline(arquivoMedicos, linhaLeitura);
    }
    arquivoMedicos.close();
    if (check != 1){
      cout << "\nMedico não existente no sistema.\n";
    }else{
      break;
    }
  }
  
  cout << "\nDigite o dia, mês, ano e hora da consulta: ";
  
  getline(cin, horario);
  arquivoHorarios.open("horarios.txt", ios::app);
  arquivoHorarios << "- " ;
  arquivoHorarios.close();
  appendArquivo(horario , "horarios.txt");
}

void verAgendamentos(string arquivoNome){
  string medico, horario;
  fstream arquivo;
  string linhaLeitura;
  string horarioIndentifier = "-";
  int check = 0;

  while (true){
    check = 0;
    arquivo.open("horarios.txt", ios::in);
    cout << "\nDigite o médico que você quer achar as consultas: ";
    cin.ignore();
    getline(cin, medico);

    while(getline(arquivo, linhaLeitura)){
      if (medico == linhaLeitura){
        check = 1;
        getline(arquivo, linhaLeitura);
        cout << linhaLeitura << endl;
      }
    }
    arquivo.close();
    
    if (check == 0){
      cout << "\nMedico não existente no sistema ou não possui consultas agendadas.\n";
    }

    int command;
    cout << "\n[1]Continuar\n[2]Voltar\n";
    cin >> command;
    if (command == 2){
      break;
    }
  }
}

void adicionarMedico(string arquivoNome){
  string medico;
  string especialidade;
  cin.ignore();

  cout << "\nDigite o nome do médico que você quer adicionar: ";
  getline(cin, medico);

  cout << "\nDigite a especialização do médico: ";
  getline(cin, especialidade);

  appendArquivo(medico, arquivoNome);
  appendArquivo(especialidade, arquivoNome);
}

void alterarEspecialidade(string arquivoNome){

}

void excluirMedico(string arquivoNome){

}