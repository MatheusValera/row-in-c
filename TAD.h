#define MAXFILA 50

struct Processo{
	char nome[20];
	int prioridade, ut;
};

struct F{
	Processo fila[MAXFILA];
	int inicio,fim,cont;
};

void inicializar(F &row);
char vazia(F row);
char cheia(F row);
void inserir(F &row, Processo elemento);
Processo retirar(F &row);
void exibir(F row);
Processo fila_inicio(F row);
Processo fila_fim(F row);

void inicializar(F &row)
{
	row.inicio = row.cont = 0;
	row.fim = -1;
}

char vazia(F row)
{
	return row.cont==0;
}

char cheia(F row)
{
	return row.cont==MAXFILA;
}

void inserir(F &row,Processo elemento)
{
	row.fila[++row.fim] = elemento;
	row.cont++;
	Processo aux;
	int pos = row.fim;
	while(pos != row.inicio && row.fila[pos].prioridade < row.fila[pos-1].prioridade)
	{
		aux = row.fila[pos];
		row.fila[pos] = row.fila[pos-1];	
		row.fila[pos-1] = aux;
		pos--;
		if(pos == 0 && pos !=row.inicio){
			if(row.fila[0].prioridade < row.fila[MAXFILA-1].prioridade)
			{
				aux = row.fila[0];
				row.fila[0] = row.fila[MAXFILA-1];
				row.fila[MAXFILA-1] = aux;
			}
			pos = MAXFILA-1;
		}
	}	
}

Processo retirar(F &row)
{
	Processo aux;
	aux = row.fila[row.inicio++];
	row.cont--;
	if(row.inicio == MAXFILA)
		row.inicio = 0;
	return aux;
}

void exibir(F row)
{
	Processo aux;
	while(!vazia(row))
	{
		aux=retirar(row);
		printf("Nome: %s\n Prioridade do cliente: %d\n UT: %d\n",aux.nome,aux.prioridade,aux.ut);
	}
}

Processo fila_inicio(F row)
{
	Processo aux = row.fila[row.inicio];
	return aux;
}

Processo fila_fim(F row)
{
	Processo aux = row.fila[row.fim];
	return aux;
}

