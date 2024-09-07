#include <iostream>
using namespace std;
#include <vector>

vector<int> findSimilarValues(const std::vector<int>& array) {
    vector<int> similarValues;

    for (size_t i = 0; i < array.size(); ++i) {
        for (size_t j = i + 1; j < array.size(); ++j) {
            if (array[i] == array[j]) {
                // Found similar values
                similarValues.push_back(array[i]);
            }
        }
    }

    return similarValues;
}

int main() {
    vector<int> array = {1, 2, 3, 3, 5, 6};
    
    vector<int> similarValues = findSimilarValues(array);

    if (similarValues.empty()) {
        cout << "No similar values found." << std::endl;
    } else {
        cout << "Similar values: ";
        for (const auto& value : similarValues) {
            cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


        
        
        
    
    