// objetivo: Fazer CRUD COMPLETO com arquivo
#include <iostream>
#include <string.h>
#include <fstream>
#include "aluno.h"
#include "avaliador.h"
#include "banca.h"
#include "fichas.h"
#include "menu.h"
#include "orientador.h"
using namespace std;

// Registro / Tipo de Variavel
class aluno
{   
    public:
    // INFO DO ALUNO CONCLUENTE
    char aluno_nome[50];   // Preenchimento obrigatório
    int aluno_matricula;   // Preenchimento obrigatório
    char aluno_curso[50];  // Preenchimento obrigatório
    char aluno_email[100]; // Preenchimento obrigatório
    short int aluno_semestre;
    long int aluno_tel_fixo;
    long int aluno_celular;
    short int aluno_frequencia;
    short int aluno_apto_defesa; // sim ou não, ou x>0 ou 0
    short int aluno_nota;        // nota que justifica o porquê de não estar apto

    void adicionar_aluno(aluno aluno) // variável aluno do tipo struct aluno
{
    cout<<"Nome do aluno: "<< endl;
    fgets(aluno.aluno_nome, 50, stdin);
    clearBuffer();
    cout<<"Curso:"<<endl;
    fgets(aluno.aluno_curso, 50, stdin);
    clearBuffer();
    cout<<"Email: "<<endl;
    fgets(aluno.aluno_email, 100, stdin);
    clearBuffer();
    cout<<"Matricula: "<<endl;
    cin>>aluno.aluno_matricula;
    cout<<"Semestre: "<<endl;
    cin>>aluno.aluno_semestre;
    cout<<"Telefone fixo:"<<endl;
    cin>>aluno.aluno_tel_fixo;
    cout<<"Telefone Celular: "<<endl;
    cin>>aluno.aluno_celular;
    cout<<"Frequencia do aluno: "<<endl;
    cin>>aluno.aluno_frequencia;
    cout<<"Apto a defesa(1 = sim 0 = nao): "<<endl;
    cin>>aluno.aluno_apto_defesa;
    cout<<"Justificativa de não aptdao: "<<endl;
    cin>>aluno.aluno_nota; // acredito que aqui deva ser um string
    cout<<aluno.aluno_nome;
    cout<<aluno.aluno_curso;
    cout <<aluno.aluno_email<<endl;
    cout <<aluno.aluno_matricula<< endl;
    cout<<aluno.aluno_semestre;
    cout<<aluno.aluno_tel_fixo;
    cout<<aluno.aluno_celular;
    cout<<aluno.aluno_apto_defesa;
}
};

class orientador
{   
    public:
    // INFO ORIENTADOR
    char orientador_nome[50]; // Preenchimento obrigatório
};

class avaliador
{
    public:
    // INFO AVALIADORES
    char avaliador_nome[50];         // Preenchimento obrigatório
    char avaliador_instituicao[100]; // Preenchimento obrigatório
    char aluno_email[100];           // Preenchimento obrigatório
    long int avaliador_tel_fixo;
    long int avaliador_celular;

    void adicionar_avaliador(avaliador avaliador)
{
    cout<<"Nome do avaliador: "<<endl;
    fgets(avaliador.avaliador_nome, 50, stdin);
    clearBuffer();
    cout<<"Instituicao: "<<endl;
    fgets(avaliador.avaliador_instituicao, 100, stdin);
    clearBuffer();
    cout<<"Email do aluno: "<<endl;
    fgets(avaliador.aluno_email, 100, stdin);
    clearBuffer();
    cout<<"Telefone fixo:"<<endl;
    cin>>avaliador.avaliador_tel_fixo;
    cout<<"Telefone Celular: "<<endl;
    cin>>avaliador.avaliador_celular;
}
};

class banca
{
    char banca_trab_titulo[50];  // Preenchimento obrigatório
    char banca_trab_resumo[500]; // Preenchimento obrigatório
    int data;                    // Preenchimento obrigatório
    int horario;                 // Preenchimento obrigatório
    char banca_local[50];        // Preenchimento obrigatório


};

class ficha // Struct base para a lista duplamente encadeada
{
    public:
    aluno ficha_aluno;
    orientador ficha_orientador;
    avaliador ficha_avaliador1;
    avaliador ficha_avaliador2;
    avaliador ficha_avaliador3;
    avaliador ficha_avaliador4;
    banca ficha_banca;
    struct ficha *prox;
    struct ficha *ant;
};

// Prototipos
int menu();
void adicionar_ficha();
aluno adicionar_aluno();     // feito! falta fazer verificaçoes de campos de preenchimento obrigatório
void adicionar_orientador(); // feito! falta fazer verificaçoes de campos de preenchimento obrigatório
void adicionar_avaliador();  // feito! falta fazer verificaçoes de campos de preenchimento obrigatório
void adicionar_banca();
void imprimir();
void alterar_aluno();
void alterar_orientador();
void alterar_avaliador();
void alterar_banca();
void excluir();
void clearBuffer();

// Programa Principal
int main(void)
{
    int opcao;

    do
    {
        opcao = menu();
        switch (opcao)
        {

        case 1:
            cout<<"\\n===Adicionar===\\n\\n"<<endl;
            adicionar_ficha();
            break;

        case 2:
            cout<<"\\n===Imprimir===\\n\\n"<<endl;
            imprimir();
            break;

        case 3:
            cout<<"\\n===Alterar aluno===\\n\\n"<<endl;
            alterar_aluno();
            break;

        case 4:
            cout<<"\\n===Alterar orientador===\\n\\n"<<endl;
            alterar_orientador();
            break;

        case 5:
            cout<<"\\n===Alterar avaliador===\\n\\n"<<endl;
            alterar_avaliador();
            break;

        case 6:
            cout<<"\\n===Alterar banca===\\n\\n"<<endl;
            alterar_banca();
            break;

        case 7:
            cout<<"\\n===Excluir===\\n\\n"<<endl;
            excluir();
            break;

        default:
            cout<<"por favor, inserir um numero valido!\\n"<<endl;
        }
    } while (opcao != 0);
    // system("pause");
    return 0;
}
// Menu de Opcoes
int menu(void)
{

    int opcao;
    do
    {

        cout<<"\\n\\n=== MENU PARA CADASTRO DE BANCAS ===\\n\\n"<<endl;
        cout<<"1. Adicionar\\n"<<endl;
        cout<<"2. Imprimir\\n"<<endl;
        cout<<"3. Alterar aluno\\n"<<endl;
        cout<<"4. Alterar orientador\\n"<<endl;
        cout<<"5. Alterar avaliador\\n"<<endl;
        cout<<"6. Alterar banca\\n"<<endl;
        cout<<"7. Excluir\\n"<<endl;
        cout<<"0. Sair\\n\\n"<<endl;
        cout<<"Digite sua opcao: "<<endl;
        cin>>opcao;

        if ((opcao < 0) || (opcao > 8))
            cout<<"por favor, inserir um numero valido!\\n"<<endl;

    } while ((opcao < 0) || (opcao > 8));

    return opcao;
}



void adicionar_orientador(orientador orientador)
{
    cout<<"Nome do orientador: "<<endl;
    fgets(orientador.orientador_nome, 50, stdin);
    clearBuffer();
}



void alterar_aluno(aluno){
    // Abre arquivo
    fstream cadastros;
    cadastros.open("cadastros.bin");
    if (cadastros.is_open()) { /* está tudo ok */ };

    aluno aluno;
    novo_aluno nvAlu;
    int opcao;
    cout<<"Qual informação sobre o aluno deseja alterar?"<<endl;
    cout<<"1 - Nome"<<endl;
    cout<<"2 - matricula"<<endl;
    cout<<"3 - curso"<<endl;
    cout<<"4 - email"<<endl;
    cout<<"5 - semestre"<<endl;
    cout<<"6 - telefone fixo"<<endl;
    cout<<"7 - celular"<<endl;
    cout<<"8 - frequência"<<endl;
    cout<<"9 - defesa"<<endl;
    cout<<"10 - nota"<<endl;
    cin>>opcao;
    switch (opcao)
    {
    case 1:
        cout<<"Altere o nome do aluno\n"<<endl;
        cin>>nvAlu.novo_nome;
        strcpy(aluno.aluno_nome, nvAlu.novo_nome); //Não consegui pensar numa forma de mudar o strcpy
        break;
    
    case 2:
        cout<<"Altere a Matricula do aluno\n"<<endl;
        cin>>nvAlu.nova_matricula;
        aluno.aluno_matricula = nvAlu.nova_matricula;
        break;
    case 3:
        cout<<"Altere o curso do aluno\n"<<endl;
        cin>>nvAlu.novo_curso;
        strcpy(aluno.aluno_curso, nvAlu.novo_curso);
        break;
    
    case 4:
        cout<<"Altere o email do aluno\n"<<endl;
        cin>>nvAlu.novo_email;
        strcpy(aluno.aluno_email, nvAlu.novo_email);
        break;
    
    case 5:
        cout<<"Altere o Semestre do aluno\n"<<endl;
        cin>>nvAlu.novo_semestre;
        aluno.aluno_semestre = nvAlu.novo_semestre;
        break;

    case 6:
        cout<<"Altere o Telefone fixo do aluno\n"<<endl;
        cin>>nvAlu.novo_tel_fixo;
        aluno.aluno_tel_fixo = nvAlu.novo_tel_fixo;
        break;
        /*função usando private
        cout<<"Altere o Telefone fixo do aluno\n"<<endl;
        setNov_tel_fix;
        aluno.aluno_tel_fixo = nvAlu.ntf;
        break;
        */
    case 7:
        cout<<"Qual o celular do aluno?"<<endl;
        cin>>nvAlu.novo_celular;
        aluno.aluno_celular = nvAlu.novo_celular;
        break;
        /*usando private
        cout<<"Qual o celular do aluno?"<<endl;
        setNovo_celular;
        aluno.aluno_celular = nvAlu.nc;
        break;
        */
    case 8:
        cout<<"Altere a Frequencia do aluno\n"<<endl;
        cin>>nvAlu.nova_freq;
        aluno.aluno_frequencia = nvAlu.nova_freq;
        break;
        /*
        cout<<"Altere a Frequencia do aluno\n"<<endl;
        setNova_freq;
        aluno.aluno_frequencia = nvAlu.nf;
        break;
        */
    case 9:
        cout<<"Altere a aptdao do aluno\n"<<endl;
        cin>>nvAlu.nova_defesa;
        aluno.aluno_apto_defesa = nvAlu.nova_defesa;
        break;
        /*
        cout<<"Altere a aptdao do aluno\n"<<endl;
        setNova_defesa;
        aluno.aluno_apto_defesa = nvAlu.nd;
        break;
        */
    case 10:
        cout<<"Altere a nota do aluno\n"<<endl; // Caso deva ser string deve ser modificado para usar strcpy
        cin>>nvAlu.nova_nota;
        aluno.aluno_nota = nvAlu.nova_nota;
        break;
        /*
        cout<<"Altere a nota do aluno\n"<<endl; // Caso deva ser string deve ser modificado para usar strcpy
        setNova_nota;
        aluno.aluno_nota = nvAlu.nn;
        break;
        */
    }
    
    
}

void clearBuffer()
{
    int ch;
    while ((ch = (getchar()) != '\n' && ch != EOF))
        ;
}
 