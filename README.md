# Projeto-Sistema-gerenciador-de-medicos-em-um-hospital

## Sistema simplificado de visualização de médicos e suas especialidades

### A.	Entrando com o perfil de atendente dá acesso a um menu com as seguintes opções:
  1.	Listar todos os médicos por nome e suas respectivas funções;
  2.	Listar todas as especialidades disponíveis e a quantidade de profissionais de cada uma;
  3.	Agendar horário para um determinado médico (nome e dia/horário);
  4.	Ver todos os agendamentos de uma determinado médico (pesquisar pelo nome);
  
### B.	Entrando com o perfil de gestor com uma senha de acesso (admin) para evitar que estranhos acessem informações indevidas, dá acesso a um menu com as seguintes opções: 
  1.	Listar todos os médicos por nome e suas respectivas funções;;
  2.	Listar todas as especialidades disponíveis e a quantidade de profissionais de cada uma;;
  3.	Adicionar um novo médico;;
  4.	Ver todos os agendamentos de uma determinado médico (pesquisar pelo nome);
  5.	Alterar a especialidade de um médico;
  6.	Excluir um médico;

### Funcionalidades: 
- Detecta comandos inválidos nos menus; 
- Presença de comandos de voltar e sair do programa; 
- Impressão formatada dos arquivos .txt;
- Menus de tentar novamente e cancelar ação;
- Informações cadastradas (médicos, especialidade e horários) são guardadas em arquivos .txt;

#### OBS: Feito no C++ com biblioteca padrão e modularizado para funcionamento em terminal

#### Comandos para execução:
 -   cd ./<diretorio onde estão os arquivos> 
 -   g++ -c main.cpp functions.cpp escolhas.cpp
 -   g++ -o programa main.o functions.o escolhas.o
 -   ./programa

##### Projeto realizado por aluno Lucas Cortez para a disciplina de Linguagem de Programação 1 pelo professor Janiheryson Felipe do Bacharelado em Tecnologia da Informação da UFRN
