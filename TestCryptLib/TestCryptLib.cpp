// TestCryptLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../CryptLib/CryptLib.h"

using namespace AOI::Crypt;

int _tmain(int argc, _TCHAR* argv[])
{
    EncryptFile ( "./data/OCR_Test.png", "./data/OCR_Test_Enc.png");
    DecryptFile ( "./data/OCR_Test_Enc.png", "./data/OCR_Test_New.png");
	return 0;
}

