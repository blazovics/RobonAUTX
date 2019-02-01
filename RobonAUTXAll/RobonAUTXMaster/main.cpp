#include <QCoreApplication>

#include "MainSystemController.h"
#include "Configuration.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString configFIlePath = "D:/AUT-Projects/RobonAUTX/MainSystem.ini";

    if(argc > 1)
    {
        configFIlePath = argv[1];
    }

    Configuration::InitializeConfiguration(configFIlePath);

    MainSystemController *main = new MainSystemController();

    main->StartServers();

    return a.exec();
}
