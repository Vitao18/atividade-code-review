#include <string>
using namespace std;

bool sao_anagramas(string string1, string string2) {
    return true;
}

string cifra_de_cesar(string texto, int deslocamento) {
    return texto;
}

/*
Encontre a maior palavra em uma frase.
A frase pode conter pontuações como vírgulas, pontos, pontos de exclamação e interrogações.
*/
string encontrar_maior_palavra(string frase) {
    string maior = "";
    int maior_tamanho = 0;
    int tamanho_frase = frase.size();

    // Percorre a frase de trás para frente para identificar as palavras que vêm primeiro por último e se adequar ao requisito de em caso de empate retornar a que aparece primeiro na frase.
    for(int i = tamanho_frase; i >= 0; i--) {

        // Remove pontuações do tamanho da frase.
        if(frase[i] == ',' || frase[i] == '.' || frase[i] == '!' || frase[i] == '?' ) {
            tamanho_frase--;
        }

        // Verifica se é um espaço ou o início da frase para identificar o fim de uma palavra.
        if(frase[i] == ' ' || i == 0) {
            int inicio_palavra = (i == 0) ? 0 : i + 1;
            int tamanho_palavra = tamanho_frase - inicio_palavra;
            string palavra_atual = frase.substr(inicio_palavra, tamanho_palavra);
            if(palavra_atual.size() > maior_tamanho) {
                maior = palavra_atual;
                maior_tamanho = palavra_atual.size();
            }
            tamanho_frase = i - 1;
        }
    }

    return maior;
}
