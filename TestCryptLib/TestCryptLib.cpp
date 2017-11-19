// TestCryptLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../CryptLib/EncryptLib.h"

using namespace AOI::Encrypt;

int _tmain(int argc, _TCHAR* argv[])
{
    EncryptFile ( "./data/OCR_Test.png", "./data/OCR_Test_Enc.png");
    DecryptFile ( "./data/OCR_Test_Enc.png", "./data/OCR_Test_New.png");
	return 0;
}

