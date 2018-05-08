#define DLLEXPORT
#include "CryptLib.h"
#include <fstream>
#include <sstream>

namespace AOI
{
namespace Crypt
{

const char KEY[] = "NingFeiGuang2017";
const int KEY_SIZE = sizeof(KEY) / sizeof(char);
const char SIGN[] = {1, -1};
static std::string g_strErrorMsg;

EncryptFileAPI int EncryptFileNfg(const std::string &strInputFilePath, const std::string &strOutputFilePath) {
    std::ifstream fsIn(strInputFilePath, std::ios::in | std::ios::binary | std::ios::ate);
    if (! fsIn.is_open()) {
        std::stringstream ss;
        ss << "Failed to open file \"" << strInputFilePath << "\".";
        g_strErrorMsg = ss.str();
        return -1;
    }

    std::ofstream fsOut(strOutputFilePath, std::ios::out | std::ios::binary);
    if (! fsIn.is_open()) {
        std::stringstream ss;
        ss << "Failed to open file \"" << strOutputFilePath << "\".";
        g_strErrorMsg = ss.str();
        return -1;
    }

    int nFileSize = static_cast<int> (fsIn.tellg());
    fsIn.seekg(0, std::ios::beg);
    const int BUFFER_SIZE = 8192;
    char bufferIn[BUFFER_SIZE], bufferOut[BUFFER_SIZE];
    int nFilePos = 0;

    while (nFilePos < nFileSize) {
        int nSizeToOperate = BUFFER_SIZE;
        if ((nFilePos + BUFFER_SIZE) > nFileSize)
            nSizeToOperate = nFileSize - nFilePos;
        fsIn.read(bufferIn, nSizeToOperate);

        for (int i = 0; i < nSizeToOperate; ++ i) {
            char sign = SIGN[i % 2];
            bufferOut[i] = bufferIn[i] + sign * KEY[i % KEY_SIZE];
        }

        fsOut.write(bufferOut, nSizeToOperate);
        nFilePos += nSizeToOperate;
    }
    fsIn.close();
    fsOut.close();
    return 0;
}

EncryptFileAPI int DecryptFileNfg(const std::string &strInputFilePath, const std::string &strOutputFilePath) {
    std::ifstream fsIn(strInputFilePath, std::ios::in | std::ios::binary | std::ios::ate);
    if (! fsIn.is_open()) {
        std::stringstream ss;
        ss << "Failed to open file \"" << strInputFilePath << "\".";
        g_strErrorMsg = ss.str();
        return -1;
    }
    std::ofstream fsOut(strOutputFilePath, std::ios::out | std::ios::binary);
    if (! fsIn.is_open()) {
        std::stringstream ss;
        ss << "Failed to open file \"" << strOutputFilePath << "\".";
        g_strErrorMsg = ss.str();
        return -1;
    }

    int nFileSize = static_cast<int> (fsIn.tellg());
    fsIn.seekg(0, std::ios::beg);
    const int BUFFER_SIZE = 8192;
    char bufferIn[BUFFER_SIZE], bufferOut[BUFFER_SIZE];
    int nFilePos = 0;

    while (nFilePos < nFileSize) {
        int nSizeToOperate = BUFFER_SIZE;
        if ((nFilePos + BUFFER_SIZE) > nFileSize)
            nSizeToOperate = nFileSize - nFilePos;
        fsIn.read(bufferIn, nSizeToOperate);

        for (int i = 0; i < nSizeToOperate; ++ i) {
            char sign = SIGN[i % 2];
            bufferOut[i] = bufferIn[i] - sign * KEY[i % KEY_SIZE];
        }

        fsOut.write(bufferOut, nSizeToOperate);
        nFilePos += nSizeToOperate;
    }
    fsIn.close();
    fsOut.close();
    return 0;
}

EncryptFileAPI std::string GetErrorMsg() {
    return g_strErrorMsg;
}

}
}