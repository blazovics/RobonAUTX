#include "SpeedRaceResultModel.h"

SpeedRaceResultModel::SpeedRaceResultModel(QObject *parent): QAbstractListModel(parent)
{

}

void SpeedRaceResultModel::addSpeedRaceResult(const SpeedRaceResult &result)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_results << result;
    endInsertRows();
}

void SpeedRaceResultModel::removeAll()
{
    if(rowCount() > 0)
    {
        beginRemoveRows(QModelIndex(),0,rowCount()-1);
        m_results.clear();
        endRemoveRows();
    }
}

int SpeedRaceResultModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_results.count();
}

QVariant SpeedRaceResultModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_results.count())
           return QVariant();

       const SpeedRaceResult &result = m_results[index.row()];
       if (role == PositionRole)
           return result.position;
       else if (role == TeamIDRole)
           return result.teamID;
       else if (role == JuniorRole)
           return result.isJunior;
       else if (role == SpeedPointRole)
           return result.speedPoint;
       else if (role == SpeedTimeRole)
           return result.speedTime;
       return QVariant();
}

QHash<int, QByteArray> SpeedRaceResultModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[PositionRole] = "name";
        roles[TeamIDRole] = "teamID";
        roles[JuniorRole] = "isJunior";
        roles[SpeedPointRole] = "speedPoint";
        roles[SpeedTimeRole] = "speedTime";
        return roles;
}
