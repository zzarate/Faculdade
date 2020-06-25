/**************************************************
*
* João Víctor Zárate Pereira Araújo
* Trabalho 1
* Professor(a): Diego Padilha Rubert
*
*/

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>


#define MIN 3
#define MAX 20

#define TAM_LINE 128

/* Célula de uma lista encadeada de ocorrências, armazena um inteiro */
class Ocorrencia {
  friend class ListaO;

public:
  Ocorrencia(int linha); // Construtor padrão
  ~Ocorrencia();         // Destrutor padrão

private:
  int linha;
  Ocorrencia *prox;
};


/* Lista encadeada de ocorrências, inserção realizada no fim da lista.
 * Tenha o cuidado de não inserir duplicatas */
class ListaO {
public:
  ListaO();               // Construtor padrão
  ~ListaO();              // Destrutor padrão
  void insere(int linha); // Recebe um inteiro e insere na lista
  void escreve();         // Escreve os elementos da lista

private:
  Ocorrencia *inicio; // Início da lista
  Ocorrencia *fim;    // Fim da lista
};


/* Célula de uma lista encadeada de palavras, armazena uma cadeia de caracteres */
class Palavra {
  friend class ListaP;

public:
  Palavra(char p[]);      // Construtor padrão
  ~Palavra();             // Destrutor padrão
  void insere(int linha); // Insere uma ocorrência na lista de ocorrências
  void escreve();         // Escreve a palavra e suas ocorrências

private:
  char p[MAX];        // A palavra em si
  ListaO ocorrencias; // Lista de ocorrências
  Palavra *prox;      // Próxima Palavra na lista
};


/* Lista encadeada de palavras, inserção realizada no fim da lista.
 * Tenha o cuidado de não inserir duplicatas */
class ListaP {
public:
  ListaP();                  // Construtor padrão
  ~ListaP();                 // Destrutor padrão
  Palavra *insere(char p[]); // Recebe uma palavra e insere na lista, devolvendo um ponteiro para o objeto inserido
  Palavra *busca(char p[]);  // Busca e devolve o objeto de uma palavra na lista
  void escreve();            // Escreve os elementos da lista

private:
  Palavra *inicio; // Início da lista
  Palavra *fim;    // Fim da lista
};


/* Tabela de dispersão que guarda um índice de palavras */
class TabelaDispersao {
public:
  TabelaDispersao();  // Construtor padrão
  ~TabelaDispersao(); // Destrutor padrão
  void escreve();     // Escreve a tabela (incluindo fator de carga)
  void novaOcorrencia(char p[], int linha); // Registra uma nova ocorrência de uma palavra
  
private:
  static const int TAMANHO = 47; // Tamanho da tabela
  ListaP tabela[TAMANHO];        // Listas da tabela
  float qnt;                       //Quantidade de palavras na lista

  int valor(char p[]); // Valor da palavra p
  int h(char p[]);     // Função de hash
};

/******************************************************
 *              MEU CODIGO                            *
 ******************************************************/

/*********************************** OCORRENCIA ***********************************/
Ocorrencia::Ocorrencia(int linha){
  this->linha=linha;
  prox=NULL;
}

Ocorrencia::~Ocorrencia(){

}

/*********************************** LISTA O ***********************************/
ListaO::ListaO(){
  inicio=NULL;
  fim=NULL;

}

ListaO::~ListaO(){
  Ocorrencia *temp;
  Ocorrencia *aux;
  temp=inicio;

  while (temp)
  {
    aux=temp;
    temp= temp->prox;
    delete aux;
  }
}

void ListaO::insere(int linha){  
  if (inicio == NULL)
  {
    Ocorrencia *o = new Ocorrencia(linha);
    inicio=o;
    inicio->prox=NULL;
    fim=o;
  }else
  {
    if (fim->linha!=linha)
    {
      Ocorrencia *o = new Ocorrencia(linha);
      fim->prox= o;
      fim=o;
    }
  }
}

void ListaO::escreve(){
  Ocorrencia *temp;
  temp=inicio;
  printf ("(");
  while (temp)
  {
    printf ("%d", temp->linha);
    if ( (temp= temp->prox) ){
      printf (",");
    }
  }
  printf (")");
}

/*********************************** PALAVRA ***********************************/

/*Construtor padrão de palavra*/
Palavra::Palavra(char p[]){
  /*Passa o conteudo da palavra passada 
   como parametro para a chave da palavra*/
  for (int i = 0; i < MAX; i++)
  {
    this->p[i]=p[i];
  }
  prox=NULL;/*Como é a ultima palavra a ser inserida proximo aponta para NULO*/
}

Palavra::~Palavra(){

}

void Palavra::insere(int linha){
  ocorrencias.insere(linha);
}

void Palavra::escreve(){
  int i=0;
  while (p[i])
  {
    printf ("%c", p[i]);
    i++;
  }
  ocorrencias.escreve();
}

/*********************************** LISTA P ***********************************/

ListaP::ListaP(){
  inicio= NULL;
  fim= NULL;
}

ListaP::~ListaP(){
  Palavra *temp;
  Palavra *aux;
  temp=inicio;

  while (temp)
  {
    aux=temp;
    temp= temp->prox;
    delete aux;
  }
}

/*Insere palavra na lista*/
Palavra *ListaP::insere(char p[]){
  Palavra *palavra = new Palavra(p);//Cria uma nova palavra

  //Caso não tenha palavra na lista, palavra será o inicio, e o próx. será nulo;
  if (inicio == NULL)
  {
    inicio=palavra;
    palavra->prox= NULL;
  }else {
    fim->prox = palavra;
  }
  fim=palavra; /*Fim recebe o endereço de palavra, pois é a ultima palavra a ser inserida*/
  return palavra;
}

Palavra *ListaP::busca(char p[]){
  Palavra *temp;
  Palavra *aux= new Palavra(p);
  temp=inicio;

  if(inicio){
    while (temp)
    {
    if (*temp->p == *aux->p)
    {
      delete aux;
      return temp;
    }
    temp= temp->prox;
    }
  }
  delete aux;
  return NULL;
}

void ListaP::escreve(){
  if (inicio)
  {
    Palavra *temp;
    temp=inicio;
    printf (" ");
    while (temp)
    {
      temp->escreve();
      if ( (temp= temp->prox) ){
        printf (" ");
      }
    }
  }
}


/***********************************  TABELA DE DISPERSÃO ***********************************/

TabelaDispersao::TabelaDispersao(){
  qnt=0;
  
}

TabelaDispersao::~TabelaDispersao(){

}

void TabelaDispersao::escreve(){

  for (int i = 0; i < TAMANHO; i++)
  {
    printf ("%d:", i);
    tabela[i].escreve();
    printf ("\n");
  }
  printf ("Fator de carga: %f",qnt/TAMANHO);
}

void TabelaDispersao::novaOcorrencia(char p[], int linha){
  int hash =h(p);
  ListaP lista;
  Palavra *end= NULL;

  if ((end = tabela[hash].busca(p)))
  {
    end->insere(linha);//Insere uma nova ocorrencia
  }
  else//caso seja nulo
  {
    end = tabela[hash].insere(p); //Insere uma nova palavra
    end->insere(linha); //Insere uma nova ocorrencia
    qnt++;
  }
}

/*Calcula o valor da palavra*/
int TabelaDispersao::valor(char p[]){
  int i=0;
  int valor=0;
  while (p[i])
  {
    valor += p[i];
    i++;
  }
  return valor;
}


/*Faz o calculo do hash*/
int TabelaDispersao::h(char p[]){
  int result;
  int i=0;
  int num = valor(p);
  while (p[i])
  {
    result= (num %TAMANHO);
    i++;
  }
  return result;
}
/*********************************** ARQUIVO ***********************************/

/*  Operações com o arquivo passado como parametro */
class Arquivo {
	public:
	Arquivo(); //Construtor padrão
	~Arquivo(); // Destrutor padrão
	void Abre(char *nome_arquivo);  // Abre o arquivo
  void Le (); //Faz a leitura do conteudo do arquvio
  void escreve (); // Escreve tabela de dispersão referente ao arquivo;

	private:
	FILE *arquivo;  //Arquivo que será lido
  TabelaDispersao tabela; 

};

 Arquivo::Arquivo(){

 }

Arquivo::~Arquivo(){
  fclose (arquivo);//Fecha o arquivo
}

              
 /* char *nome_arquivo= recebe ponteiro para o array que contém o nome do arquivo, não há retorno  *
  * Verifica se o arquivo do nome dado como parametro existe, caso exista abre o arquivo e chama o *
  * método Arquivo::Le(), onde é lido o arquivo e enviada a tabela hash.                           */
void Arquivo::Abre(char *nome_arquivo){
  if ((arquivo = fopen(nome_arquivo, "r")) == NULL)
  {
     perror("Erro ao abrir arquivo");
     exit (1);
  }
}

/* Chamado para fazer a leitura de um arquivo, verificando por linha *
 * e em cada linha, separando em palavras, e caso a palavra seja >=  *
 * a MIN letras, é enviado para a tabela de dispersão                  */
void Arquivo::Le(){
  int line_count = 1; //Conta em qual linha esta atualmente a leitura
  char linha [TAM_LINE];
  char palavra [MAX];

  //Inicializa todas as posições da linha com NULL 
  for (int k = 0; k < MAX; k++)
  {
    palavra[k] = 0;
  }
  
  //Le, linha por linha
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    if(linha[strlen(linha)] !='\0' ){
      linha[strlen(linha) - 1] = '\0';
    }
    
    int i=0;//controla a posição da linha
    int j=0;//controla a posição da palavra

    //Verifica todas as posiçòes da linha até o fim da linha
    while (linha[i] != '\0')
    {
      //Vefifica se a posição da linha lida é uma letra
      if ((linha [i] >= 'a' && linha [i] <= 'z') || (linha [i] >= 'A' && linha [i] <= 'Z') ){
        palavra[j] = linha [i]; 
        j++;
      } 
      else {
        //Caso a palavra tenha mais de 2 letras
        if (j>=MIN){
          //Passa todos os caracteres para minusculo
          for (int k=0; k<MAX; k++){
            palavra[k] = tolower(palavra[k]);
          }
          tabela.novaOcorrencia(palavra, line_count);
        }
        //Limpa a palavra
        for (int k = 0; k < MAX; k++)
        {
          palavra[k] =0;
        }
        j=0;
      }
      /*Caso a proxima posição da linha seja nulo verifica
       * se a apalavra >= 3 e registra nova ocorrencia */
      if(linha[i+1] == 0 ){
        //Caso a palavra tenha mais de 2 letras
        if (j>=MIN){
          //Passa todos os caracteres para minusculo
          for (int k=0; k<MAX; k++){
            palavra[k] = tolower(palavra[k]);
          }
          tabela.novaOcorrencia(palavra, line_count);
        }
        //Limpa a palavra
        for (int k = 0; k < MAX; k++)
        {
          palavra[k] =0;
        }
        j=0;
      }

      i++;
    }
    line_count++;
  }
}

void Arquivo::escreve(){
  tabela.escreve();
}

/*********************************** MAIN ***********************************/


int main (int argc, char *argv[]){
    if (argc < 2 )
    {
        std::cout <<"Erro! Deve-se passar o nome do arquivo de texto como argumento.\n";
        exit (1);
    }
    char *nome_arquivo = argv[1];
    
    
    //Inicia a leitura do arquivo de texto
    Arquivo arq;
    arq.Abre(nome_arquivo);
    arq.Le ();
    arq.escreve();
    
    arq.~Arquivo();
    exit (0);    
}