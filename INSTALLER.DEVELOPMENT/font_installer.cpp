

#include <cstdlib>
#include <cstring>
#include <iostream>

int main(){

    int value = system(".\\7z\\7za.exe x -y .\\liberation-fonts-ttf-2.1.4.tar");

    if(value == -1){

      std::cout << "\n The fonts can not be extracted.";

      exit(EXIT_FAILURE);
    }

    value = system("xcopy /s /y .\\liberation-fonts-ttf-2.1.4 C:\\Windows\\Fonts");

    if(value == -1){

        std::cout << "\n The Liberation fonts can not be copied to the C:\\Windows\\Fonts";

        exit(EXIT_FAILURE);
    }

    value = system("del .\\liberation-fonts-ttf-2.1.4.tar");

    value = system("rmdir .\\7z /s /q");

    value = system("rmdir .\\liberation-fonts-ttf-2.1.4 /s /q");

    char reg_exe_mono [] = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"LiberationMono-Regular (TrueType)\" /t REG_SZ /d LiberationMono-Regular.ttf /f";

    char reg_exe_mono_bold [] = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"LiberationMono-Regular (TrueType)\" /t REG_SZ /d LiberationMono-Regular.ttf /f";

    char reg_exe_sans [] = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"LiberationSans-Regular (TrueType)\" /t REG_SZ /d LiberationSans-Regular.ttf /f";

    char reg_exe_sans_bold [] = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"LiberationSans-Regular (TrueType)\" /t REG_SZ /d LiberationSans-Regular.ttf /f";


    value = system(reg_exe_mono);

    if(value == -1){

        std::cout << "\n The libreration-mono font can not be installed.";

        exit(EXIT_FAILURE);
    }

    value = system(reg_exe_mono_bold);

    if(value == -1){

       std::cout << "\n The libreration-mono-bold font can not be installed.";

       exit(EXIT_FAILURE);
    }

    value = system(reg_exe_sans);

    if(value == -1){

        std::cout << "\n The libreration-mono-sans font can not be installed.";

        exit(EXIT_FAILURE);
    }

    value = system(reg_exe_sans_bold);

    if(value == -1){

       std::cout << "\n The libreration-mono-sans-bold font can not be installed";

       exit(EXIT_FAILURE);
    }


    return 0;
}
