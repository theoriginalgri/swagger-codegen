#include "NetworkHelper.h"

static QHash<QString, QChar> collectionFormatDelimiters {
    { "csv", QLatin1Char(',') },
    { "tsv", QLatin1Char('\t') },
    { "ssv", QLatin1Char(' ') },
    { "pipes", QLatin1Char('|') },
};

template <typename T>
static QString formatCollectionParameter(const QList<T> &list, const QString &collectionFormat) {
    const QChar delimiter = collectionFormatDelimiters.value(collectionFormat);

    QString value;
    QTextStream s(&value);

    QListIterator<T> iter(list);
    while (iter.hasNext()) {
        s << iter.next();

        if (iter.hasNext()) {
            s << delimiter;
        }
    }

    return value;
}


NetworkHelper::NetworkHelper()
{
}

NetworkHelper::~NetworkHelper()
{
}

void NetworkHelper::addVar(const QString &name, const QString &value) {
    m_vars.insert(name, value);
}

void NetworkHelper::addFile(const QString &name, const QHttpPart &part) {
    m_files.insert(name, part);
}

void NetworkHelper::setData(const QByteArray &data) {
    m_data = data;
}

QNetworkReply *NetworkHelper::execute(const QString &method, const QNetworkRequest &request, QNetworkAccessManager *mgr) {
    if (method == "POST") {
        if (m_files.isEmpty()) {
            QByteArray params = m_data;
            // TODO: Percent encoding of parameters
            return mgr->post(request, params);
        } else {
            QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

            QMapIterator<QString, QString> iter(m_vars);
            while (iter.hasNext()) {
                QHttpPart part;
                part.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data; name=%1").arg(iter.key()));
            }

            for(const QHttpPart &filePart : m_files) {
                multiPart->append(filePart);
            }

            return mgr->post(request, multiPart);
        }
    } else if (method == "GET") {
        return mgr->get(request);
    } else if (method == "PUT") {
        return mgr->put(request, m_data);
    } else if (method == "HEAD") {
        return mgr->head(request);
    } else if (method == "DELETE") {
        return mgr->deleteResource(request);
    }

    return nullptr;
}
