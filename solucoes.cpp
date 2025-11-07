#include <string>
#include <set>
#include <iostream>

using namespace std;

bool sao_anagramas(string string1, string string2) {
    if (string1.length() != string2.length()) {
        return false; // anagramas necessariamente tem o mesmo tamanho
    }

    set<char> char_set1;
    set<char> char_set2;

    for (char c : string1) {
        char_set1.insert(c);
    }

    for (char c : string2) {
        if (char_set1.find(c) == char_set1.end()) {
            return false; // char na string2 não encontrado na string1
        }
    }

    return true;
}

string cifra_de_cesar(string texto, int deslocamento) {
    return texto;
}

bool valida_cpf(string cpf) {
    return true;
}

int main() {
    // testando a função de anagramas
    cout << sao_anagramas("roma", "amor") << endl;

    
    return 0;
}

