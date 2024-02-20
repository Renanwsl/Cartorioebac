#include  <stdio.h> //biblioteca de comunica��o com o usu�rio
#include  <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro ()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);// %s l� cada caracter e armazena na string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo no modo escrever
	fprintf(file,cpf); // escreve o valor de cpf no arquivo
	fclose(file); // fecha o arquivo
	 
	file = fopen(arquivo, "a");// acrescentqr dados no arquivo (append)
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");// acrescentqr dados no arquivo (append)
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");// acrescentqr dados no arquivo (append)
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	
	file = fopen(arquivo, "a");// acrescentqr dados no arquivo (append)
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");// acrescentqr dados no arquivo (append)
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");// acrescentqr dados no arquivo (append)
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado:");
    scanf("%s",cpf);
    
    FILE* file;
    file= fopen(cpf,"r");
    
    if(file == NULL)
	{
        printf("Esse CPF n�o foi localizado:\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    	
	}
	
	fclose(file);
	system("pause");
}

int deletar ()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado:\n");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE * file;
    file= fopen(cpf, "r");
    fclose(file);
    if(file == NULL)//Verifica se o CPF existe no banco de dados, se n�o exibe mensagem de erro.
    {
    	printf(" O usu�rio n�o se encontra cadastrado em nosso sistema!\n");
    	system("pause");
	}
    
}

int main ()
    {   
    int opcao=0; //definindo as vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	    system("cls");
	    
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
        printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a op��o desejada no menu:\n\n");
        printf("\t1 - Registrar nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes \n\n");
	    printf("Op��o:"); // fim do menu
    
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
        system("cls");
        
        switch(opcao)
        {
        	case 1: 
        	registro();
    	    break;
    	    
    	    case 2:
    	    consulta();
    	    break;
    	    
    	    case 3:
    	    deletar();
			break;
			
			default:printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
		}
    
       
	
	
    }

}
