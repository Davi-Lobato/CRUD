#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "orientador.h"
#include "avaliador.h"
#include "banca.h"

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

ficha *inicio = NULL;
ficha *fim = NULL;

void adicionar_ficha(void); 
void salvaArquivoFicha(ficha ficha);