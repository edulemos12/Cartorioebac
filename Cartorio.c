#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include<locale.h> // biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{	
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletendo irformações do usuario
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
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
	setlocale(LC_ALL, "Portuguese"); //Selecionar região da biblioteca "locale.h" 
	//inicio da criação de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/strings
	
	printf("Qual o CPF a ser consultado: "); //coletando informações do cliente
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar()
{	
	//inicio da criação de variáveis/strings
	char cpf[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser deletado: "); //coletando informações do usuario
	scanf("%s", cpf);
	

	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file != NULL) //confirmação de cancelamento ou erro
	{	
		
		printf("Usuário deletado com sucesso\n\n");
		remove(cpf);
	}
	
	else
	{
		printf("Usuário não encontrado\n\n");
		
	}
	
	system("pause");
	
}


int main()
{
	int opcao=0; //definindo variaveis 
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		
		setlocale(LC_ALL, "Portuguese"); //Selecionar região da biblioteca "locale.h" 
	
		printf("### Cartório da EBAC ### \n\n"); //Inicio do Menu
		printf("Escolha a opção desejada de menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //FIm do Menu
	
		scanf("%d", &opcao); //Armazenado escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
	
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções 
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			default:
			printf("Essa opção nao esta disponivel\n");
			system("pause");
			break;			
		}			// Fim da seleção de menu
		
			system("cls");
			
	}
}
