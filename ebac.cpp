#include <stdio.h> //biblioteca comunicativa com o usuario 'sem acento'
#include <stdlib.h> //biblioteca de loca��o de espa�o de memorias
#include <locale.h> //biblioteca de aloca��o por regi�o
#include <string.h> // biblioteca responsavel por strings

int registrar() // fun��o responsalvel pelo registro
{   // inicio de cria��o de v�riaveis strings
	char arquivo [40];
    char cpf [40];
	char nome[40];
	char sobrenome[40];	
	char cargo[40];
	// final de cria��o de v�riaveis strings
	
	printf("Digite o CPF a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s", cpf); // %s � responsavel por salvar uma string
	
	strcpy(arquivo, cpf); // responsavel por copias valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // apbre o arquivo e cria o "w" siginificando que vai escrever
	fprintf(file,cpf); // salvor o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,","); // responsavel por separar os dados
	fclose(file); // fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s",nome); // %s � responsavel por salvar uma string
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,nome); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
    file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,","); // responsavel por separar os dados
	fclose(file); // fechar o arquivo
	
    printf("Digite o sobrenome a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s",sobrenome); // %s � responsavel por salvar uma string
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,sobrenome); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
    file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,","); // responsavel por separar os dados
	fclose(file); // fechar o arquivo
	
    printf("Digite o cargo a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s",cargo); // %s � responsavel por salvar uma string
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,cargo); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	system("pause"); // responsavel por parar a fun��o e voltar ao inicio
}

int consultar() // fun��o responsalvel pela consulta
{
	setlocale(LC_ALL, "Portuguese"); // responsavel definir a linguagem
	
	//inicio da cria��o das variaveis strings
    char cpf[40];
    char conteudo[200];
    //final da cria��o das variaveis strings
    
    printf("Digite o CPF a ser consultado: "); // responsavel por consultar os dados do usuario
    scanf("%s", cpf); // %s � responsavel por encontrar uma string
    
    FILE *file; // cria arquivo ja existido
    file = fopen(cpf,"r"); // abrir o arquivo e criar "r" significa ler a strings
    
    if(file == NULL) // responsavel por definir arquivos ou dados n�o encontrado
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); // responsavel por consultar os dados do usuario que n�o existe
	}
    
    while(fgets(conteudo, 200, file) != NULL) // responsavel por mostrar os dados do usuario
    {
    	printf("\nEssas s�o as informa��es do usu�rio: "); // responsavel por mostrar os dados do usuario
    	printf("%s", conteudo); // respnsavel por carregar strings
    	printf("\n\n"); // responsavel por dar espa�o
	}
	
	system("pause"); // responsavel por parar a fun��o e voltar ao inicio
}

int deletar() // responsavel por deletar as variaveis strings
{
     // criado uma variavel string
	char cpf [40];
	
	printf("Digite o CPF a ser deletado: "); // responsavel por procurar dados do usuario
	scanf("%s", cpf); // responsavel por carregar dados do usuario
	
	remove(cpf); // remove o arquivo

	FILE *file; // criar arquivo ou encontra arquivo ja criado
	file = fopen(cpf, "r"); // abrir o arquivo e criar o "r" para ler a string
	    
	if(file != NULL) // responsavel por achar dados ou string n�o existentes
	{	   
       printf("O usu�rio foi deletado do sistema!\n\n");
    }
	else // responsavel pelo "se" n�o houver SO DELETA QUANDO FECHA O PROGRAMA
	{
	   printf("O usu�rio n�o existe!\n\n");
	}
	system("pause"); // responsavel para parar a fun��o e voltar ao inicio
    
}


int main()
{
	int opcao=0; // definindo as variaveis
	int x=1 ; // chamando a defini��o de loop
	
	for(x=1;x=1;) // loopando
	{
		system ("cls"); // limpar a tela
		
	    setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n"); 
        printf("Op��o: "); // fim do menu
     
        scanf ("%d", &opcao); // armazenando a escolha do usuario
     
        system ("cls"); // apagar telas
        
        switch(opcao) // inicio da sele��o de menu
        {
        	case 1:
            registrar(); //chamada de uma fun��o
         	break;
         	
         	case 2:
            consultar(); //chamada de uma fun��o
         	break;
         	
         	case 3:
            deletar(); //chamada de uma fun��o
         	break;
         	
         	default:
         	printf("Essa op��o n�o est� disponivel!\n");
         	system("pause");
         	break;
		}  // fim da sele��o
	 
	 }
}
