#ifndef FINALRESULTMODEL_H
#define FINALRESULTMODEL_H

#include <QAbstractListModel>
#include "FinalResult.h"

class FinalResultModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum FinalRoles {
        PositionRole = Qt::UserRole +1,
        TeamIDRole,
        SkillPointRole,
        SpeedPointRole,
        QualificationPointRole,
        VotePointRole,
        FinalPointRole
    };

    FinalResultModel(QObject* parent = nullptr);

    void addFinalResult(const FinalResult &result);

    void removeAll();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<FinalResult> m_results;
};

#endif // FINALRESULTMODEL_H
