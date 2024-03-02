#include <iostream>
class aluno
{   
    public:
    // INFO DO ALUNO CONCLUENTE
    char aluno_nome[50];   
    int aluno_matricula;   
    char aluno_curso[50];  
    char aluno_email[100]; 
    short int aluno_semestre;
    long int aluno_tel_fixo;
    long int aluno_celular;
    short int aluno_frequencia;
    short int aluno_apto_defesa; 
    short int aluno_nota;
};

    void adicionar_aluno(aluno);

class novo_aluno
{   public:
    char novo_nome[50];
    int nova_matricula;
    char novo_curso[50];
    char novo_email[100];
    short int novo_semestre;
    long int novo_tel_fixo;
    long int novo_celular;
    short int nova_freq;
    short int nova_defesa;
    short int nova_nota;
};
//prototipo usando private
/*
class aluno
{   
    public:
    // INFO DO ALUNO CONCLUENTE
    char aluno_nome[50];   
    int aluno_matricula;   
    char aluno_curso[50];  
    char aluno_email[100]; 
    short int aluno_semestre;
    private:
    long int aluno_tel_fixo;
    long int aluno_celular;
    short int aluno_frequencia;
    short int aluno_apto_defesa; 
    short int aluno_nota;       
};

    void adicionar_aluno(aluno);

class novo_aluno
{   private:
    long int novo_tel_fixo;
    long int novo_celular;
    short int nova_freq;
    short int nova_defesa;
    short int nova_nota;
    public:
    char novo_nome[50];
    int nova_matricula;
    char novo_curso[50];
    char novo_email[100];
    short int novo_semestre;
    //setter
    long int setNov_tel_fix(long int ntf){
        cin>>ntf;
        novo_tel_fixo = ntf;
    }
    long int setNovo_celular(long int nc){
        cin>>nc;
        novo_celular = nc
    }
    short int setNova_freq(short int nf){
        cin>>nf;
        nova_freq = nf
    }
    short int setNova_defesa(short int nd){
        cin>>nd;
        nova_defesa = nd;
    }
    short int setNova_nota(short int nn){
        cin>>nn;
        nova_nota = nn;
    }
    //getter
    long int getNovo_tel(){
        return novo_tel_fixo;
    }
    long int getNovo_cel(){
        return novo_celular;
    }
    
    short int getNova_freq(){
        return nova_freq;
    }
    short int getNova_def(){
        return nova_defesa;
    }
    short int getNova_nota(){
        return nova_nota;
    }
};*/