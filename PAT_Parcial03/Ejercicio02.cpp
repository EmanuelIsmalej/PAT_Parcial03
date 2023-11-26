#include "Ejercicio02.h"
#include <unordered_map>

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head) {
    auto* result = new vector<string>();
    if (!head || !head->next) return result; 

    std::unordered_map<string, int> sequenceCount;
    Node<char>* current = head;
    string currentSequence = "";

    // Construir secuencias de 10 caracteres
    while (current) {
        currentSequence += current->value;
        if (currentSequence.length() == 10) {
            sequenceCount[currentSequence]++;
            currentSequence.erase(0, 1); // Remueve el primer carácter
        }
        current = current->next;
    }

    // Agregar secuencias repetidas al resultado
    for (const auto& pair : sequenceCount) {
        if (pair.second > 1) {
            result->push_back(pair.first);
        }
    }

    return result;
}
