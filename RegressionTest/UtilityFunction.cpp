#include "stdafx.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "../CryptLib/CryptLib.h"

using namespace AOI::Crypt;

static std::vector<unsigned char> readFileToBuffer(const std::string& strInputFilePath) {
    std::vector<unsigned char> buffer;
    std::ifstream fsIn(strInputFilePath, std::ios::in | std::ios::binary | std::ios::ate);
    if (!fsIn.is_open()) {
        std::cout << "Failed to open file" << strInputFilePath << std::endl;
        return buffer;
    }

    const int nFileSize = static_cast<int> (fsIn.tellg());
    fsIn.seekg(0, std::ios::beg);
    const int BUFFER_SIZE = 4096;
    int nFilePos = 0;
    buffer.resize(nFileSize);
    while (nFilePos < nFileSize) {
        int nSizeToOperate = BUFFER_SIZE;
        if ((nFilePos + BUFFER_SIZE) > nFileSize)
            nSizeToOperate = nFileSize - nFilePos;
        fsIn.read((char*)buffer.data() + nFilePos, nSizeToOperate);
        nFilePos += nSizeToOperate;
    }
    fsIn.close();
    return buffer;
}

bool isFileSame(const std::string &strFilePathOne, const std::string &strFilePathTwo) {
    std::ifstream fsOne(strFilePathOne, std::ios::in | std::ios::binary | std::ios::ate);
    if (!fsOne.is_open()) {
        std::cout << "Failed to open file " << strFilePathOne << std::endl;
        return false;
    }
    std::ifstream fsTwo(strFilePathTwo, std::ios::in | std::ios::binary | std::ios::ate);
    if (!fsTwo.is_open()) {
        std::cout << "Failed to open file " << std::endl;
        return false;
    }

    int nFileSizeOne = static_cast<int> (fsOne.tellg());
    int nFileSizeTwo = static_cast<int> (fsTwo.tellg());
    if (nFileSizeOne != nFileSizeTwo)
        return false;

    fsOne.seekg(0, std::ios::beg);
    fsTwo.seekg(0, std::ios::beg);

    int nFilePos = 0;
    const int BUFFER_SIZE = 8192;
    char bufferOne[BUFFER_SIZE], bufferTwo[BUFFER_SIZE];
    bool bSame = true;
    while (nFilePos < nFileSizeOne) {
        int nSizeToOperate = BUFFER_SIZE;
        if ((nFilePos + BUFFER_SIZE) > nFileSizeOne)
            nSizeToOperate = nFileSizeOne - nFilePos;
        fsOne.read(bufferOne, nSizeToOperate);
        fsTwo.read(bufferTwo, nSizeToOperate);
        if (memcmp(bufferOne, bufferTwo, nSizeToOperate) != 0) {
            bSame = false;
            break;
        }
        nFilePos += nSizeToOperate;
    }
    fsOne.close();
    fsTwo.close();
    return bSame;
}

bool TestEncryptDecrypt(const std::string &strFilePath) {
    std::string strEncFilePath = strFilePath + ".Enc";
    std::string strDecFilePath = strFilePath + ".Dec";
    int nResult = EncryptFileNfg(strFilePath, strEncFilePath);
    if (nResult != 0) {
        std::cout << "Failed to encrypt file " << strFilePath << std::endl;
        std::cout << GetErrorMsg() << std::endl;
        return false;
    }
    std::cout << "Success to encrypt file " << strFilePath << std::endl;

    if (isFileSame(strFilePath, strEncFilePath)) {
        std::cout << "The encrypted file is the same as original file" << std::endl;
    }

    nResult = DecryptFileNfg(strEncFilePath, strDecFilePath);
    if (nResult != 0) {
        std::cout << "Failed to decrypt file " << strEncFilePath << std::endl;
        std::cout << GetErrorMsg() << std::endl;
        return false;
    }
    std::cout << "Success to decrypt file " << strEncFilePath << std::endl;

    if (isFileSame(strFilePath, strDecFilePath)) {
        std::cout << "The decrypted file is the same as original file" << std::endl;
    }
    else {
        std::cout << "The decrypted file is not the same as original file" << std::endl;
    }

    remove(strEncFilePath.c_str());
    remove(strDecFilePath.c_str());

    return true;
}

bool TestMemEncryptDecrypt(const std::string &strFilePath) {
    std::string strEncFilePath = strFilePath + ".Enc";
    std::string strDecFilePath = strFilePath + ".Dec";

    const auto buffer = readFileToBuffer(strFilePath);
    int nResult = EncryptMemNfg(buffer, strEncFilePath);
    if (nResult != 0) {
        std::cout << "Failed to encrypt file " << strFilePath << std::endl;
        std::cout << GetErrorMsg() << std::endl;
        return false;
    }
    std::cout << "Success to encrypt file " << strFilePath << std::endl;

    if (isFileSame(strFilePath, strEncFilePath)) {
        std::cout << "The encrypted file is the same as original file" << std::endl;
    }

    nResult = DecryptFileNfg(strEncFilePath, strDecFilePath);
    if (nResult != 0) {
        std::cout << "Failed to decrypt file " << strEncFilePath << std::endl;
        std::cout << GetErrorMsg() << std::endl;
        return false;
    }
    std::cout << "Success to decrypt file " << strEncFilePath << std::endl;

    if (isFileSame(strFilePath, strDecFilePath)) {
        std::cout << "The decrypted file is the same as original file" << std::endl;
    }
    else {
        std::cout << "The decrypted file is not the same as original file" << std::endl;
    }

    remove(strEncFilePath.c_str());
    remove(strDecFilePath.c_str());

    return true;
}

void CreateFileWithSize(const std::string &strFilePath, int size)
{
    std::ofstream fsOut(strFilePath, std::ios::out);
    if (!fsOut.is_open()) {
        std::stringstream ss;
        std::cout << "Failed to open file \"" << strFilePath << "\".";
        return;
    }
    int byteWrite = 0;
    while (byteWrite < size) {
        fsOut << "a";
        ++byteWrite;
    }
    fsOut.close();
}
