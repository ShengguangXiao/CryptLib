#ifndef _AOI_CRYPT_LIB_H_
#define _AOI_CRYPT_LIB_H_

#ifdef DLLEXPORT
    #define EncryptFileAPI   __declspec(dllexport)
#else
    #define EncryptFileAPI   __declspec(dllimport)
#endif

#include <string>

namespace AOI
{
namespace Crypt
{

//Return 0 means success, other wise is fail.
EncryptFileAPI int EncryptFileNfg(const std::string &strInputFilePath, const std::string &strOutputFilePath);
EncryptFileAPI int DecryptFileNfg(const std::string &strInputFilePath, const std::string &strOutputFilePath);
EncryptFileAPI std::string GetErrorMsg();

}
}

#endif /*_AOI_CRYPT_LIB_H_*/