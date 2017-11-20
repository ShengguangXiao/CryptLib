#ifndef _AOI_CRYPT_LIB_H_
#define _AOI_CRYPT_LIB_H_

#include <string>

namespace AOI
{
namespace Crypt
{

//Return 0 means success, other wise is fail.
int EncryptFile(const std::string &strInputFilePath, const std::string &strOutputFilePath);
int DecryptFile(const std::string &strInputFilePath, const std::string &strOutputFilePath);
std::string GetErrorMsg();

}
}

#endif _AOI_CRYPT_LIB_H_