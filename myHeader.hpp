#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#ifndef MYHEADER_HPP
#define MYHEADER_HPP

void escolhaAtendente();
void escolhaAdmin();
void appendArquivo(string linhaEscrita, string arquivoNome);
void lerListaMedicos(string arquivoNome);
void lerListaEspecialidades(string arquivoNome);
void agendarHorario(string arquivoNome);
void verAgendamentos(string arquivoNome);
void adicionarMedico(string arquivoNome);
void alterarEspecialidade(string arquivoNome);
void excluirMedico(string arquivoNome);
void removeLastLine(string filename);

#endif