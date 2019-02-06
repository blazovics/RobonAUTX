#include "VoteResultModel.h"

VoteResultModel::VoteResultModel(QObject *parent): QAbstractListModel(parent)
{

}

void VoteResultModel::addVoteResult(const VoteResult &result)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_votes << result;
    endInsertRows();
}

void VoteResultModel::removeAll()
{
    if(rowCount() > 0)
    {
        beginRemoveRows(QModelIndex(),0,rowCount()-1);
        m_votes.clear();
        endRemoveRows();
    }
}

int VoteResultModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_votes.count();
}

QVariant VoteResultModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_votes.count())
           return QVariant();

       const VoteResult &result = m_votes[index.row()];
       if (role == PositionRole)
           return result.position;
       else if (role == TeamIDRole)
           return result.teamID;
       else if (role == VoteCountRole)
           return result.voteCount;
       else if (role == VotePointRole)
           return result.votePoint;
       else if (role == NameRole)
           return result.teamName;
       return QVariant();
}

QHash<int, QByteArray> VoteResultModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[PositionRole] = "position";
        roles[TeamIDRole] = "teamID";
        roles[VoteCountRole] = "voteCount";
        roles[VotePointRole] = "votePoint";
        roles[NameRole] = "name";
        return roles;
}
