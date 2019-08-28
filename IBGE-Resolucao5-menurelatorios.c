#include <stdio.h>

//QUINTA SOLUÇÃO, CRIANDO MENU PARA EXTRAÇÃO DE RELATÓRIOS E SAIDA DO PROGRAMA

/**
    Isso é uma etrutura de dados, podendo ter várias variávies dentro desta mesma.
    Ela é de melhor visualização e entendimento que uma matriz por exemplo, 
    e pode conter informações de diversos tipos, como char e int.
    
    A estrutura está sendo decladara fora da função principal int main(), para poder ser usada nas outras funções.
*/
typedef struct cidade {//o typedef indica que toda essa estrutra se chamará cidade, é necessárop para usarmos em outras funções
  int codigo_cidade;
  char nome_cidade[50]; //iremos declarar mais uma informação, o nome da cidade.
  int numero_veiculo;
  int quantidade_vitimas;
} cidade;


int main () {

  int num_cidade;
  printf ("==== IBGE ==== \n \n");
  printf ("Digite a quantidade de cidades a serem cadastradas: ");
  scanf ("%d", &num_cidade);	// numero de cidades a ser cadastradas


  cidade cidades[num_cidade];	//aqui temos um vetor da estrutura cidade, declarada anteriormente
  popularDadosCidade(num_cidade, cidades);	//aqui chamamos um método para popular as cidade, que passa o num_cidade e o array da cidade


  int menu = 5; //atribuindo valor diferente de zero para não sair do wile e não cair em nenhuma opção do menu
  while (menu != 0){ // enquanto o menu for diferente de zero. não sair da APLICAÇÃO
     
      imprimirMenuDeInformacoes(); //chama o método que apenas informa as opções
      scanf ("%d", &menu); // entrada da oppção escolhida
      
     switch (menu)  { // caso o e menu caia em uma dessas oções chamará o método que representa o relatório
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
            printf ("\nSaindo da aplicação ");
           break;
           default:
              printf ("\nValor inválido ");
        }
  }
  
 return 0;
}


/**função que irá popular o arrya cidade, 
 * funções servem para separar o código e atribuir uma determinada tarefa, assim o código se torna mais limpo menos confuso,
 * e de fácil manutenção
 * 
 * o void indica que o método não retorna nada, ele altera os volores por referencia, 
 * assim, as modificações feitas na variavel cidades reflitirá na variavel do método principal int main().
  */
void popularDadosCidade(int num_cidade, cidade cidades[]) {

  printf ("\n\nAgora digite os dados da cidade: \n\n");
  for (int i = 0; i < num_cidade; i++) {				
      printf ("------------------------------");
      printf ("\n\nCadastro da cidade: %d", i + 1);

      printf ("\nDigite o código da cidade: ");
      scanf ("%d", &cidades[i].codigo_cidade);	//usamos o "." (ponto) para poder indicar qual variavel da estrutura estamdos usando
      
      printf ("Digite o nome da cidade: ");
      scanf ("%s", &cidades[i].nome_cidade);

      printf ("Digite o número de veiculos de passeio da cidade:");
      scanf ("%d", &cidades[i].numero_veiculo);

      printf ("Digite o número de acidentes de trânsito com vítimas:");
      scanf ("%d", &cidades[i].quantidade_vitimas);
    }
}

void imprimirMenuDeInformacoes() {
    
    printf("\n\n----RELATÓRIOS----- \n\n");
    printf ("\nDigite a opção desjada para: ");
    printf ("\n1 - DESCOBRIR CIDADE COM MAIOR NUMERO DE ACIDENTES: ");
    printf ("\n2 - DESCOBRIR CIDADE COM MENOR NUMERO DE ACIDENTES: ");
    printf ("\n3 - MÉDIA DE VEICULOS ENTRE AS CIDADES: ");
    printf ("\n4 - MÉDIA DE ACIDENTES ENTRE AS CIDADES COM MENOS DE 2000 VEICULOS: ");
    printf ("\n0 - SAIR DA APLICAÇÃO: ");
    printf ("\nopcaçõ:");
}
    

/**
    Método para lógica de maior, 
    pegamos as informações da priemira posições do vetor e comparamos com as sbsequentes da mesma
    se o volor da variável for menor que a comparada, ela recebe o valor da comparada, 
    assim no final a variável ficará com o maior valor de todo o array.
*/
void descobriCidadeComMaiorNAcidentes(int num_cidade, cidade cidades[]){
    

    struct cidade cidadeMaiorAcidente = cidades[0]; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informação da mesma cidade.
    int maior_n_acidente = cidades[0].quantidade_vitimas;  //variável para guardar o valor do maior numero de acidentes, essa variável será agora apenas de controle, o resultado usarmoes a variavel cidadeMaiorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(maior_n_acidente < cidades[i].quantidade_vitimas) {
            maior_n_acidente = cidades[i].quantidade_vitimas;
            cidadeMaiorAcidente = cidades[i]; //a variavel cidadeMaiorAcidente receve toda a estrutra da cidades da posição [i] para usarmos posteriormente.
        }
     }
    printf ("\n------------------------------");
    printf("\nA cidade com maior indíce de acidentes é: %d", cidadeMaiorAcidente.codigo_cidade);
    printf("\nO Nome da cidade com  maior indíce de acidentes é: %s", cidadeMaiorAcidente.nome_cidade);
    printf("\nE o número de acidentes é: %d", cidadeMaiorAcidente.quantidade_vitimas);
}


/**
    Método para lógica de de menor, 
    pegamos as informações da priemira posições do vetor e comparamos com as sbsequentes da mesma
    se o volor da variável for maior que a comparada, ela recebe o valor da comparada, 
    assim no final a variável ficará com o menor valor de todo o array.
*/
void descobriCidadeComMenorNAcidentes(int num_cidade, cidade cidades[]) {
  
    struct cidade cidadeMenorAcidente = cidades[0]; //declaramos uma cidade novamente para depois fazer o uso da mesma no resultado, isso facita caso necessitamos pegar outra informação da mesma cidade.
    int menor_n_acidente = cidades[0].quantidade_vitimas;  //variável para guardar o valor do menor numero de acidentes, essa variável será agora apenas de controle, o resultado usarmoes a variavel cidadeMenorAcidente acima.
    for (int i = 0; i < num_cidade; i++) {
        if(menor_n_acidente > cidades[i].quantidade_vitimas) {
            menor_n_acidente = cidades[i].quantidade_vitimas;
             cidadeMenorAcidente = cidades[i]; //a variavel cidadeMenorAcidente receve toda a estrutra da cidades da posição [i] para usarmos posteriormente.
        }
     }
    printf ("\n------------------------------");
    printf("\nO código da cidade com  menor indíce de acidentes é: %d", cidadeMenorAcidente.codigo_cidade);
    printf("\nO Nome da cidade com  menor indíce de acidentes é: %s", cidadeMenorAcidente.nome_cidade);
    printf("\nE o número de acidentes é: %d", cidadeMenorAcidente.quantidade_vitimas);
}


/**
    Método de média de veiculos, somamos todos os veiculos do array,
    e no fim dividimos pela quantiade de cidades.
*/
void mediaVeiculosCidades(int num_cidade, cidade cidades[]) {
  
    int total_veiculos = 0;
    for (int i = 0; i < num_cidade; i++) {
        total_veiculos = total_veiculos + cidades[i].numero_veiculo;
    }
    
    float media_veiculo = total_veiculos / num_cidade;
    printf ("\n------------------------------");
    printf("\nA méida de veiculos nas cidades juntas é: %.1f", media_veiculo);
}


/**
    Método de média de acidentes de trânsito, 
    desde que a cidade tenha menos que 2000 veiculos.
*/
void mediaAcidentesCidadesMenor2000Veiculos(int num_cidade, cidade cidades[]) {
  
    int total_acident_transito = 0; //variável para somar os acidentes de trânsito
    int count_cidades_menor_2000 = 0; //varável que irá contar quntas cidade tem menos que 2000, necessária para média, já que não faremos desta vez com a quantiade de cidades.
    for (int i = 0; i < num_cidade; i++) {
        if(cidades[i].numero_veiculo < 2000){
            total_acident_transito = total_acident_transito + cidades[i].quantidade_vitimas;
            count_cidades_menor_2000++;
        }
    }
    
     float media_acidente_transito = total_acident_transito / count_cidades_menor_2000;
     printf ("\n------------------------------");
     printf("\nA méida de acidentes de trânsito em cidades com menos de 2000 veículos é: %.1f", media_acidente_transito);
}


