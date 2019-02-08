#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "DisplayManagerController.h"
#include <QQmlContext>
#include "Configuration.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QString configFIlePath = "D:/Projects/RobonAUTxQt/Win1MainSystem.ini";
    //QString configFIlePath = "D:/AUT-Projects/RobonAUTX/WinHomeMainSystem.ini";

    if(argc > 1)
    {
        configFIlePath = argv[1];
    }

    Configuration::InitializeConfiguration(configFIlePath);


    Configuration& instance = Configuration::GetInstance();

    QHostAddress serverAddress;
    long serverPort = 35005;

    if(instance.IsKeyAvailable("MainSystemSettings","ListenAddress") && instance.IsKeyAvailable("MainSystemSettings","DisplayManagerServerPort"))
    {
        QString serverAddressString = QString::fromStdString(instance.GetStringValue("MainSystemSettings","ListenAddress"));
        serverPort = instance.GetLongValue("MainSystemSettings","DisplayManagerServerPort");
        serverAddress.setAddress(serverAddressString);
    }
    else {
        serverAddress = QHostAddress("192.168.5.100");
    }
    DisplayManagerController controller(serverAddress, quint16(serverPort));

    controller.ConnectToServer();

    DisplayManager* manager = controller.getDisplayManager();

    //mainViewController.setRootContext(engine.rootContext());

    engine.rootContext()->setContextProperty("voteModel",manager->getVoteResult());
    engine.rootContext()->setContextProperty("qualificationModel",manager->getQualificationResult());
    engine.rootContext()->setContextProperty("speedRaceModel",manager->getSpeedRaceResult());
    engine.rootContext()->setContextProperty("skillRaceModel",manager->getSkillRaceResult());
    engine.rootContext()->setContextProperty("finalModel",manager->getFinalResult());
    engine.rootContext()->setContextProperty("inRaceSpeedModel",manager->getInRaceSpeedResult());

    engine.rootContext()->setContextProperty("manager",manager);
    engine.rootContext()->setContextProperty("controller",&controller);

    return app.exec();
}
