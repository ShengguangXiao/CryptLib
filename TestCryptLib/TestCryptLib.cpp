// TestCryptLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../CryptLib/CryptLib.h"

#include <iostream>
#include <fstream>

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

int _tmain(int argc, _TCHAR* argv[])
{
    std::string strFolder("C:/Users/shenxiao/Downloads/1208104230/");

    //const std::string strInputFilePath("./data/OCR.png");
    //
    //std::ifstream fsIn(strInputFilePath, std::ios::in | std::ios::binary | std::ios::ate);
    //if (!fsIn.is_open()) {
    //    std::cout << "Failed to open file" << strInputFilePath << std::endl;
    //    return -1;
    //}

    //const int nFileSize = static_cast<int> (fsIn.tellg());
    //fsIn.seekg(0, std::ios::beg);
    //const int BUFFER_SIZE = 4096;
    //int nFilePos = 0;
    //std::vector<unsigned char> buffer(nFileSize);
    //while (nFilePos < nFileSize) {
    //    int nSizeToOperate = BUFFER_SIZE;
    //    if ((nFilePos + BUFFER_SIZE) > nFileSize)
    //        nSizeToOperate = nFileSize - nFilePos;
    //    fsIn.read((char*)buffer.data() + nFilePos, nSizeToOperate);
    //    nFilePos += nSizeToOperate;
    //}
    //fsIn.close();

    //EncryptFileNfg("./data/OCR_Test.png", "./data/OCR_Test.enc");
    //EncryptMemNfg(buffer, "./data/OCR_Test.ent");
    DecryptFileNfg("./data/OCR_Test.ent", "./data/OCR_Decrypt.png");
    //for (int i = 1; i <= 12; ++i) {
    //    char chIndex[10];
    //    sprintf(chIndex, "%02d", i);
    //    std::string strInputFile = strFolder + chIndex + ".ent";
    //    std::string strOutputFile = strFolder + chIndex + ".bmp";
    //    DecryptFileNfg(strInputFile, strOutputFile);
    //}
    
    return 0;
}

