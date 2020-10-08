#ifndef _ENCYPT_REGR_TEST_UTILITY_FUNCTION_H_
#define _ENCYPT_REGR_TEST_UTILITY_FUNCTION_H_

#include <string>

bool TestEncryptDecrypt(const std::string &strFilePath);
bool TestMemEncryptDecrypt(const std::string &strFilePath);
void CreateFileWithSize(const std::string &strFilePath, int size);

#endif /*_ENCYPT_REGR_TEST_UTILITY_FUNCTION_H_*/