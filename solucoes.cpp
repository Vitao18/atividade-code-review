#include <string>
#include <iostream>
#include <cctype>
#include <cassert>
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
        if(ispunct(frase[i]) ) {
            tamanho_frase--;
            continue;
        }

        // Verifica se é um espaço ou o início da frase para identificar o fim de uma palavra.
        if(frase[i] == ' ' || i == 0) {

            // Ignora espaços consecutivos.
            if((frase[i-1] == ' ' && i != 0) || (i == 0 && frase[i] == ' ')) {
                tamanho_frase--;
                continue;
            }

            // Extrai a palavra atual.
            int inicio_palavra = (i == 0) ? 0 : i + 1;
            int tamanho_palavra = tamanho_frase - inicio_palavra;
            string palavra_atual = frase.substr(inicio_palavra, tamanho_palavra);
            if(palavra_atual.size() >= maior_tamanho) {
                maior = palavra_atual;
                maior_tamanho = palavra_atual.size();
            }
            tamanho_frase = i;
        }
    }

    return maior;
}

/* TESTES DA FUNÇÃO encontrar_maior_palavra*/

void teste_encontrar_maior_palavra() {
    // Testes Iniciais
    assert(encontrar_maior_palavra("A maior palavra aqui é extraordinariamente!") == "extraordinariamente");
    assert(encontrar_maior_palavra("Teste, com pontuação.") == "pontuação");
    assert(encontrar_maior_palavra("Igual tamanho aqui") == "tamanho");
    assert(encontrar_maior_palavra("Uma frase simples") == "simples");
    assert(encontrar_maior_palavra("Palavras: curtas, médias, longas!") == "Palavras");

    // Casos Extremos
    assert(encontrar_maior_palavra("") == "");
    assert(encontrar_maior_palavra("     ") == "");
    assert(encontrar_maior_palavra("A") == "A");
    assert(encontrar_maior_palavra("A B C D E F G") == "A");

    // Casos Específicos
    assert(encontrar_maior_palavra("Eu gosto de banana e cereja") == "banana");

    // Somente pontuações
    assert(encontrar_maior_palavra("?!.,;:@#$%&*()") == "");
    assert(encontrar_maior_palavra("O ano é 2025 agora") == "agora"); 

    // Junto com números
    assert(encontrar_maior_palavra("Senha forte: p4ssw0rd!") == "p4ssw0rd");
    assert(encontrar_maior_palavra("azul . vermelho") == "vermelho");
    assert(encontrar_maior_palavra("avô avó") == "avô");
}

/* MAIN PARA EXECUTAR OS TESTES */
int main() {
    teste_encontrar_maior_palavra();
    return 0;
}
