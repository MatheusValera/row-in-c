#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "TAD.h"

char menu ()
{
    int i;
    system("cls");
    gotoxy(10,1); printf("%c",201);
    gotoxy(110,1); printf("%c",187);
    gotoxy(10,22); printf("%c",200);
    gotoxy(110,22); printf("%c",188);
    for(i=2; i<22; i++)
    {
        gotoxy(10,i); printf("%c",186);
        gotoxy(110,i); printf("%c",186);
    }
    for(i=11; i<110; i++)
    {
        gotoxy(i,1); printf("%c",205);
        gotoxy(i,22); printf("%c",205);
    }
    textbackground(0);
    gotoxy(39,2); printf(" TRABALHO 1 - 1 BIMESTRE - ESTRUTURA DE DADOS ");
    gotoxy(35,10); printf("[A] COMECAR");
    gotoxy(75,10); printf("[ESC] SAIR");
    gotoxy(57,16); printf("OPCAO:");
    return toupper(getche());
}

char menu1 ()
{
    int i;
    system("cls");
    gotoxy(10,1); printf("%c",201);
    gotoxy(110,1); printf("%c",187);
    gotoxy(10,22); printf("%c",200);
    gotoxy(110,22); printf("%c",188);
    for(i=2; i<22; i++)
    {
        gotoxy(10,i); printf("%c",186);
        gotoxy(110,i); printf("%c",186);
    }
    for(i=11; i<110; i++)
    {
        gotoxy(i,1); printf("%c",205);
        gotoxy(i,22); printf("%c",205);
    }
    textbackground(0);
    gotoxy(42,2); printf("ESCOLHA A OPCAO:");
    gotoxy(20,4); printf("[A] INICIALIZAR A FILA:");
    gotoxy(20,6); printf("[B] INSERIR CLIENTE NA FILA");  //INSERE NA VARIAVEL FILA
    gotoxy(20,8); printf("[C] RETIRAR O ELEMENTO DA FILA");
    gotoxy(20,10); printf("[D] EXIBIR FILA");
    gotoxy(20,12); printf("[E] PRIMEIRO CLIENTE DA FILA");
    gotoxy(70,4); printf("[F] ULTIMO CLIENTE DA FILA");
    gotoxy(70,6); printf("[G] EXECUTAR FILA COM AS UT"); //EXECUTA A FILA COM OS DADOS QUE ESTAO NO ARQUIVO
    gotoxy(70,8); printf("[ESC] SAIR");
    gotoxy(20,16); printf("OPCAO:");
    return toupper(getche());
}

void executarFila(char NomeArq[],F &row)
{
	FILE *arq = fopen(NomeArq,"r");
	if(arq==NULL)
		printf("Arquivo nao encontrado!");
	else
	{
		Processo elem,processo;
		processo.ut=0;
		int ut =0;
		while(!vazia(row) || !feof(arq))
		{
			if(ut % 3 == 0 && !feof(arq))
			{
				fscanf(arq,"%s %d %d\n",&elem.nome,&elem.prioridade,&elem.ut);
				printf("Novo processo foi inserido na fila:\nNome: %s\tPrioridade do cliente: %d\tTempo: %d\n",elem.nome,elem.prioridade,elem.ut);
				inserir(row,elem);
			}
			if(processo.ut>0)
			{
				processo.ut--;
				if(processo.ut == 0)
					printf("\nAtendimento do %s foi concluido!\n",processo.nome);
			}
			if(processo.ut ==0 && !vazia(row))
			{
				processo=retirar(row);
				printf("\nChamando o cliente %s para ser atendido!\n",processo.nome);
			}
			ut++;
			printf("\n\n");
			fclose(arq);
		}
	}
}
int main()
{
    Processo elem;
    F row;
	char op1, op2;
   do
   {
	   	op1=menu();
	   	switch(op1)
	   	{
	   	 	case 'A':	 
					do{
						op2=menu1();
				        switch(op2)
				        {
				            case 'A':	inicializar(row);
				            			system("cls");
				                		printf("\nFila inicializada com sucesso!\n");
				                		break;
				
				            case 'B':	system("cls");
										if(cheia(row))
											printf("Fila cheia\n");							
										else
										{
											printf("Digite o nome do cliente:\n");
				            				fflush(stdin);
				            				gets(elem.nome);
				            				printf("Digite a prioridade do atendimento (0-10):\n");
				            				scanf("%d",&elem.prioridade);
				            				printf("Digite o tempo de atendimento: ");
				            				scanf("%d",&elem.ut);
				            				inserir(row, elem);	
				            				printf("Elemento inserido na fila\n");
										}
						                break;
				
				            case 'C': 	system("cls");
				            			if(!vazia(row))
				            			{
				            				retirar(row);
				                			printf("\nElemento retirado com sucesso!\n");
										}
										else
				                			printf("Nao existe elemento para retirar\n");
				                		break;
				
				            case 'D': 	system("cls");
				            			if(!vazia(row))
				            				exibir(row);
										else
				                			printf("Nao existe elemento para exibir\n");				                
				                		break;
				
				            case 'E': 	system("cls");
										if(!vazia(row))
				            			{
				            				elem = fila_inicio(row);
				                			printf("Primeiro elemento da fila\nNome: %s\tPrioridade: %d\tUnidade de tempo: %d",elem.nome,elem.prioridade,elem.ut);
										}
										else
				                			printf("Nao existe elemento para exibir\n");
				                		break;
				
				            case 'F': 	system("cls");
										if(!vazia(row))
				            			{
				            				elem = fila_fim(row);
				                			printf("Ultimo elemento da fila\nNome: %s\tPrioridade: %d\tUnidade de tempo: %d",elem.nome,elem.prioridade,elem.ut);
										}
										else
				                			printf("Nao existe elemento para exibir\n");
				                		break;
				
				            case 'G': 	system("cls");
										executarFila("Clientes.txt",row);
				                		break;
				        }
			        	getch();
			    	}while(op2 != 27);
					break; 
		}
		
   }while(op1!=27);

    return 1;
}
