#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

int findShortestDistance(const std::string& str) {
    int xPos = -1, yPos = -1;
    int minDistance = str.size() + 1;

    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == 'x') {
            xPos = i;
            if (yPos != -1) {
                minDistance = std::min(minDistance, xPos - yPos);
            }
        } else if (str[i] == 'y') {
            yPos = i;
            if (xPos != -1) {
                minDistance = std::min(minDistance, yPos - xPos);
            }
        }
    }

    return minDistance == str.size() + 1 ? 0 : minDistance;
}

int main() {
    std::string input1 = "xyoox";
    std::string input2 = "xooo";
    std::string input3 = "xooy";

    std::cout << "Input: " << input1 << " -> Output: " << findShortestDistance(input1) << "\n";
    std::cout << "Input: " << input2 << " -> Output: " << findShortestDistance(input2) << "\n";
    std::cout << "Input: " << input3 << " -> Output: " << findShortestDistance(input3) << "\n";

    return 0;
}
