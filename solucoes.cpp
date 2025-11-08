#include <string>
#include <iostream>
#include <cctype>
#include <cassert>
#include <algorithm>

using namespace std;

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

bool sao_anagramas(string string1, string string2) {
    if (string1.length() != string2.length()) return false;

   
    transform(string1.begin(), string1.end(), string1.begin(), [](unsigned char c){ return std::tolower(c); });
    transform(string2.begin(), string2.end(), string2.begin(), [](unsigned char c){ return std::tolower(c); });

    sort(string1.begin(), string1.end());
    sort(string2.begin(), string2.end());

    return string1 == string2;
}

string cifra_de_cesar(string texto, int deslocamento) {
    string resultado = "";

    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];
        if (isalpha(c)) { 
            char base = islower(c) ? 'a' : 'A'; 
            c = (c - base + deslocamento) % 26 + base;
        }
        resultado += c;
    }

    return resultado;
}

void teste_encontrar_maior_palavra() {
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

    assert(encontrar_maior_palavra("Eu gosto de banana e cereja") == "banana");

    assert(encontrar_maior_palavra("?!.,;:@#$%&*()") == "");
    assert(encontrar_maior_palavra("O ano é 2025 agora") == "agora"); 

    assert(encontrar_maior_palavra("Senha forte: p4ssw0rd!") == "p4ssw0rd");
    assert(encontrar_maior_palavra("azul . vermelho") == "vermelho");
    assert(encontrar_maior_palavra("avô avó") == "avô");
}

int main() {
    assert(sao_anagramas("roma", "amor"));
    assert(sao_anagramas("Roma", "AMOR")); 
    assert(!sao_anagramas("banana", "babana")); 
    assert(!sao_anagramas("abc", "ab"));

    assert(cifra_de_cesar("Ataque ao Amanhecer!", 5) == "Fyfvzj ft Frfsmjhjw!");

    teste_encontrar_maior_palavra();

    return 0;
}

