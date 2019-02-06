#include "FinalResultModel.h"

FinalResultModel::FinalResultModel(QObject *parent): QAbstractListModel(parent)
{

}

void FinalResultModel::addFinalResult(const FinalResult &result)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_results << result;
    endInsertRows();
}

void FinalResultModel::removeAll()
{
    if(rowCount() > 0)
    {
        beginRemoveRows(QModelIndex(),0,rowCount()-1);
        m_results.clear();
        endRemoveRows();
    }
}

int FinalResultModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_results.count();
}

QVariant FinalResultModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_results.count())
           return QVariant();

       const FinalResult &result = m_results[index.row()];
       if (role == PositionRole)
           return result.position;
       else if (role == TeamIDRole)
           return result.teamID;
       else if (role == QualificationPointRole)
           return result.qualificationPoint;
       else if (role == SkillPointRole)
           return result.skillPoint;
       else if (role == SpeedPointRole)
           return result.speedPoint;
       else if (role == VotePointRole)
           return result.votePoint;
       else if (role == FinalPointRole)
           return result.finalPoint;
       else if (role == NameRole)
           return result.teamName;
       return QVariant();
}

QHash<int, QByteArray> FinalResultModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[PositionRole] = "position";
        roles[TeamIDRole] = "teamID";
        roles[QualificationPointRole] = "qualificationPoint";
        roles[SkillPointRole] = "skillPoint";
        roles[SpeedPointRole] = "speedPoint";
        roles[VotePointRole] = "votePoint";
        roles[FinalPointRole] = "finalPoint";
        roles[NameRole] = "name";
        return roles;
}

