#include "helper.cpp"

class TimeMap {
    public:
        // ["salah" : {(0 : "eddine"),(1:"gouzi")}, "asma": {(1:"tighanimin"), (4:"koraichi")} ]
        map <string, pair <string, int>> hash;
        TimeMap()
        {
        }
        void set(string key, string value, int timestamp)
        {
            hash[key] = {value, timestamp};
        }
        string get(string key, int timestamp)
        {
            string val = "";
            return val;
        }
};

int main() {
    TimeMap* timeMap = new TimeMap();
    timeMap->set("test", "one", 10);
    timeMap->set("test", "two", 20);
    timeMap->set("test", "three", 30);

    cout << timeMap->get("test", 15) << endl; // Expected: "one"
    cout << timeMap->get("test", 25) << endl; // Expected: "two"
    cout << timeMap->get("test", 35) << endl; // Expected: "three"

    delete timeMap;
    return 0;
}