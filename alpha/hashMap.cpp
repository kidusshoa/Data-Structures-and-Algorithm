#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> ageMap;

    ageMap["Kidus "] = 25;
    ageMap["Yabets"] = 30;
    ageMap["Eyasu"] = 22;

    std::cout << "Kidus's age: " << ageMap["Kidus"] << std::endl;

    if (ageMap.find("Yabets") != ageMap.end()) {
        std::cout << "Yabets is in the map!" << std::endl;
    }

    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    ageMap.erase("Eyasu");

    return 0;
}
