#include <string>

namespace AOI
{
namespace Encrypt
{

//Return 0 means success, other wise is fail.
int EncryptFile(const std::string &strInputFilePath, const std::string &strOutputFilePath);
int DecryptFile(const std::string &strInputFilePath, const std::string &strOutputFilePath);
std::string GetErrorMsg();

}
}