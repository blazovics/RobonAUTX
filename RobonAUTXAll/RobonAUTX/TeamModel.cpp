#include "TeamModel.h"

TeamModel::TeamModel(QObject *parent): QAbstractListModel(parent)
{

}

void TeamModel::addTeam(const Team &team)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_teams << team;
    endInsertRows();
}

void TeamModel::removeAll()
{
    if(rowCount() > 0)
    {
        beginRemoveRows(QModelIndex(),0,rowCount()-1);
        m_teams.clear();
        endRemoveRows();
    }
}

int TeamModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_teams.count();
}

QVariant TeamModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_teams.count())
           return QVariant();

       const Team &team = m_teams[index.row()];
       if (role == NameRole)
           return team.getName();
       else if (role == TeamIDRole)
           return team.getTeamID();
       return QVariant();
}

QHash<int, QByteArray> TeamModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[NameRole] = "name";
        roles[TeamIDRole] = "teamID";
        return roles;
}
