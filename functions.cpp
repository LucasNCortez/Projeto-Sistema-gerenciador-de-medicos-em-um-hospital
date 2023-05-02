#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "myHeader.hpp"

// Tipo estruturado para ter um contador para cada especialidade de médico
typedef struct especialidade{
  string especialidade;
  int count;
}ESPECIALIDADE;

// Adiciona uma string linhaEscrita ao fim de um arquivo de nome arquivoNome
void appendArquivo(string linhaEscrita, string arquivoNome){
  fstream arquivo;
  linhaEscrita += "\n";
  arquivo.open(arquivoNome, ios::app);
  arquivo << linhaEscrita;
  arquivo.close();
}

// Imprime a lista de médicos e suas especialidades guardadas num arquivo .txt de nome arquivoNome
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

// Imprime a lista de especialidades e quantidade de cada especialidade guardada num arquivo .txt de nome arquivoNome
void lerListaEspecialidades(string arquivoNome){
  fstream arquivo;
  vector<ESPECIALIDADE> especialidades;
  string linhaLeitura;

  arquivo.open(arquivoNome, ios::in);

  // Passa as especialiades gurdadas no arquivo .txt de nome arquivoNome para um vector de tipo ESPECIALIDADE, e armazena quantas tem de cada tipo especialidades[].especialidade num contador especialidades[].count
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

  // Imprime as especialidades
  for(int i = 0; i < especialidades.size(); i++){
    cout << "\nEspecialidade - " << especialidades[i].especialidade << " - (quant: " << especialidades[i].count << ")";
  }
  cout << endl;
}

// Insere num arquivo .txt de nome arquivoNome um novo agendamento de um médico já cadastrado
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

    // Procura o médico nos cadastros de médico
    while(getline(arquivoMedicos, linhaLeitura)){
      if (medico == linhaLeitura){
        arquivoMedicos.close();
        appendArquivo(medico ,"horarios.txt" );
        check = 1;
        break;
      }
    }
    
    if (check != 1){
      cout << "\nMedico não existente no sistema.\n";
      arquivoMedicos.close();
      
      while (true){
        int command;
        cout << "\n[1]Continuar\n[2]Voltar\n";
        cin >> command;
        if(command == 1){
          break;
        }else if (command == 2){
          return;
        }else{
          cout << "\nargumento \"" << command << "\" inválido\n";
        }
      }
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

// Função que pesquisa os agendamentos salvos num arquivo .txt de nome arquivoNome do médico desejado e os imprime
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

    // Procura os agendamentos do médico especificado, caso tenha, imprime os agendamentos
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
    while (true){
      int command;
      cout << "\n[1]Continuar\n[2]Voltar\n";
      cin >> command;
      if(command == 1){
        break;
      }else if (command == 2){
        return;
      }else{
        cout << "\nargumento \"" << command << "\" inválido\n";
      }
    }
  }
}

// Adiciona um médico e sua especialidade a um arquivo de .txt de nome ArquivoNome
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

// Altera a especialidade de um médico guardado num arquivo .txt de nome arquivoNome
void alterarEspecialidade(string arquivoNome){
  string medico, especialidade;
  fstream arquivo;
  string linhaLeitura;
  int check = 0;

  while (true){
    check = 0;
    arquivo.open(arquivoNome, ios::in | ios::out);
    cout << "\nDigite o médico que você quer alterar a especialidade: ";
    cin.ignore();
    getline(cin, medico);

    // Verifica se o médico está cadastrado
    while(getline(arquivo, linhaLeitura)){
      // Caso exista, altera sua especialidade
      if (medico == linhaLeitura){
        check = 1;

        cout << "\nAtualize a especialidade do médico: ";
        getline(cin, especialidade);

        string arquivoTempNome = "medicosTemp.txt";
        fstream arquivoTemp;
        
        arquivo.close();

        arquivo.open(arquivoNome, ios::in | ios::out);

        // Usa arquivo temporário para se receber a lista de medicos com a espcialidade atualizada
        while (getline(arquivo, linhaLeitura)){
          appendArquivo(linhaLeitura, arquivoTempNome);
          if (medico == linhaLeitura){
            getline(arquivo, linhaLeitura);
            appendArquivo(especialidade, arquivoTempNome);
          }
        }
        rename(arquivoTempNome.c_str(), "temp.txt");
        rename("medicos.txt", arquivoTempNome.c_str());
        rename("temp.txt", "medicos.txt");
        arquivoTemp.open(arquivoTempNome, ios::out | ios::trunc);
        arquivoTemp.close();

        return;
      }
    }
    
    if (check == 0){
      cout << "\nMedico não existente no sistema\n";
      arquivo.close();
    }

    while (true){
      int command;
      cout << "\n[1]Continuar\n[2]Voltar\n";
      cin >> command;
      if(command == 1){
        break;
      }else if (command == 2){
        return;
      }else{
        cout << "\nargumento \"" << command << "\" inválido\n";
      }
    }
  }
}

// Exclui cadastro do médico desejado do arquivo de arquivoNome
void excluirMedico(string arquivoNome){
  string medico;
  fstream arquivo;
  string linhaLeitura;
  int check = 0;

  while (true){
    check = 0;
    arquivo.open(arquivoNome, ios::in | ios::out);
    cout << "\nDigite o médico que você quer excluir: ";
    cin.ignore();
    getline(cin, medico);

    while(getline(arquivo, linhaLeitura)){
      if (medico == linhaLeitura){
        check = 1;

        string arquivoTempNome = "medicosTemp.txt";
        fstream arquivoTemp;

        arquivo.close();

        arquivo.open(arquivoNome, ios::in | ios::out);

        // Usa arquivo temporário para se receber a lista de medicos atualizada
        while (getline(arquivo, linhaLeitura)){
          // Verifica se o médico está cadastrado
          if (medico == linhaLeitura){
            getline(arquivo, linhaLeitura);
            getline(arquivo, linhaLeitura);
            appendArquivo(linhaLeitura, arquivoTempNome);
            getline(arquivo, linhaLeitura);

            // Tratamento caso médico esteja salvo na ultima linha do .txt
            if (linhaLeitura == ""){
              removeLastLine(arquivoTempNome);
            }else{
              appendArquivo(linhaLeitura, arquivoTempNome);
            }
          }else{
            appendArquivo(linhaLeitura, arquivoTempNome);
          }
        }
        arquivo.close();

        rename(arquivoTempNome.c_str(), "temp.txt");
        rename("medicos.txt", arquivoTempNome.c_str());
        rename("temp.txt", "medicos.txt");
        arquivoTemp.open(arquivoTempNome, ios::out | ios::trunc);
        arquivoTemp.close();

        return;
      }
    }
    
    if (check == 0){
      cout << "\nMedico não existente no sistema\n";
      arquivo.close();
    }

    while (true){
      int command;
      cout << "\n[1]Continuar\n[2]Voltar\n";
      cin >> command;
      if(command == 1){
        break;
      }else if (command == 2){
        return;
      }else{
        cout << "\nargumento \"" << command << "\" inválido\n";
      }
    }
  }
}

// Função que remove a última linha de um arquivo .txt de nome arquivoNome
void removeLastLine(string arquivoNome) {

    ifstream arquivoIn(arquivoNome);

    string arquivoNomeTemp = arquivoNome + ".tmp";
    ofstream arquivoOut(arquivoNomeTemp);

    string linhaLeitura;
    string linhaAnterior;

    while (getline(arquivoIn, linhaLeitura)) {
      if (!linhaAnterior.empty()) {
        arquivoOut << linhaAnterior << '\n';
      }
      linhaAnterior = linhaLeitura;
    }

    arquivoIn.close();

    if (!linhaAnterior.empty()) {
      arquivoOut << linhaAnterior;
    }

    arquivoOut.close();

    remove(arquivoNome.c_str());
    rename(arquivoNomeTemp.c_str(), arquivoNome.c_str());
}
