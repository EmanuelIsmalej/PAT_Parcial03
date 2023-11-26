#pragma once

#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;
using std::pair;

class TimeMap {
public:
    TimeMap();
    void set(string key, string value, int timestamp);
    string get(string key, int timestamp);

private:
    map<string, vector<pair<int, string>>> data;
};

