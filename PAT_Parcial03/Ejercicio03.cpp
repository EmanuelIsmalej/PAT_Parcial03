#include "Ejercicio03.h"

TimeMap::TimeMap() {
    // Constructor vacío
}

void TimeMap::set(string key, string value, int timestamp) {
    data[key].emplace_back(timestamp, value);
}

string TimeMap::get(string key, int timestamp) {
    if (data.find(key) == data.end()) {
        return ""; // Si la clave no existe, devuelve una cadena vacía
    }

    const auto& entries = data[key];
    int low = 0, high = entries.size() - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (entries[mid].first == timestamp) {
            return entries[mid].second; // Coincidencia exacta
        }
        else if (entries[mid].first < timestamp) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (high >= 0) {
        return entries[high].second; // El más cercano y menor o igual al timestamp
    }

    return ""; // No hay valores para el timestamp dado
}
