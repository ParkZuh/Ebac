#include <stdio.h> //biblioteca comunicativa com o usuario 'sem acento'
#include <stdlib.h> //biblioteca de locação de espaço de memorias
#include <locale.h> //biblioteca de alocação por região
#include <string.h> // biblioteca responsavel por strings

int registrar() // função responsalvel pelo registro
{   // inicio de criação de váriaveis strings
	char arquivo [40];
    char cpf [40];
	char nome[40];
	char sobrenome[40];	
	char cargo[40];
	// final de criação de váriaveis strings
	
	printf("Digite o CPF a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s", cpf); // %s é responsavel por salvar uma string
	
	strcpy(arquivo, cpf); // responsavel por copias valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // apbre o arquivo e cria o "w" siginificando que vai escrever
	fprintf(file,cpf); // salvor o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,","); // responsavel por separar os dados
	fclose(file); // fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s",nome); // %s é responsavel por salvar uma string
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,nome); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
    file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,","); // responsavel por separar os dados
	fclose(file); // fechar o arquivo
	
    printf("Digite o sobrenome a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s",sobrenome); // %s é responsavel por salvar uma string
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,sobrenome); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
    file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,","); // responsavel por separar os dados
	fclose(file); // fechar o arquivo
	
    printf("Digite o cargo a ser cadastrado: "); // responsavel por coletar dados do usuario
	scanf("%s",cargo); // %s é responsavel por salvar uma string
	
	file = fopen(arquivo, "a"); // abrir o arquivo
	fprintf(file,cargo); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	system("pause"); // responsavel por parar a função e voltar ao inicio
}

int consultar() // função responsalvel pela consulta
{
	setlocale(LC_ALL, "Portuguese"); // responsavel definir a linguagem
	
	//inicio da criação das variaveis strings
    char cpf[40];
    char conteudo[200];
    //final da criação das variaveis strings
    
    printf("Digite o CPF a ser consultado: "); // responsavel por consultar os dados do usuario
    scanf("%s", cpf); // %s é responsavel por encontrar uma string
    
    FILE *file; // cria arquivo ja existido
    file = fopen(cpf,"r"); // abrir o arquivo e criar "r" significa ler a strings
    
    if(file == NULL) // responsavel por definir arquivos ou dados não encontrado
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!\n"); // responsavel por consultar os dados do usuario que não existe
	}
    
    while(fgets(conteudo, 200, file) != NULL) // responsavel por mostrar os dados do usuario
    {
    	printf("\nEssas são as informações do usuário: "); // responsavel por mostrar os dados do usuario
    	printf("%s", conteudo); // respnsavel por carregar strings
    	printf("\n\n"); // responsavel por dar espaço
	}
	
	system("pause"); // responsavel por parar a função e voltar ao inicio
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
	    
	if(file != NULL) // responsavel por achar dados ou string não existentes
	{	   
       printf("O usuário foi deletado do sistema!\n\n");
    }
	else // responsavel pelo "se" não houver SO DELETA QUANDO FECHA O PROGRAMA
	{
	   printf("O usuário não existe!\n\n");
	}
	system("pause"); // responsavel para parar a função e voltar ao inicio
    
}


int main()
{
	int opcao=0; // definindo as variaveis
	int x=1 ; // chamando a definição de loop
	
	for(x=1;x=1;) // loopando
	{
		system ("cls"); // limpar a tela
		
	    setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); // inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n"); 
        printf("Opção: "); // fim do menu
     
        scanf ("%d", &opcao); // armazenando a escolha do usuario
     
        system ("cls"); // apagar telas
        
        switch(opcao) // inicio da seleção de menu
        {
        	case 1:
            registrar(); //chamada de uma função
         	break;
         	
         	case 2:
            consultar(); //chamada de uma função
         	break;
         	
         	case 3:
            deletar(); //chamada de uma função
         	break;
         	
         	default:
         	printf("Essa opção não está disponivel!\n");
         	system("pause");
         	break;
		}  // fim da seleção
	 
	 }
}
