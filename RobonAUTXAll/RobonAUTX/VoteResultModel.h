#ifndef VOTERESULTMODEL_H
#define VOTERESULTMODEL_H

#include <VoteResult.h>
#include <QAbstractListModel>

class VoteResultModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum VoteRoles {
        PositionRole = Qt::UserRole +1,
        TeamIDRole,
        VoteCountRole,
        VotePointRole,
        NameRole
    };

    VoteResultModel(QObject* parent = nullptr);

    void addVoteResult(const VoteResult &result);

    void removeAll();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<VoteResult> m_votes;
};

#endif // VOTERESULTMODEL_H
