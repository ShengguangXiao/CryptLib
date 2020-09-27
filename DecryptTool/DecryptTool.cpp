// DecryptTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include <string>

#include "../CryptLib/CryptLib.h"

namespace fs = std::filesystem;

void printHelpMsg() {
    std::cout << "Please input the folder contains encrypted image" << std::endl;
    std::cout << "RenameFolders.exe d:\\images [File Extension to decrypt]" << std::endl;
}

static std::string strExtToDecrypt("ent");

static bool compareChar(char c1, char c2)
{
    if (c1 == c2)
        return true;
    else if (std::toupper(c1) == std::toupper(c2))
        return true;
    return false;
}

/*
 * Case Insensitive String Comparision
 */
bool caseInSensStringCompare(const std::string& str1, const std::string& str2)
{
    return ((str1.size() == str2.size()) &&
        std::equal(str1.begin(), str1.end(), str2.begin(), &compareChar));
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Please input the folder contains the file to decrypt" << std::endl;
        printHelpMsg();
        return -1;
    }

    if (argc > 2) {
        strExtToDecrypt = argv[2];
    }

    for (auto& p : fs::directory_iterator(argv[1])) {
        if (!p.is_regular_file())
            continue;

        const std::string strEnt = p.path().string();
        const auto strExt = strEnt.substr(strEnt.size() - 3);
        if (!caseInSensStringCompare(strExt, strExtToDecrypt)) {
            std::cout << "File " << strEnt << " skipped" << std::endl;
            continue;
        }

        std::cout << "Start to decrypt file " << p.path() << std::endl;
        const std::string strResult = strEnt.substr(0, strEnt.size() - 3) + "bmp";
        auto nResult = AOI::Crypt::DecryptFileNfg(strEnt, strResult);
        if (nResult != 0) {
            std::cout << "Failed to decrypt file " << strEnt << std::endl;
            return -1;
        }
        std::cout << "Decrypted file " << strEnt << " to " << strResult << std::endl;
    }
}
