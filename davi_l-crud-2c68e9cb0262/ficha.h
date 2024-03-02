#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "orientador.h"
#include "avaliador.h"
#include "banca.h"

typedef struct ficha // Struct base para a lista duplamente encadeada
{
    Aluno ficha_aluno;
    Orientador ficha_orientador;
    Avaliador ficha_avaliador1;
    Avaliador ficha_avaliador2;
    Avaliador ficha_avaliador3;
    Avaliador ficha_avaliador4;
    Banca ficha_banca;
    struct ficha *prox;
    struct ficha *ant;
} Ficha;

Ficha *inicio = NULL;
Ficha *fim = NULL;

void adicionar_ficha(void);
void salvaArquivoFicha(Ficha ficha);