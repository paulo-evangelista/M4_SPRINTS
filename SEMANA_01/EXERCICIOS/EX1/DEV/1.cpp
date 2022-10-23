#include <stdlib.h>
#include <iostream>

using namespace std;

// ex. 1
float converteSensor(float num, float min, float max){
    float res = (num-min) / (max-min);
    return res;
}

// ex. 2 - lê uma entrada de teclado.
//Uma simulação da leitura de um sensor de fato está no arquivo 2.ino
char lerTeclado(){
    char c;
    cin >> c;
    return c;
}

// ex. 3
// recebe um vetor, a posição a ser preenchida, o maximo de entradas para o vetor e um valor a ser inserido.
int addVetor(int *vetor, int pos, int max, int valor){
    if(pos < max){
        vetor[pos] = valor;
    }
    return vetor;
}

//ex. 4 - recebe um vetor d
char maiorDistancia(int *vetor){
    int d1 = vetor[0];
    int d2 = vetor[1];
    int d3 = vetor[2];
    int d4 = vetor[3];

    if(d1 > d2 && d1 > d3 && d1 > d4){
        return 'Direita - %d', d1;
    }else if(d2 > d1 && d2 > d3 && d2 > d4){
        return 'Esquerda - %d', d2;
    }else if(d3 > d1 && d3 > d2 && d3 > d4){
        return 'Frente - %d', d3;
    }else if(d4 > d1 && d4 > d2 && d4 > d3){
        return 'Tras - %d', d4;
    }
}

// ex. 5
bool leComando(){
    char entrada;
    cout << "Deseja continuar o mapeamento? (s/n)" << endl;
    cin >> entrada;
    if(entrada == 's'){
        return true;
    }else{
        return false;
    }
}

int main(){
    cout<<porcentagem(50,100,85)<<endl;
}



// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		int medida = /// .. Chame a função de de leitura da medida para a "Direita"
		medida = converteSensor(medida,0,830);
		posAtualVetor = // Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = leComando();		
	}
	return posAtualVetor;
}
