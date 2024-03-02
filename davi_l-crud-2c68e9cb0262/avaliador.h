#include <stdio.h>
#include <stdlib.h>

class avaliador
{
    public:
    // INFO AVALIADORES
    char avaliador_nome[50];         // Preenchimento obrigatório
    char avaliador_instituicao[100]; // Preenchimento obrigatório
    char aluno_email[100];           // Preenchimento obrigatório
    long int avaliador_tel_fixo;
    long int avaliador_celular;
};

class novo_avaliador
{
    public:
    char novo_avaliador_nome[50];
    char novo_avaliador_institucao[100];
    char novo_aluno_email[100];
    long int novo_telFix_avaliador;
    long int novo_avaliador_celular;
};