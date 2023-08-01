#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include<locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletendo irforma��es do usuario
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Qual o nome a ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Qual o sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Qual o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{	
	setlocale(LC_ALL, "Portuguese"); //Selecionar regi�o da biblioteca "locale.h" 
	//inicio da cria��o de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/strings
	
	printf("Qual o CPF a ser consultado: "); //coletando informa��es do cliente
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar()
{	
	//inicio da cria��o de vari�veis/strings
	char cpf[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser deletado: "); //coletando informa��es do usuario
	scanf("%s", cpf);
	

	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file != NULL) //confirma��o de cancelamento ou erro
	{	
		
		printf("Usu�rio deletado com sucesso\n\n");
		remove(cpf);
	}
	
	else
	{
		printf("Usu�rio n�o encontrado\n\n");
		
	}
	
	system("pause");
	
}


int main()
{
	int opcao=0; //definindo variaveis 
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		
		setlocale(LC_ALL, "Portuguese"); //Selecionar regi�o da biblioteca "locale.h" 
	
		printf("### Cart�rio da EBAC ### \n\n"); //Inicio do Menu
		printf("Escolha a op��o desejada de menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //FIm do Menu
	
		scanf("%d", &opcao); //Armazenado escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
	
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es 
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			default:
			printf("Essa op��o nao esta disponivel\n");
			system("pause");
			break;			
		}			// Fim da sele��o de menu
		
			system("cls");
			
	}
}
