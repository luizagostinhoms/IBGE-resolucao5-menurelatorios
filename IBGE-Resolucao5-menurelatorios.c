#include <stdio.h>

//QUINTA SOLU��O, CRIANDO MENU PARA EXTRA��O DE RELAT�RIOS E SAIDA DO PROGRAMA

/**
    Isso � uma etrutura de dados, podendo ter v�rias vari�vies dentro desta mesma.
    Ela � de melhor visualiza��o e entendimento que uma matriz por exemplo, 
    e pode conter informa��es de diversos tipos, como char e int.
    
    A estrutura est� sendo decladara fora da fun��o principal int main(), para poder ser usada nas outras fun��es.
*/
typedef struct cidade {//o typedef indica que toda essa estrutra se chamar� cidade, � necess�rop para usarmos em outras fun��es
  int codigo_cidade;
  char nome_cidade[50]; //iremos declarar mais uma informa��o, o nome da cidade.
  int numero_veiculo;
  int quantidade_vitimas;
} cidade;


int main () {

  int num_cidade;
  printf ("==== IBGE ==== \n \n");
  printf ("Digite a quantidade de cidades a serem cadastradas: ");
  scanf ("%d", &num_cidade);	// numero de cidades a ser cadastradas


  cidade cidades[num_cidade];	//aqui temos um vetor da estrutura cidade, declarada anteriormente
  popularDadosCidade(num_cidade, cidades);	//aqui chamamos um m�todo para popular as cidade, que passa o num_cidade e o array da cidade


  int menu = 5; //atribuindo valor diferente de zero para n�o sair do wile e n�o cair em nenhuma op��o do menu
  while (menu != 0){ // enquanto o menu for diferente de zero. n�o sair da APLICA��O
     
      imprimirMenuDeInformacoes(); //chama o m�todo que apenas informa as op��es
      scanf ("%d", &menu); // entrada da opp��o escolhida
      
     switch (menu)  { // caso o e menu caia em uma dessas o��es chamar� o m�todo que representa o relat�rio
           case 1:
             descobriCidadeComMaiorNAcidentes(num_cidade, cidades);
           break;
        
           case 2:
              descobriCidadeComMenorNAcidentes(num_cidade, cidades); 
           break;
        
           case 3:
             mediaVeiculosCidades(num_cidade, cidades);
           break;
           
           case 4:
             mediaAcidentesCidadesMenor2000Veiculos(num_cidade, cidades);
           break;
          
           case 0:
            printf ("\nSaindo da aplica��o ");
           break;
           default:
              printf ("\nValor inv�lido ");
        }
  }
  
 return 0;
}


/**fun��o que ir� popular o arrya cidade, 
 * fun��es servem para separar o c�digo e atribuir uma determinada tarefa, assim o c�digo se torna mais limpo menos confuso,
 * e de f�cil manuten��o
 * 
 * o void indica que o m�todo n�o retorna nada, ele altera os volores por referencia, 
 * assim, as modifica��es feitas na variavel cidades reflitir� na variavel do m�todo principal int main().
  */
void popularDadosCidade(int num_cidade, cidade cidades[]) {

  printf ("\n\nAgora digite os dados da cidade: \n\n");
  for (int i = 0; i < num_cidade; i++) {				
      printf ("------------------------------");
      printf ("\n\nCadastro da cidade: %d", i + 1);

      printf ("\nDigite o c�digo da cidade: ");
      scanf ("%d", &cidades[i].codigo_cidade);	//usamos o "." (ponto) para poder indicar qual variavel da estrutura estamdos usando
      
      printf ("Digite o nome da cidade: ");
      scanf ("%s", &cidades[i].nome_cidade);

      printf ("Digite o n�mero de veiculos de passeio da cidade:");
      scanf ("%d", &cidades[i].numero_veiculo);

      printf ("Digite o n�mero de acidentes de tr�nsito com v�timas:");
      scanf ("%d", &cidades[i].quantidade_vitimas);
    }
}

void imprimirMenuDeInformacoes() {
    
    printf("\n\n----RELAT�RIOS----- \n\n");
    printf ("\nDigite a op��o desjada para: ");
    printf ("\n1 - DESCOBRIR CIDADE COM MAIOR NUMERO DE ACIDENTES: ");
    printf ("\n2 - DESCOBRIR CIDADE COM MENOR NUMERO DE ACIDENTES: ");
    printf ("\n3 - M�DIA DE VEICULOS ENTRE AS CIDADES: ");
    printf ("\n4 - M�DIA DE ACIDENTES ENTRE AS CIDADES COM MENOS DE 2000 VEICULOS: ");
    printf ("\n0 - SAIR DA APLICA��O: ");
    printf ("\nopca��:");
}
    

/**
    M�todo para l�gica de maior, 
    pegamos as informa��es da priemira posi��es do vetor e comparamos com as sbsequentes da mesma
    se o volor da vari�vel for menor que a comparada, ela recebe o valor da comparada, 
    assim no final a vari�vel ficar� com o maior valor de todo o array.
*/
void descobriCidadeComMaiorNAcidentes(int num_cidade, cidade cidades[]){
    

    struct cidade cidadeMaiorAcidente = cidades[0]; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informa��o da mesma cidade.
    int maior_n_acidente = cidades[0].quantidade_vitimas;  //vari�vel para guardar o valor do maior numero de acidentes, essa vari�vel ser� agora apenas de controle, o resultado usarmoes a variavel cidadeMaiorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < cidades[i].quantidade_vitimas) {
            maior_n_acidente = cidades[i].quantidade_vitimas;
            cidadeMaiorAcidente = cidades[i]; //a variavel cidadeMaiorAcidente receve toda a estrutra da cidades da posi��o [i] para usarmos posteriormente.
        }
     }
    printf ("\n------------------------------");
    printf("\nA cidade com maior ind�ce de acidentes �: %d", cidadeMaiorAcidente.codigo_cidade);
    printf("\nO Nome da cidade com  maior ind�ce de acidentes �: %s", cidadeMaiorAcidente.nome_cidade);
    printf("\nE o n�mero de acidentes �: %d", cidadeMaiorAcidente.quantidade_vitimas);
}


/**
    M�todo para l�gica de de menor, 
    pegamos as informa��es da priemira posi��es do vetor e comparamos com as sbsequentes da mesma
    se o volor da vari�vel for maior que a comparada, ela recebe o valor da comparada, 
    assim no final a vari�vel ficar� com o menor valor de todo o array.
*/
void descobriCidadeComMenorNAcidentes(int num_cidade, cidade cidades[]) {
  
    struct cidade cidadeMenorAcidente = cidades[0]; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informa��o da mesma cidade.
    int menor_n_acidente = cidades[0].quantidade_vitimas;  //vari�vel para guardar o valor do menor numero de acidentes, essa vari�vel ser� agora apenas de controle, o resultado usarmoes a variavel cidadeMenorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > cidades[i].quantidade_vitimas) {
            menor_n_acidente = cidades[i].quantidade_vitimas;
             cidadeMenorAcidente = cidades[i]; //a variavel cidadeMenorAcidente receve toda a estrutra da cidades da posi��o [i] para usarmos posteriormente.
        }
     }
    printf ("\n------------------------------");
    printf("\nO c�digo da cidade com  menor ind�ce de acidentes �: %d", cidadeMenorAcidente.codigo_cidade);
    printf("\nO Nome da cidade com  menor ind�ce de acidentes �: %s", cidadeMenorAcidente.nome_cidade);
    printf("\nE o n�mero de acidentes �: %d", cidadeMenorAcidente.quantidade_vitimas);
}


/**
    M�todo de m�dia de veiculos, somamos todos os veiculos do array,
    e no fim dividimos pela quantiade de cidades.
*/
void mediaVeiculosCidades(int num_cidade, cidade cidades[]) {
  
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + cidades[i].numero_veiculo;
    }
    
    float media_veiculo = total_veiculos / num_cidade;
    printf ("\n------------------------------");
    printf("\nA m�ida de veiculos nas cidades juntas �: %.1f", media_veiculo);
}


/**
    M�todo de m�dia de acidentes de tr�nsito, 
    desde que a cidade tenha menos que 2000 veiculos.
*/
void mediaAcidentesCidadesMenor2000Veiculos(int num_cidade, cidade cidades[]) {
  
    int total_acident_transito = 0; //vari�vel para somar os acidentes de tr�nsito
    int count_cidades_menor_2000 = 0; //var�vel que ir� contar quntas cidade tem menos que 2000, necess�ria para m�dia, j� que n�o faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(cidades[i].numero_veiculo < 2000){
            total_acident_transito = total_acident_transito + cidades[i].quantidade_vitimas;
            count_cidades_menor_2000++;
        }
    }
    
     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf ("\n------------------------------");
     printf("\nA m�ida de acidentes de tr�nsito em cidades com menos de 2000 ve�culos �: %.1f", media_acidente_transito);
}


