#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ControlUnitController.h"
#include <QQuickStyle>
#include <QQmlContext>

#include "MainViewController.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    ControlUnitController controller(QHostAddress("192.168.0.150"));

    MainViewcontroller mainViewController;

    RaceControlUnit* controlUnit = controller.getRaceControlUnit();

    //mainViewController.setRootContext(engine.rootContext());

    engine.rootContext()->setContextProperty("teamModel",controlUnit->getTeamModel());
    engine.rootContext()->setContextProperty("controlUnit",controlUnit);
    engine.rootContext()->setContextProperty("controller",&controller);

    //controller.ConnectToServer();

    return app.exec();
}
