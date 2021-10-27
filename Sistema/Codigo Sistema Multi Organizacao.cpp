//============================================================================================================================================================================
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Aceitar palavras no padr�o portugu�s-brasileiro com acentos
#include <string.h>
//============================================================================================================================================================================
//Estruturas de dados
typedef struct{
	char usuario[50];
	char senha[50];
}login; //  struct ser� usada para fazer login no sistema

typedef struct{
	char titulo[50];
	char autor[50];
	char editora[20];
}cad_livro; // struct usada para cadastro de livros

typedef struct{
	int dia;
	int mes;
	int ano;
}DATA; // Struct para datas

typedef struct{
	char nome[100];
	char cpf[12];
	char cargo[20];
	DATA data;
}cad_biblioteca; // Struct para cadastro de biblioc�rio/monitor

typedef struct{
	char titulo[50];
	char autor[50];
	char editora[20];
	char nome[100];
	char fone[15];
}livros_emprestados; //Struct para monitorar livros emprestados
//============================================================================================================================================================================

int main(){
//============================================================================================================================================================================
//Vari�veis; Declara��o de fun��es
	int opcao; char buffer; FILE *sen; login pr, log, teste;
	int testlog, testsen; char tentenov;

	setlocale(LC_ALL, "Portuguese"); //Aceitar palavras no padr�o portugu�s-brasileiro com acentos

	void cabecalho();
	int comparasen(char log[], char key[]);
//============================================================================================================================================================================	
//Login no sistema
sen = fopen("arqsenha", "rb");
	if(sen == NULL){ //Testar se o usu�rio ja tem um login no sistema, 
					 //de maneira b�sica vou usar arquivos, se o arquivo "sen" estiver na m�quina, significa q ja existe um login.
		sen = fopen("arqsenha", "w+b"); // caso seja NULL ir� ser feito a cri��o de um login
		cabecalho();
		printf("Bem-vindo ao Multi-Organiza��o\nEsse � seu primeiro acesso, se cadastre:");
		printf("\nDigite um usu�rio para login: ");
		scanf("%[^\n]s", pr.usuario);
		scanf("%c", &buffer);
		printf("Digite uma senha para login: ");
		scanf("%[^\n]s", pr.senha);
		scanf("%c", &buffer);
		
		fwrite(&pr, sizeof(login), 1, sen); // gravar senha no arquivo
		if(ferror(sen)){ // testar se ouve erro
			printf("\nErro na Grava��o\n");
		}
		else{
			printf("\nCadastro feito com sucesso\n");
		}
		
		system("pause");
		fclose(sen); system("cls");
		
		sen = fopen("arqsenha", "rb"); 
		if(sen == NULL){
			printf("Erro no sistema\n");
			system("pause"); return 0;
		}
		else{ //Ap�s a cria��o do login, ser� pedido que o usu�rio fa�a o login
			
			while(!feof(sen)){
			fread(&pr, sizeof(login), 1, sen);
			}
			
			if(ferror(sen)){
				printf("\nErro no Sistema.\n");	
			}
		    
		    do{
			cabecalho();
			printf("Fa�a seu login para ter acesso ao Multi-Organiza��o:");
			printf("\nDigite seu usuario: ");
			scanf("%[^\n]s", log.usuario);
			scanf("%c", &buffer);
			printf("Digite sua senha: ");
			scanf("%[^\n]s", log.senha);
			scanf("%c", &buffer);
			system("cls");
			
			testlog = comparasen(pr.usuario, log.usuario);
			testsen = comparasen(pr.senha, log.senha);
			
			if(testlog == 0 ||  testsen == 0){ // testar se senhas est�o corretas atraves da fun��o comparasen
				cabecalho();
				printf("Senha incorreta!\nClique qualquer letra para Tentar novamente \nOu clique 0 para sair.\n");
				scanf("%c", &tentenov);
				scanf("%c", &buffer);
				
				if(tentenov == '0'){
					system("pause");
					return 0;
				}
			}
			fclose(sen);
			system("cls");
		    }while(testlog == 0 ||  testsen == 0);
	
		}
	}
	else{
		
		sen = fopen("arqsenha", "rb");
		if(sen == NULL){
			printf("Erro no sistema\n");
			system("pause"); return 0;
		}
		
		else{
		
			while(!feof(sen)){
				fread(&pr, sizeof(login), 1, sen);
			}
				if(ferror(sen)){
				printf("\nErro no Sistema.\n");	
			}
			
		    
		    do{
			
			cabecalho();
			printf("Fa�a seu login para ter acesso ao Multi-Organiza��o:");
			printf("\nDigite seu usuario: ");
			scanf("%[^\n]s", log.usuario);
			scanf("%c", &buffer);
			printf("Digite sua senha: ");
			scanf("%[^\n]s", log.senha);
			scanf("%c", &buffer);
		    system("cls");
			
			testlog = comparasen(pr.usuario, log.usuario);
			testsen = comparasen(pr.senha, log.senha);
			
			
			if(testlog == 0 ||  testsen == 0){
				printf("Senha incorreta!\nClique qualquer letra para Tentar novamente \nOu clique 0 para sair.\n");
				scanf("%c", &tentenov);
				scanf("%c", &buffer);
				
				if(tentenov == '0'){
					system("pause");
					return 0;
				}
			
			}
			system("cls");
			fclose(sen);
		    }while(testlog == 0 ||  testsen == 0);
		}
	}
//============================================================================================================================================================================
//Layout Principal

	do{
		cabecalho();
        printf("\nSeja Bem-Vindo ao Multi-Organiza��o!");
        printf("\nO que deseja fazer?");
        printf("\n[1]-Cadastro de Livros");
        printf("\n[2]-Cadrastro de Bibliotec�rios ou Volunt�rios");
        printf("\n[3]-Bibliotec�rios e Volunt�rios da Biblioteca");
        printf("\n[4]-Lista de Livros");
        printf("\n[5]-Lista de Livros Emprestados");
        printf("\n[6]-Buscar Livro");
        printf("\n[7]-Outras Ferramentas");
        printf("\n[0]-Sair do Sistema Multi-Organiza��o");
        printf("\nDigite sua op��o: ");
		scanf("%d", &opcao); system("cls");
	
	}while(opcao != 0);
	
	system("pause");
	return 0;
}

//============================================================================================================================================================================
//fun��o cabe�alho
void cabecalho(){
	system("cls");
	printf("  _ _ _        _ _ _     __         __    __     _ _ _ _ _ _ _ _ __    __  \n");
	printf("|   _  \\      /  _   |  |  |       |  |  |  |   |_ _ _ _    _ _ _ _|  |  | \n");
	printf("|  | \\  \\    /  / |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |  \\  \\  /  /  |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |   \\  \\/  /   |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |    \\    /    |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |     \\__/     |  |  |  |       |  |  |  |           |  |          |  | \n");
	printf("|  |              |  |  |  |_ _ _ _|  |  |  |_ _ _ __   |  |          |  | \n");
	printf("|__|              |__|  |_ _ _ _ _ _ _|  |_ _ _ _ _ _|  |__|          |__| \n");
	printf("___________________________________________________________________________\n");	
}

//==================================================================================================================================================
//funcao que testa se login esta correto, tambem pode ser testado outras palavras
int comparasen(char log[], char key[]){
	int cont = 0;
	int a = strlen(log);
	int b = strlen(key);
	
	if(b<a){
			return 0;
		}
		
		if(b>a){
			return 0;
		}
		if(b==a){
		
			for(int i=0; i<strlen(log); i++){
	
				if(log[i]==key[i]){
					cont++;
				}	
				
			}
			if(cont==strlen(log)){
				return 1;
			}
			else{
				return 0;
			}		
		}
}

