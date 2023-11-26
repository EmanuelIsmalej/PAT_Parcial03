#include "Ejercicio01.h"
#include <queue>

struct compare {
    bool operator()(const Node<int>* l, const Node<int>* r) {
        return l->value < r->value;
    }
};

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists) {
    std::priority_queue<Node<int>*, std::vector<Node<int>*>, compare> pq;

    // Inicializar el montículo con el primer nodo de cada lista
    while (lists != nullptr) {
        if (lists->value != nullptr) {
            pq.push(lists->value);
        }
        lists = lists->next;
    }

    Node<int>* dummy = new Node<int>(); // Nodo ficticio para facilitar la manipulación
    Node<int>* tail = dummy;

    // Construir la lista combinada
    while (!pq.empty()) {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;

        if (tail->next != nullptr) {
            pq.push(tail->next);
        }
    }

    Node<int>* result = dummy->next;
    delete dummy; // Eliminar el nodo ficticio
    return result;
}
