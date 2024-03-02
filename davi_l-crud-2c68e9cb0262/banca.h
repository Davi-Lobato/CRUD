#include <stdio.h>
#include <stdlib.h>

class banca
{
    public:
    char banca_trab_titulo[50];  // Preenchimento obrigatório
    char banca_trab_resumo[500]; // Preenchimento obrigatório
    char banca_data[9];          // Preenchimento obrigatório
    char banca_horario[5];       // Preenchimento obrigatório
    char banca_local[50];        // Preenchimento obrigatório
} ;

void adicionar_banca(banca );