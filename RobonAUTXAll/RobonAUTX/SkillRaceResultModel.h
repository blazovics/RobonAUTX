#ifndef SKILLRACERESULTMODEL_H
#define SKILLRACERESULTMODEL_H

#include <QAbstractListModel>
#include "SkillRaceResult.h"

class SkillRaceResultModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SkillRaceRoles {
        PositionRole = Qt::UserRole +1,
        TeamIDRole,
        SkillPointRole
    };

    SkillRaceResultModel(QObject* parent = nullptr);

    void addSkillRaceResult(const SkillRaceResult &result);

    void removeAll();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<SkillRaceResult> m_results;
};

#endif // SKILLRACERESULTMODEL_H
