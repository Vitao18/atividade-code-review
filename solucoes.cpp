#include <string>
using namespace std;

bool sao_anagramas(string string1, string string2) {
    return true;
}

string cifra_de_cesar(string texto, int deslocamento) {
    return texto;
}

string encontrar_maior_palavra(string frase) {
    string maior = "";
    int maior_tamanho = 0;
    int tamanho_frase = frase.size();
    for(int i = tamanho_frase; i >= 0; i--) {
        if(frase[i] == ',' || frase[i] == '.' || frase[i] == '!' || frase[i] == '?' ) {
            tamanho_frase--;
        }
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
