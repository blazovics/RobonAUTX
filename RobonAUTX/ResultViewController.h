/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#ifndef RESULTVIEWCONTROLLER_H
#define RESULTVIEWCONTROLLER_H

#include <QObject>

class ResultViewController : public QObject {

    Q_OBJECT

public: 
    ResultViewController(QObject *parent);

signals:
    void showSpeedResults(quint32 fromPos = 1);
    
    void showJuniorSpeedResults(quint32 fromPos = 1);
    
    void showSkillResults(quint32 fromPos = 1);

    void showVoteResults(quint32 fromPos = 1);

    void showQualificationResults(quint32 fromPos = 1);
    
    void ShowFinalResults(quint32 fromPos = 1);

    void ShowFinalResultForTeam(quint32 atPos);
};

#endif //_RESULTVIEWCONTROLLER_H
