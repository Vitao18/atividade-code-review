#include <string>
#include <set>
#include <iostream>
#include <cassert>

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

void teste_sao_anagramas() {
    // Casos básicos
    assert(sao_anagramas("amor", "roma") == true);
    assert(sao_anagramas("alegria", "galeria") == true);
    assert(sao_anagramas("", "") == true); 
    assert(sao_anagramas("pato", "patos") == false);
    assert(sao_anagramas("casa", "ca") == false);
    assert(sao_anagramas("gato", "rato") == false); 
    assert(sao_anagramas("banana", "bananana") == false);
    assert(sao_anagramas("a b c", "c b a") == true);

    // Casos em que o set falha
    assert(sao_anagramas("banana", "nababa") == false);
    assert(sao_anagramas("aab", "abb") == false);

    // Caso que a função diferencia maiúsculas de minúsculas
    assert(sao_anagramas("Amor", "roma") == true); 

    // Caso que mostra que a função não ignora espaços e que o set falha
    assert(sao_anagramas("a b c", "abc  ") == false);

}

int main() {
    // testando a função de anagramas
    teste_sao_anagramas();

    
    return 0;
}

