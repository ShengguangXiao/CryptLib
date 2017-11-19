// RegressionTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UtilityFunction.h"

int _tmain(int argc, _TCHAR* argv[])
{
    bool bPass = true;
    bPass = TestEncryptDecrypt ( "./data/Not Exit file") && bPass;
    bPass = TestEncryptDecrypt ( "./data/Empty.txt") && bPass;
    bPass = TestEncryptDecrypt ( "./data/CommandLines.txt") && bPass;
    bPass = TestEncryptDecrypt ( "./data/OCR.png") && bPass;
    bPass = TestEncryptDecrypt ( "./data/F8-58-2.bmp") && bPass;

    if ( bPass )
        return 0;
	return -1;
}
