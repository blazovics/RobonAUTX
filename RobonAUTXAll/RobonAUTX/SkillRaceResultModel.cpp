#include "SkillRaceResultModel.h"

SkillRaceResultModel::SkillRaceResultModel(QObject *parent): QAbstractListModel(parent)
{

}

void SkillRaceResultModel::addSkillRaceResult(const SkillRaceResult &result)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_results << result;
    endInsertRows();
}

void SkillRaceResultModel::removeAll()
{
    if(rowCount() > 0)
    {
        beginRemoveRows(QModelIndex(),0,rowCount()-1);
        m_results.clear();
        endRemoveRows();
    }
}

int SkillRaceResultModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_results.count();
}

QVariant SkillRaceResultModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_results.count())
           return QVariant();

       const SkillRaceResult &result = m_results[index.row()];
       if (role == PositionRole)
           return result.position;
       else if (role == TeamIDRole)
           return result.teamID;
       else if (role == SkillPointRole)
           return result.skillPoint;
       else if (role == NameRole)
           return result.teamName;
       return QVariant();
}

QHash<int, QByteArray> SkillRaceResultModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[PositionRole] = "position";
        roles[TeamIDRole] = "teamID";
        roles[SkillPointRole] = "skillPoint";
        roles[NameRole] = "name";
        return roles;
}
