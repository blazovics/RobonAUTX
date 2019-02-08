#include <QCoreApplication>

#include "MainSystemController.h"
#include "Configuration.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QString configFIlePath = "D:/AUT-Projects/RobonAUTX/WinHomeMainSystem.ini";
    //QString configFIlePath = "D:/Projects/RobonAUTxQt/Win1MainSystem.ini";
    QString configFIlePath = "/Users/blazovics/Projects/RobonAUTX/MainSystem.ini";

    //QString configFIlePath = "/home/bmeaut/RobonAUTX/MainSystem_Linux.ini";

    if(argc > 1)
    {
        configFIlePath = argv[1];
    }

    Configuration::InitializeConfiguration(configFIlePath);

    MainSystemController *main = new MainSystemController();

    main->StartServers();

    return a.exec();
}
