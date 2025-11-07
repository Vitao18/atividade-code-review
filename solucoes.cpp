#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>

using namespace std;

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

string encontrar_maior_palavra(string frase) {
    return frase;
}

int main() {
    assert(sao_anagramas("roma", "amor"));
    assert(sao_anagramas("Roma", "AMOR")); 
    assert(!sao_anagramas("banana", "babana")); 
    assert(!sao_anagramas("abc", "ab"));

    assert(cifra_de_cesar("Ataque ao Amanhecer!", 5) == "Fyfvzj ft Frfsmjhjw!");

    return 0;
}

