#ifndef QUALIFICATIONRESULTMODEL_H
#define QUALIFICATIONRESULTMODEL_H

#include <QAbstractListModel>
#include "QualificationResult.h"

class QualificationResultModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum QualificationRoles {
        PositionRole = Qt::UserRole +1,
        TeamIDRole,
        QualificationPointRole,
        NameRole
    };

    QualificationResultModel(QObject* parent = nullptr);

    void addQualificationResult(const QualificationResult &result);

    void removeAll();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<QualificationResult> m_results;
};

#endif // QUALIFICATIONRESULTMODEL_H
