#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long 

/**
 * Função que retorna a menor string binária possível usando no máximo 'availableSwaps' trocas
 * Estratégia: Para cada '1' encontrado, tenta trocá-lo com o '0' mais próximo à direita
 * 
 * @param binarySequence: string binária de entrada
 * @param availableSwaps: número máximo de trocas permitidas
 * @return: menor string binária possível
 */
string getSmallestString(string binarySequence, ll availableSwaps){
    ll sequenceLength = binarySequence.length();
    
    // Índice que aponta para a próxima posição onde pode haver um '0'
    ll nextZeroIndex = 0; 

    // Percorre cada posição da string
    for (ll currentPosition = 0; currentPosition < sequenceLength; currentPosition++) {
        
        // Se não há mais trocas disponíveis, para a execução
        if (availableSwaps == 0) {
            break;
        }

        // Se encontrou um '1' na posição atual
        if (binarySequence[currentPosition] == '1') {
            
            // Garante que não voltamos para trás na busca
            nextZeroIndex = max(currentPosition, nextZeroIndex);

            // Procura o próximo '0' à direita do '1' atual
            while (nextZeroIndex < sequenceLength && binarySequence[nextZeroIndex] == '1') {
                nextZeroIndex++;
            }

            // Se não encontrou nenhum '0', não há mais trocas possíveis
            if (nextZeroIndex == sequenceLength) {
                break;
            }

            // Calcula o custo da troca (distância entre as posições)
            ll swapCost = nextZeroIndex - currentPosition;

            // Se o custo é viável, faz a troca completa
            if (swapCost <= availableSwaps) {
                swap(binarySequence[currentPosition], binarySequence[nextZeroIndex]);
                availableSwaps -= swapCost;
            } else {
                // Se o custo é maior que as trocas disponíveis,
                // move o '0' o máximo possível para a esquerda
                binarySequence[nextZeroIndex] = '1'; 
                binarySequence[nextZeroIndex - availableSwaps] = '0';
                availableSwaps = 0;
                break;
            }

        }
        else {
            // Se a posição atual já é '0', atualiza o índice de busca
            nextZeroIndex = max(nextZeroIndex, currentPosition + 1);
        }
    }
    return binarySequence;
}




int main()
{
    string inputBinarySequence;
    ll maxAllowedSwaps;
    
    cin >> inputBinarySequence;
    cin >> maxAllowedSwaps;
    
    cout << getSmallestString(inputBinarySequence, maxAllowedSwaps) << endl;
    
    return 0;
}