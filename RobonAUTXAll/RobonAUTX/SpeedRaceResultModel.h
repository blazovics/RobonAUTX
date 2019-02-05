#ifndef SPEEDRACERESULTMODEL_H
#define SPEEDRACERESULTMODEL_H

#include <QAbstractListModel>
#include "SpeedRaceResult.h"

class SpeedRaceResultModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SpeedRaceRoles {
        PositionRole = Qt::UserRole +1,
        TeamIDRole,
        JuniorRole,
        SpeedPointRole,
        SpeedTimeRole
    };

    SpeedRaceResultModel(QObject* parent = nullptr);

    void addSpeedRaceResult(const SpeedRaceResult &result);

    void removeAll();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<SpeedRaceResult> m_results;
};

#endif // SPEEDRACERESULTMODEL_H
