// TestCryptLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../CryptLib/CryptLib.h"

using namespace AOI::Crypt;

int _tmain(int argc, _TCHAR* argv[])
{
    std::string strFolder("C:/Users/shenxiao/Downloads/1208104230/");
    //EncryptFileNfg ( "./data/OCR_Test.png", "./data/OCR_Test_Enc.png");
    for ( int i = 1; i <= 12; ++ i ) {
        char chIndex[10];
        sprintf ( chIndex, "%02d", i );
        std::string strInputFile = strFolder + chIndex + ".ent";
        std::string strOutputFile = strFolder + chIndex + ".bmp";
        DecryptFileNfg (strInputFile, strOutputFile );
    }
    
    return 0;
}

