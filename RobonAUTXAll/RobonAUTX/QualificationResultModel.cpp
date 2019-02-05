#include "QualificationResultModel.h"

QualificationResultModel::QualificationResultModel(QObject *parent): QAbstractListModel(parent)
{

}

void QualificationResultModel::addQualificationResult(const QualificationResult &result)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_results << result;
    endInsertRows();
}

void QualificationResultModel::removeAll()
{
    if(rowCount() > 0)
    {
        beginRemoveRows(QModelIndex(),0,rowCount()-1);
        m_results.clear();
        endRemoveRows();
    }
}

int QualificationResultModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_results.count();
}

QVariant QualificationResultModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_results.count())
           return QVariant();

       const QualificationResult &result = m_results[index.row()];
       if (role == PositionRole)
           return result.position;
       else if (role == TeamIDRole)
           return result.teamID;
       else if (role == QualificationPointRole)
           return result.qualificationPoint;
       return QVariant();
}

QHash<int, QByteArray> QualificationResultModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[PositionRole] = "name";
        roles[TeamIDRole] = "teamID";
        roles[QualificationPointRole] = "qualificationPoint";
        return roles;
}

