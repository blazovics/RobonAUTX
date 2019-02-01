#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ControlUnitController.h"
#include "Configuration.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //QString configFIlePath = "D:/AUT-Projects/RobonAUTX/MainSystem.ini";
    QString configFIlePath = "D:/Projects/RobonAUTxQt/MainSystem.ini";

    if(argc > 1)
    {
        configFIlePath = argv[1];
    }

    Configuration::InitializeConfiguration(configFIlePath);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    ControlUnitController controller;

    controller.ConnectToServer();

    return app.exec();
}
