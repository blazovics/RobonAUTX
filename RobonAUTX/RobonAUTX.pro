#-------------------------------------------------
#
# Project created by QtCreator 2019-01-23T13:35:07
#
#-------------------------------------------------

QT       += qml quick network sql

QT       -= gui

CONFIG += c++14

TARGET = RobonAUTX
TEMPLATE = lib

DEFINES += ROBONAUTX_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        robonautx.cpp \
    CentralController.cpp \
    CoreController.cpp \
    DatabaseManager.cpp \
    DisplayManager.cpp \
    FinalResult.cpp \
    Lap.cpp \
    MainViewcontroller.cpp \
    QualificationResult.cpp \
    Race.cpp \
    RaceControlUnit.cpp \
    RaceEvent.cpp \
    RaceViewController.cpp \
    RemoteCentralController.cpp \
    RemoteDevice.cpp \
    RemoteDisplayManager.cpp \
    RemoteLaserGate.cpp \
    RemoteRaceControlUnit.cpp \
    RemoteSafetyCar.cpp \
    RemoteSkillRaceFieldUnit.cpp \
    RemoteVoteCounter.cpp \
    ResultViewController.cpp \
    RTimer.cpp \
    SkillRace.cpp \
    SkillRaceEvent.cpp \
    SkillRaceRecord.cpp \
    SkillRaceResult.cpp \
    SkillRaceViewController.cpp \
    SocketConnection.cpp \
    SpeedRace.cpp \
    SpeedRaceEvent.cpp \
    SpeedRaceResult.cpp \
    SpeedRaceViewController.cpp \
    Team.cpp \
    VoteCounter.cpp \
    VoteResult.cpp \
    Event.cpp

HEADERS += \
        robonautx.h \
        robonautx_global.h \
    BaseResult.h \
    CentralController.h \
    ConnectionState.h \
    CoreController.h \
    DatabaseManager.h \
    DBRecord.h \
    DisplayManager.h \
    FinalResult.h \
    ICentralController.h \
    IDatabaseAccess.h \
    IDisplayManager.h \
    ILaserGate.h \
    ISafetyCar.h \
    ISkillRaceFieldUnit.h \
    IVoteCounter.h \
    Lap.h \
    MainViewcontroller.h \
    QualificationResult.h \
    Race.h \
    RaceControlUnit.h \
    RaceEvent.h \
    RaceRecord.h \
    RaceViewController.h \
    RemoteCentralController.h \
    RemoteDevice.h \
    RemoteDisplayManager.h \
    RemoteLaserGate.h \
    RemoteRaceControlUnit.h \
    RemoteSafetyCar.h \
    RemoteSkillRaceFieldUnit.h \
    RemoteVoteCounter.h \
    ResultViewController.h \
    ResultType.h \
    RTimer.h \
    SkillRace.h \
    SkillRaceEvent.h \
    SkillRaceRecord.h \
    SkillRaceResult.h \
    SkillRaceViewController.h \
    SocketConnection.h \
    SpeedRace.h \
    SpeedRaceEvent.h \
    SpeedRaceResult.h \
    SpeedRaceViewController.h \
    Team.h \
    TimeSourceType.h \
    VoteCounter.h \
    VoteResult.h \
    IRaceControlUnit.h \
    Event.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SUBDIRS += \
    RobonAUTX.pro

DISTFILES += \
    RobonAUTX.pro.user
