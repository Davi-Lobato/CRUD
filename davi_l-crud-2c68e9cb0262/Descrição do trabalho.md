SOBRE A ATIVIDADE PROPOSTA:
====================================================================================
Todo semestre, na UFC de Russas, há um período de cadastramento de bancas de
TCC seguido por um período de divulgação (sim, as bancas de TCC são um evento
público!). O cadastramento de bancas realizado pelos cursos de Ciência da Computação
(CC) e Engenharia de Software (ES) seguem o ANEXO II encontrado no manual de TCC (o
de CC está no link: http://shorturl.at/mFSX3 , o de ES é igual).

**MISSÃO:** criar um sistema, escrito em C, que realize um CRUD
(Create, Read, Update, Delete) das bancas de TCC.
O sistema deverá, conforme anexo II:

- Cadastrar: armazenar em arquivo as informações de aluno, orientador,
bancas, título e resumo, horário e local das bancas de TCC.

- Exibir: exibir, em um formato amigável, todas as bancas cadastradas até
então a partir de leitura de arquivo (serve para divulgação).

- Atualizar: o sistema deverá, dado um código, atualizar as informações em
arquivo de aluno, orientador, frequência, avaliadores, horários, título e
resumo, quando solicitados.

- Apagar: o sistema deverá apagar uma banca quando for necessário.

**OBSERVAÇÕES:** Nem todos os campos são obrigatórios no preenchimento de cadastro e
podem ser pulados. Seguem os preenchimentos obrigatórios:

- Alunos: Nome, Matrícula, Curso e E-mail.

- Orientador: Nome

- Frequência: Porcentagem

- Avaliadores: Nome, Instituição, E-mail

- Dados da Banca: Título, Resumo, Horário e Local

__________________________________________________________________________________
Bônus: (+1 no trabalho)
Utilizar uma biblioteca gráfica como a ncurses (por exemplo), dará um ponto a mais
pelo uso.