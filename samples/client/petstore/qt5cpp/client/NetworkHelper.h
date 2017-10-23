#ifndef SWG_NETWORK_HELPER_H_
#define SWG_NETWORK_HELPER_H_

#include <QHttpPart>
#include <QNetworkReply>

class NetworkHelper {
public:
    NetworkHelper();
    ~NetworkHelper();

    void addVar(const QString &name, const QString &value);

    void addFile(const QString &name, const QHttpPart &part);

    void setData(const QByteArray &data);

    QNetworkReply *execute(const QString &method, const QNetworkRequest &request, QNetworkAccessManager *mgr);

private:
    QMap<QString, QString> m_vars;
    QMap<QString, QHttpPart> m_files;
    QByteArray m_data;
};

#endif // SWG_NETWORK_HELPER_H_
