#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ficha.h"

typedef struct data
{

    int ano;
    short mes;
    short dia;
} Data;

int tam = 0;

void imprimir();
void alterar_aluno();
void alterar_orientador();
void alterar_avaliador();
void alterar_banca();
void excluir();
void clearBuffer();

int main(void)
{   
    int opcao;

    do
    {
        opcao = menu();
        switch (opcao)
        {

        case 1:
            printf("\n===Adicionar===\n\n");
            adicionar_ficha();
            break;

        case 2:
            printf("\n===Imprimir===\n\n");
            int indx = buscarFichaAluno();
+           mostraFicha(indx);
            imprimir();
            break;

        case 3:
            printf("\\n===Alterar aluno===\\n\\n");
            alterar_aluno();

            
            int indx = buscarFichaAluno(); 
            mostraFicha(indx);            
            break;

        case 4:
            printf("\n===Alterar aluno===\n\n");
            alterar_aluno();

            break;

        case 5:
            printf("\n===Alterar orientador===\n\n");
            alterar_orientador();
            break;

        case 6:
            printf("\n===Alterar avaliador===\n\n");
            alterar_avaliador();
            break;
        
        case 7:
            printf("\n===Alterar banca===\n\n");
            alterar_banca();
            break;

        case 8:
            printf("\n===Excluir===\n\n");
            excluir();

            break;


            break;


        default:
            printf("por favor, inserir um numero valido!\\n");
        }
    } while (opcao != 0);
    system("pause");
    return 0;
}

int menu(void)
{
    int opcao;
    do
    {

        printf("\n\n=== MENU PARA CADASTRO DE BANCAS ===\n\n");
        printf("1. Adicionar\n");
        printf("2. Imprimir\n");
        printf("3. Alterar aluno\n");
        printf("4. Alterar orientador\n");
        printf("5. Alterar avaliador\n");
        printf("6. Alterar banca\n");
        printf("7. Excluir\n");
        printf("0. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if ((opcao < 0) || (opcao > 8))
            printf("por favor, inserir um numero valido!\\n");

    } while ((opcao < 0) || (opcao > 8));

    return opcao;
}

void adicionar_ficha()
{
    FILE *cadastros = fopen("cadastros.bin", "wb");
    if (cadastros == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return;
    }
    Ficha * ficha = malloc(sizeof(Ficha));
    ficha->ficha_aluno = adicionar_aluno(ficha->ficha_aluno);
    ficha->ficha_orientador = adicionar_orientador(ficha->ficha_orientador);
    ficha->ficha_avaliador1 = adicionar_avaliador(ficha->ficha_avaliador1);
    ficha->ficha_avaliador2 = adicionar_avaliador(ficha->ficha_avaliador2);
    ficha->ficha_avaliador3 = adicionar_avaliador(ficha->ficha_avaliador3);
    ficha->ficha_avaliador4 = adicionar_avaliador(ficha->ficha_avaliador4);
    ficha->ficha_banca = adicionar_banca(ficha->ficha_banca); 
    if (fwrite(ficha, sizeof(Ficha), 1, cadastros) != 1)
    {
        printf("Erro ao gravar conteudo no arquivo!");
        fclose(cadastros);
    }
    fclose(cadastros);
    printf("Arquivo gravado com sucesso!");

}

int buscarFichaAluno()
{
    Ficha *aux = inicio;
    int matricula;

    printf("Digite a matricula do aluno que esta buscando: \n");
    scanf("%d", &matricula);

    for (int i = 0; i < tam; i++)
    {
        if (matricula == aux->ficha_aluno.aluno_matricula)
        {
            return i; // indice do valor buscado. Retornado para usar em outras operações
        }
        else
        {
            aux = aux->prox;
        }
    }
}

void mostraFicha(int indx)
{
    Ficha *aux = inicio;
    for (int i = 0; i < tam; i++)
    {
        if (i == indx)
        {
            printf("Nome do aluno: %s\n", ficha->ficha_aluno.aluno_nome);
            printf("Curso: %s\n", ficha->ficha_aluno.aluno_curso);
            printf("Email: %s\n", ficha->ficha_aluno.aluno_email);
            printf("Matricula: %d\n", ficha->ficha_aluno.aluno_matricula);
            printf("Semestre: %hd\n", ficha->ficha_aluno.aluno_semestre);
            printf("Telefone fixo: %ld\n", ficha->ficha_aluno.aluno_tel_fixo);
            printf("Telefone Celular: %ld\n", ficha->ficha_aluno.aluno_celular);
            printf("Frequencia do aluno: %hd\n", ficha->ficha_aluno.aluno_frequencia);
            printf("Apto a defesa(1 = sim 0 = nao): %hd\n", ficha->ficha_aluno.aluno_apto_defesa);
            printf("Justificativa de nao aptdao: %hd\n\n", ficha->ficha_aluno.aluno_nota);
            printf("Nome do orientador: %s\n\n", ficha->ficha_orientador.orientador_nome);
            printf("Nome do avaliador: %s\n", ficha->ficha_avaliador1.avaliador_nome);
            printf("Instituicao: %s\n", ficha->ficha_avaliador1.avaliador_instituicao);
            printf("Email do avaliador: %s\n", ficha->ficha_avaliador1.avaliador_email);
            printf("Telefone fixo:%ld\n", ficha->ficha_avaliador1.avaliador_tel_fixo);
            printf("Telefone Celular: %ld\n", ficha->ficha_avaliador1.avaliador_celular);
            break;
        }
        else
        {
            aux = aux->prox;
        }
    }
}

Aluno adicionar_aluno(Aluno aluno) 
{
    clearBuffer();
    printf("Nome do aluno: ");
    fgets(aluno.aluno_nome, 50, stdin);
    printf("Curso: ");
    fgets(aluno.aluno_curso, 50, stdin);
    printf("Email: ");
    fgets(aluno.aluno_email, 100, stdin);
    printf("Matricula: ");
    scanf("%d", &aluno.aluno_matricula);
    printf("Semestre: ");
    scanf("%hd", &aluno.aluno_semestre);
    printf("Telefone fixo: ");
    scanf("%ld", &aluno.aluno_tel_fixo);
    printf("Telefone Celular: ");
    scanf("%ld", &aluno.aluno_celular);
    printf("Frequencia do aluno: ");
    scanf("%hd", &aluno.aluno_frequencia);
    printf("Apto a defesa(1 = sim 0 = nao): ");
    scanf("%hd", &aluno.aluno_apto_defesa);
    printf("Justificativa de nao aptdao: ");
    scanf("%hd", &aluno.aluno_nota); 

    return aluno;
}

void alterarFichaAluno()
{
    Ficha *aux = inicio;

    int indxAlterar = buscarFichaAluno();

    for (int i = 0; i < tam; i++)
    {
        if (i == indxAlterar)
        {
            aux->ficha_aluno = adicionar_aluno(aux->ficha_aluno);
        }
        else
        {
            aux = aux->prox;
        }
    }
}

Orientador adicionar_orientador(Orientador orientador)
{
    clearBuffer();
    printf("Nome do orientador: ");
    fgets(orientador.orientador_nome, 50, stdin);
    return orientador;
}

int buscarFichaOrientador()
{
    Ficha *aux = inicio;
    char nome[50];

    clearBuffer();
    printf("Nome do orientador: ");
    fgets(nome, 50, stdin);

    for (int i = 0; i < tam; i++)
    {
        if (nome == aux->ficha_orientador.orientador_nome)
        {
            return i; // indice do valor buscado. Retornado para usar em outras operações
        }
        else
        {
            aux = aux->prox;
        }
    }
}

void alteraFichaOrientador()
{
    Ficha *aux = inicio;

    int indxAlterar = buscarFichaOrientador();

    for (int i = 0; i < tam; i++)
    {
        if (i == indxAlterar)
        {
            aux->ficha_orientador = adicionar_orientador(aux->ficha_orientador);
        }
        else
        {
            aux = aux->prox;
        }
    }
}

Avaliador adicionar_avaliador(Avaliador avaliador)
{
    printf("Nome do avaliador: ");
    fgets(avaliador.avaliador_nome, 50, stdin);
    printf("Instituicao: ");
    fgets(avaliador.avaliador_instituicao, 100, stdin);
    printf("Email do avaliador: ");
    fgets(avaliador.avaliador_email, 100, stdin);
    printf("Telefone fixo:");
    scanf("%ld", &avaliador.avaliador_tel_fixo);
    printf("Telefone Celular: ");
    scanf("%ld", &avaliador.avaliador_celular);
    clearBuffer();
    return avaliador;
}

int buscarFichaAvaliador()
{
    Ficha *aux = inicio;
    char nome[50];

    clearBuffer();
    printf("Nome do avaliador: "); // busca por nome
    fgets(nome, 50, stdin);

    for (int i = 0; i < tam; i++)
    {
        if (nome == aux->ficha_avaliador1.avaliador_nome)
        {
            return i; // indice do valor buscado. Retornado para usar em outras operações
        }
        else
        {
            aux = aux->prox;
        }
    }
}

void alteraFichaAvaliador() 
{
    Ficha *aux = inicio;

    int indxAlterar = buscarFichaAvaliador();

    for (int i = 0; i < tam; i++)
    {
            if (i == indxAlterar)
        {
            aux->ficha_avaliador1 = adicionar_avaliador(aux->ficha_avaliador1);
        }
        else
        {
            aux = aux->prox;
        }
    }
}

Banca adicionar_banca(Banca banca)
{
    printf("Titulo do Trabalho: ");
    fgets(banca.banca_trab_titulo, 50, stdin);
    printf("Resumo do Trabalho: ");
    fgets(banca.banca_trab_resumo, 500, stdin);
    printf("Data da Apresentacao: ");
    fgets(banca.banca_data, 9, stdin);
    printf("Hora do Apresentacao: ");
    fgets(banca.banca_horario, 5, stdin);
    printf("Local: ");
    fgets(banca.banca_local, 50, stdin);
    return banca;
}

void clearBuffer()
{
    int ch;
    while ((ch = (getchar()) != '\n' && ch != EOF));
}


void imprimir()
{
    FILE *cadastros = fopen("cadastros.bin", "rb");
    if (cadastros == NULL)
    {
        printf("Erro na abertura do arquivo.");
        return;
    }
    Ficha ficha;
    int matricula, matr_encontrada = 0;
    printf ("\nDigite o codigo que procura: \n");
    scanf ("%d", &matricula);
    while (fread(&ficha, sizeof(Ficha), 1, cadastros))
    {
        if (matricula == ficha.ficha_aluno.aluno_matricula)
        {
            printf("Nome do aluno: %s\n", ficha.ficha_aluno.aluno_nome);
            printf("Curso: %s\n", ficha.ficha_aluno.aluno_curso);
            printf("Email: %s\n", ficha.ficha_aluno.aluno_email);
            printf("Matricula: %d\n", ficha.ficha_aluno.aluno_matricula);
            printf("Semestre: %hd\n", ficha.ficha_aluno.aluno_semestre);
            printf("Telefone fixo: %ld\n", ficha.ficha_aluno.aluno_tel_fixo);
            printf("Telefone Celular: %ld\n", ficha.ficha_aluno.aluno_celular);
            printf("Frequencia do aluno: %hd\n", ficha.ficha_aluno.aluno_frequencia);
            printf("Apto a defesa(1 = sim 0 = nao): %hd\n", ficha.ficha_aluno.aluno_apto_defesa);
            printf("Justificativa de nao aptdao: %hd\n\n", ficha.ficha_aluno.aluno_nota);
            printf("Nome do orientador: %s\n\n", ficha.ficha_orientador.orientador_nome);
            printf("Nome do avaliador: %s\n", ficha.ficha_avaliador1.avaliador_nome);
            printf("Instituicao: %s\n", ficha.ficha_avaliador1.avaliador_instituicao);
            printf("Email do avaliador: %s\n", ficha.ficha_avaliador1.avaliador_email);
            printf("Telefone fixo:%ld\n", ficha.ficha_avaliador1.avaliador_tel_fixo);
            printf("Telefone Celular: %ld\n", ficha.ficha_avaliador1.avaliador_celular);
            printf("Nome do avaliador: %s\n", ficha.ficha_avaliador2.avaliador_nome);
            printf("Instituicao: %s\n", ficha.ficha_avaliador2.avaliador_instituicao);
            printf("Email do avaliador: %s\n", ficha.ficha_avaliador2.avaliador_email);
            printf("Telefone fixo:%ld\n", ficha.ficha_avaliador2.avaliador_tel_fixo);
            printf("Telefone Celular: %ld\n", ficha.ficha_avaliador2.avaliador_celular);
            printf("Nome do avaliador: %s\n", ficha.ficha_avaliador3.avaliador_nome);
            printf("Instituicao: %s\n", ficha.ficha_avaliador3.avaliador_instituicao);
            printf("Email do avaliador: %s\n", ficha.ficha_avaliador3.avaliador_email);
            printf("Telefone fixo:%ld\n", ficha.ficha_avaliador3.avaliador_tel_fixo);
            printf("Telefone Celular: %ld\n", ficha.ficha_avaliador3.avaliador_celular);
            printf("Nome do avaliador: %s\n", ficha.ficha_avaliador4.avaliador_nome);
            printf("Instituicao: %s\n", ficha.ficha_avaliador4.avaliador_instituicao);
            printf("Email do avaliador: %s\n", ficha.ficha_avaliador4.avaliador_email);
            printf("Telefone fixo:%ld\n", ficha.ficha_avaliador4.avaliador_tel_fixo);
            printf("Telefone Celular: %ld\n\n", ficha.ficha_avaliador4.avaliador_celular);
            printf("Titulo do Trabalho: %s\n", ficha.ficha_banca.banca_trab_titulo);
            printf("Resumo do Trabalho: %s\n", ficha.ficha_banca.banca_trab_resumo);
            printf("Data da Apresentacao: %s\n", ficha.ficha_banca.banca_data);
            printf("Hora do Apresentacao: %s\n", ficha.ficha_banca.banca_horario);
            printf("Local: %s\n", ficha.ficha_banca.banca_local);
            matr_encontrada = 1;
        }
    }
    if (!matr_encontrada)
    {
        printf("matricula nao cadastrada");
    }
    fclose(cadastros);    
}

