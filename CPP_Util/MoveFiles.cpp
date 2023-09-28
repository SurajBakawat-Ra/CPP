#include <iostream>
#include <fstream>

void copyFile(const std::string& sourcePath, const std::string& destinationPath) {
    std::ifstream source(sourcePath, std::ios::binary);
    std::ofstream destination(destinationPath, std::ios::binary);

    if (source && destination) {
        // Copy file contents
        destination << source.rdbuf();
        std::cout << "Copied file: " << sourcePath << " to " << destinationPath << std::endl;
    } else {
        std::cout << "Failed to copy file: " << sourcePath << std::endl;
    }

    // Close file streams
    source.close();
    destination.close();
}

    std::string sourceFiles[] = {"D:\\Projects\\WWE_Android\\Assets\\Resources_moved\\18_ModifierAssets\\Modifiers_Holiday\\Attitude_Adjustment_Table.prefab",
"D:\\Projects\\WWE_Android\\Assets\\Resources_moved\\18_ModifierAssets\\Modifiers_Holiday\\BellyToBelly_Table.prefab",
"D:\\Projects\\WWE_Android\\Assets\\Resources_moved\\18_ModifierAssets\\Modifiers_Holiday\\Chokeslam_Chair.prefab",
"D:\\Projects\\WWE_Android\\Assets\\Resources_moved\\18_ModifierAssets\\Modifiers_Holiday\\Coast_To_Coast_Trashcan.prefab"

};

    std::string destinationFiles[] = {"D:\\Projects\\WWE_Android\\Data\\Resources_moved\\18_ModifierData\\Modifiers_Holiday\\Attitude_Adjustment_Table.prefab",
"D:\\Projects\\WWE_Android\\Data\\Resources_moved\\18_ModifierData\\Modifiers_Holiday\\BellyToBelly_Table.prefab",
"D:\\Projects\\WWE_Android\\Data\\Resources_moved\\18_ModifierData\\Modifiers_Holiday\\Chokeslam_Chair.prefab",
"D:\\Projects\\WWE_Android\\Data\\Resources_moved\\18_ModifierData\\Modifiers_Holiday\\Coast_To_Coast_Trashcan.prefab"
};

int main() 
{
    int numFiles = sizeof(sourceFiles) / sizeof(sourceFiles[0]);

    for (int i = 0; i < numFiles; ++i) {
        copyFile(sourceFiles[i], destinationFiles[i]);
    }

    return 0;
}

