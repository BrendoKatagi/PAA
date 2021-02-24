
/*
Formando casais

O algoritmo simula um encontro entre várias pessoas, em que cada uma precisa votar em
no número de uma outra pessoa que ela se interessou e deseja ir  para a segunda fase do encontro
Após as votações são verificadas as pessoas que receberam votos. O grupo formado para a segunda fase de conter 
apenas candidatos que receberam votos de alguém. Se uma pessoa não recebe votos, consequentemente seu voto é invalidado 

Entrada
A entrada se inicia com uma linha contendo o número inteiro N (2 ≤ N ≤ 100.000) de participantes de um
evento. Cada participante é identificado por um número entre 1 e N. Em cada uma das próximas N linhas, serão
apresentados dois identificadores a e b para representar que a pessoa b foi indicada por outra pessoa a.
Saída
Imprima uma linha com os identificadores das pessoas a serem convidadas para a segunda etapa do
evento em ordem crescente. Imprima um espaço em branco entre 2 participantes.
*/

#include <stdio.h>
#include <stdlib.h>

struct candidato{
    int qtdVotos;
    struct candidato *prox;
    
};

void eliminaVoto(struct candidato *cand){
    
    cand->qtdVotos -= 1;
    
    if(cand->qtdVotos == 0 && cand->prox != NULL){
        eliminaVoto(cand->prox);
        cand->prox = NULL;
    }

}

void inicializa(struct candidato *c1){
    c1->qtdVotos = 0;
    c1->prox = NULL;
}

void setVotos(int numCandidatos, struct candidato *votos){
    int i, j, cand, voto;
    
    for(i=1; i < numCandidatos+1; i++){
        
        scanf("%d %d", &cand, &voto);
        if(voto >= 1 && voto <= numCandidatos){
            votos[cand].prox = &votos[voto];
            votos[voto].qtdVotos += 1;
        }    
        
    }
    
    for(j=1; j < numCandidatos+1; j++){
        
        if(votos[j].qtdVotos == 0 && votos[j].prox != NULL){
            eliminaVoto(votos[j].prox);
            votos[j].prox = NULL;
        }
    }
}

void imprimeVotos(int numCandidatos, struct candidato *votos){
    int j;
    
    for(j=1; j < numCandidatos+1; j++){
        if(votos[j].qtdVotos != 0){
            printf("%d ", j);
        }    
    }
    
}

int main()
{   
    int numCandidatos, i, j;
    int cand, voto;
    
    scanf("%d", &numCandidatos);
    
    struct candidato votos[numCandidatos+1];
    int validos[numCandidatos+1];
    
    for(i=1; i < numCandidatos+1; i++){
        validos[i] = 0;
        inicializa(&votos[i]);

    }
    
    setVotos(numCandidatos, votos);
    
    imprimeVotos(numCandidatos, votos);
    
    return 0;
}



