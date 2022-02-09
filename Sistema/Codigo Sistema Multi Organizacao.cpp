//============================================================================================================================================================================
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Aceitar palavras no padrão português-brasileiro com acentos
#include <string.h>
//============================================================================================================================================================================
//Estruturas de dados
typedef struct{
	char usuario[50];
	char senha[50];
}login; //  struct será usada para fazer login no sistema

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
}cad_biblioteca; // Struct para cadastro de bibliocário/monitor

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
//Variáveis; Declaração de funções
	int opcao; char buffer; FILE *sen; login pr, log, teste;
	int testlog, testsen; char tentenov;

	setlocale(LC_ALL, "Portuguese"); //Aceitar palavras no padrão português-brasileiro com acentos

	void cabecalho();
	int comparasen(char log[], char key[]);
	void cadlivros();
	void printbook();
	void cadbiblioteca();
	void printbibliotecario();
	void livroemprestados();
	void outrasferramentas();
	void buscalivro();
//============================================================================================================================================================================	
//Login no sistema
sen = fopen("arqsenha", "rb"); //caso baixe o código sugiro que apague o arquivo "arqsenha" para que crie seu login
//login padrão -> Usuário = Biblioteca; Senha = eeep12
	if(sen == NULL){ //Testar se o usuário ja tem um login no sistema, 
					 //de maneira básica vou usar arquivos, se o arquivo "sen" estiver na máquina, significa q ja existe um login.
		sen = fopen("arqsenha", "w+b"); // caso seja NULL irá ser feito a crição de um login
		cabecalho();
		printf("Bem-vindo ao Multi-Organização\nEsse é seu primeiro acesso, se cadastre:");
		printf("\nDigite um usuário para login: ");
		scanf("%[^\n]s", pr.usuario);
		scanf("%c", &buffer);
		printf("Digite uma senha para login: ");
		scanf("%[^\n]s", pr.senha);
		scanf("%c", &buffer);
		
		fwrite(&pr, sizeof(login), 1, sen); // gravar senha no arquivo
		if(ferror(sen)){ // testar se ouve erro
			printf("\nErro na Gravação\n");
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
		else{ //Após a criação do login, será pedido que o usuário faça o login
			
			while(!feof(sen)){
			fread(&pr, sizeof(login), 1, sen);
			}
			
			if(ferror(sen)){
				printf("\nErro no Sistema.\n");	
			}
		    
		    do{
			cabecalho();
			printf("Faça seu login para ter acesso ao Multi-Organização:");
			printf("\nDigite seu usuario: ");
			scanf("%[^\n]s", log.usuario);
			scanf("%c", &buffer);
			printf("Digite sua senha: ");
			scanf("%[^\n]s", log.senha);
			scanf("%c", &buffer);
			system("cls");
			
			testlog = comparasen(pr.usuario, log.usuario);
			testsen = comparasen(pr.senha, log.senha);
			
			if(testlog == 0 ||  testsen == 0){ // testar se senhas estão corretas atraves da função comparasen
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
			printf("Faça seu login para ter acesso ao Multi-Organização:");
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
        printf("\nSeja Bem-Vindo ao Multi-Organização!");
        printf("\nO que deseja fazer?");
        printf("\n[1]-Cadastro de Livros");
        printf("\n[2]-Cadrastro de Bibliotecários ou Voluntários");
        printf("\n[3]-Bibliotecários e Voluntários da Biblioteca");
        printf("\n[4]-Lista de Livros");
        printf("\n[5]-Lista de Livros Emprestados");
        printf("\n[6]-Buscar Livro");
        printf("\n[7]-Outras Ferramentas");
        printf("\n[0]-Sair do Sistema Multi-Organização");
        printf("\nDigite sua opção: ");
		scanf("%d", &opcao); system("cls");
		
		switch(opcao){
			case 0:
				cabecalho();
				printf("Sucesso ao sair. Obrigado pelo seu acesso!\n");	
				break;
				
			case 1:
				cadlivros();
				break;
			
			case 2:
				cadbiblioteca();
				break;
				
			case 3:
				printbibliotecario();
				break;
				
			case 4:
				//printbook();
				break;
				
			case 5:
				//livroemprestados();
				break;
				
			case 6:
				//buscalivro();
				break;	
			
			case 7:
				//outrasferramentas();
				break;	
				
			default:
				cabecalho();
				printf("Opçao indisponível, tente novamente!\n");
		        system("pause"); system("cls");
				break;
			}
	}while(opcao != 0);
	
	system("pause");
	return 0;
}

//============================================================================================================================================================================
//função cabeçalho
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
//==================================================================================================================================================
/// Case 1 = Função para cadastro de livros

void cadlivros(){
	FILE *CADL;
	cad_livro l1;
	char getche, buffer;
	
	CADL = fopen("cadastro de livros", "ab");
	
	if(CADL == NULL){
		printf("Erro no Sistema!\n\n");
	}
	
	else{
		
		do{
		cabecalho();
		fflush(stdin);
		printf("Digite o título do livro: ");
		fgets(l1.titulo, 50, stdin);
		l1.titulo[strcspn(l1.titulo, "\n")] = '\0';
		
		printf("Digite o nome do autor do livro: ");
		fgets(l1.autor, 50, stdin);
		l1.autor[strcspn(l1.autor, "\n")] = '\0';
		
		printf("Digite a editora do livro: ");
		fgets(l1.editora, 20, stdin);
		l1.editora[strcspn(l1.editora, "\n")] = '\0';
		
		fwrite(&l1, sizeof(cad_livro), 1, CADL);
		
		printf("Deseja cadastrar um novo Livro? (s/n)");
		scanf("%c", &getche);
		scanf("%c", &buffer);
		
		}while(getche == 's');
		fclose(CADL);
	}
	
} 
//==================================================================================================================================================
// Case 2 = Cadastro de Bibliotecarios e Voluntarios

void cadbiblioteca(){

	FILE *CADB;
	cad_biblioteca cad1;
	char getche, buffer;
	
	CADB = fopen("cadastro de Bibliotecario", "ab");
	
	if(CADB == NULL){
		printf("Erro no Sistema!\n\n");
	}
	
	else{
		
		do{
		cabecalho();
		fflush(stdin);
		printf("Digite o nome do Bibliotecário/Voluntário: ");
		fgets(cad1.nome, 100, stdin);
		cad1.nome[strcspn(cad1.nome, "\n")] = '\0';
		
		printf("Digite o CPF do Bibliotecário/Voluntário: ");
		fgets(cad1.cpf, 12, stdin);
		cad1.cpf[strcspn(cad1.cpf, "\n")] = '\0';
		
		printf("Digite a data de nascimento: (EX: 11 01 2002)");
		scanf("%d %d %d", &cad1.data.dia, &cad1.data.mes, &cad1.data.ano);
		
		fflush(stdin);
		printf("Digite o cargo(Bibliotecário/Voluntário): ");
		fgets(cad1.cargo, 20, stdin);
		cad1.cargo[strcspn(cad1.cargo, "\n")] = '\0';
		
		fwrite(&cad1, sizeof(cad_biblioteca), 1, CADB);
		
		printf("Deseja cadastrar outro Bibliotecário/Voluntário? (s/n)");
		scanf("%c", &getche);
		scanf("%c", &buffer);
		
		}while(getche == 's');
		fclose(CADB);
	}
}

//==================================================================================================================================================
// Case 3 = Lista de Bibliotecarios e Voluntarios

void printbibliotecario(){

    FILE *prb;
	cad_biblioteca cad1;
	int EOF_ctrl, cont;
	
	prb = fopen("cadastro de Bibliotecario", "rb");
	
	if(prb==NULL){
		cabecalho();
		printf("Ainda não existem Bibliotecarios/Voluntários cadastrados!\n\n");
		system("pause");
	}
	
	else{
		cont=0;
		cabecalho();
		printf("\nLISTA DE BIBLIOTECÁRIOS/VOLUNTÁRIOS:\n");
		while(!feof(prb)){
			EOF_ctrl = fread(&cad1, sizeof(cad_biblioteca), 1, prb);
			if(ferror(prb)){
				printf("\nErro no Sistema.\n");	
			}
			else{
				if(EOF_ctrl != 0){
					printf("---------------------------------------------\n");
					printf("Nome: %s\n", cad1.nome);
					printf("CPF: %s\n", cad1.cpf);
					printf("Data de Nascimento: %d/%d/%d\n", cad1.data.dia, cad1.data.mes, cad1.data.ano);
					printf("Cargo: %s\n", cad1.cargo);
					printf("---------------------------------------------\n\n");
					cont++;
				}
			}
		}
		
		if(cont==0){
				printf("Não existem Bibliotecarios/Voluntários cadastrados!\n\n");	
		}
		
		system("pause");
	}
	fclose(prb);
}

