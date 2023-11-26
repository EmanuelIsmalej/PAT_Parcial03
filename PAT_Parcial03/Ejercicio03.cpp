#include "Ejercicio03.h"

TimeMap::TimeMap() {
    // Constructor
}

void TimeMap::set(string key, string value, int timestamp) {
    // Almacena la clave y el valor con su timestamp
    data[key].emplace_back(timestamp, value);
}

string TimeMap::get(string key, int timestamp) {
    if (data.find(key) == data.end()) {
        return ""; // Clave no encontrada
    }

    // Buscar el valor más reciente para la clave en o antes del timestamp dado
    const auto& values = data[key];
    for (int i = values.size() - 1; i >= 0; --i) {
        if (values[i].first <= timestamp) {
            return values[i].second;
        }
    }
    return ""; // No hay valores previos al timestamp dado
}
