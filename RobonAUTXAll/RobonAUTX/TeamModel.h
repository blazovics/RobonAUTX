#ifndef TEAMMODEL_H
#define TEAMMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <Team.h>

class TeamModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum TeamRoles {
        NameRole = Qt::UserRole +1,
        TeamIDRole
    };

    TeamModel(QObject* parent = nullptr);

    void addTeam(const Team &team);

    void removeAll();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Team> m_teams;
};



#endif // TEAMMODEL_H
