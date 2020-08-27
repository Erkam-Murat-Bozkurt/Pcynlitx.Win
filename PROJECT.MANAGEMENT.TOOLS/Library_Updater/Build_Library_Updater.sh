
g++ -std=c++14 -o Library_Updater Library_Updater_Main_File.cpp Library_Updater.cpp Library_Updater.h

printf "\n\n  Automatic library updater program is ready :-)"

printf "\n\n  The Executing command: \"sudo cp Library_Updater /usr/bin\""

printf "\n\n"

sudo mv Library_Updater /usr/bin
