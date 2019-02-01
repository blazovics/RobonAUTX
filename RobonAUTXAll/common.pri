CONFIG -= app_bundle

QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3 -g

INCLUDEPATH += $$PWD/RobonAUTX

#   (if TrafficCommon is not defined, as in the pro file of the TrafficCommon lib itself)
! RobonAUTX {
#    message("OUT_PWD: " $$OUT_PWD)
    win32:      CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../RobonAUTX/release/ -lRobonAUTX
    else:win32: CONFIG(debug,   debug|release): LIBS += -L$$OUT_PWD/../RobonAUTX/debug/   -lRobonAUTX
    else:unix:                                  LIBS += -L$$OUT_PWD/../RobonAUTX/         -lRobonAUTX
    DEPENDPATH += RobonAUTX
}

# These two are required for Windows. Windows itself cannot or wrongly can use DLLs without
# __declspec(dllexport) and  __declspec(dllimport). That's why all the classes have to contain
# the WIN_DLL_DECLSPEC macro in a library
win32: DEFINES += WIN_DLL_DECLSPEC=__declspec(dllimport)
else:  DEFINES += WIN_DLL_DECLSPEC=
