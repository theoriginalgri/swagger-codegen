/**
 * Swagger Petstore
 * This is a sample server Petstore server.  You can find out more about Swagger at [http://swagger.io](http://swagger.io) or on [irc.freenode.net, #swagger](http://swagger.io/irc/).  For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * Contact: apiteam@swagger.io
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

#include "SWGPetApi.h"
#include "JsonSerializer.h"
#include "NetworkHelper.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QHttpPart>
#include <QDebug>

namespace Swagger {

SWGPetApi::SWGPetApi(QObject *parent)
: QObject(parent)
, m_config(nullptr)
{
}

SWGPetApi::SWGPetApi(SwaggerConfig *config, QObject *parent)
: QObject(parent)
, m_config(config)
{
}

SWGPetApi::~SWGPetApi()
{
}

void SWGPetApi::setConfig(SwaggerConfig *config)
{
    m_config = config;
}

SwaggerConfig *SWGPetApi::config() const
{
    return m_config;
}

Promise<addPetReply> SWGPetApi::addPet(const SWGPet &body) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet";

    url.setPath(fullPath);

    QUrlQuery query(url);

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;

    JsonSerializer serializer;
    QJsonDocument doc;
    doc.setObject(serializer.toJson(body));
    

    // Set post content
    helper.setData(doc.toJson());


    // START authentication
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("POST", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<addPetReply> *promise = new Promise<addPetReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        addPetReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        case 405: // Invalid input
            {
                response.http_405 = true;
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

Promise<deletePetReply> SWGPetApi::deletePet(const qint64 &pet_id, const QString &api_key) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet/{petId}";

    fullPath.replace("{petId}", QVariant::fromValue(pet_id).toString());
    url.setPath(fullPath);

    QUrlQuery query(url);

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;

    JsonSerializer serializer;
    QJsonDocument doc;


    // Set post content
    helper.setData(doc.toJson());

    request.setRawHeader("api_key", QVariant::fromValue(api_key).toByteArray());

    // START authentication
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("DELETE", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<deletePetReply> *promise = new Promise<deletePetReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        deletePetReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        case 400: // Invalid pet value
            {
                response.http_400 = true;
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

Promise<findPetsByStatusReply> SWGPetApi::findPetsByStatus(const QList<QString> &status) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet/findByStatus";

    url.setPath(fullPath);

    QUrlQuery query(url);
    query.addQueryItem("status", formatCollectionParameter(status, "csv"));

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;

    JsonSerializer serializer;
    QJsonDocument doc;


    // Set post content
    helper.setData(doc.toJson());


    // START authentication
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("GET", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<findPetsByStatusReply> *promise = new Promise<findPetsByStatusReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        findPetsByStatusReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        default: // successful operation
            {
                response.http_200 = QSharedPointer<QList<SWGPet>>::create();
                serializer.fromJson(response.http_200.data(), doc.array());
            }
            break;
        case 400: // Invalid status value
            {
                response.http_400 = true;
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

Promise<findPetsByTagsReply> SWGPetApi::findPetsByTags(const QList<QString> &tags) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet/findByTags";

    url.setPath(fullPath);

    QUrlQuery query(url);
    query.addQueryItem("tags", formatCollectionParameter(tags, "csv"));

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;

    JsonSerializer serializer;
    QJsonDocument doc;


    // Set post content
    helper.setData(doc.toJson());


    // START authentication
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("GET", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<findPetsByTagsReply> *promise = new Promise<findPetsByTagsReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        findPetsByTagsReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        default: // successful operation
            {
                response.http_200 = QSharedPointer<QList<SWGPet>>::create();
                serializer.fromJson(response.http_200.data(), doc.array());
            }
            break;
        case 400: // Invalid tag value
            {
                response.http_400 = true;
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

Promise<getPetByIdReply> SWGPetApi::getPetById(const qint64 &pet_id) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet/{petId}";

    fullPath.replace("{petId}", QVariant::fromValue(pet_id).toString());
    url.setPath(fullPath);

    QUrlQuery query(url);

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;

    JsonSerializer serializer;
    QJsonDocument doc;


    // Set post content
    helper.setData(doc.toJson());


    // START authentication
    request.setRawHeader("api_key", m_config->apiKey("api_key"));
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("GET", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<getPetByIdReply> *promise = new Promise<getPetByIdReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        getPetByIdReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        default: // successful operation
            {
                response.http_200 = QSharedPointer<SWGPet>::create();
                serializer.fromJson(response.http_200.data(), doc.object());
            }
            break;
        case 400: // Invalid ID supplied
            {
                response.http_400 = true;
            }
            break;
        case 404: // Pet not found
            {
                response.http_404 = true;
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

Promise<updatePetReply> SWGPetApi::updatePet(const SWGPet &body) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet";

    url.setPath(fullPath);

    QUrlQuery query(url);

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;

    JsonSerializer serializer;
    QJsonDocument doc;
    doc.setObject(serializer.toJson(body));
    

    // Set post content
    helper.setData(doc.toJson());


    // START authentication
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("PUT", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<updatePetReply> *promise = new Promise<updatePetReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        updatePetReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        case 400: // Invalid ID supplied
            {
                response.http_400 = true;
            }
            break;
        case 404: // Pet not found
            {
                response.http_404 = true;
            }
            break;
        case 405: // Validation exception
            {
                response.http_405 = true;
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

Promise<updatePetWithFormReply> SWGPetApi::updatePetWithForm(const qint64 &pet_id, const QString &name, const QString &status) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet/{petId}";

    fullPath.replace("{petId}", QVariant::fromValue(pet_id).toString());
    url.setPath(fullPath);

    QUrlQuery query(url);

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;
    helper.addVar("name", QVariant::fromValue(name).toString());
    helper.addVar("status", QVariant::fromValue(status).toString());

    JsonSerializer serializer;
    QJsonDocument doc;


    // Set post content
    helper.setData(doc.toJson());


    // START authentication
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("POST", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<updatePetWithFormReply> *promise = new Promise<updatePetWithFormReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        updatePetWithFormReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        case 405: // Invalid input
            {
                response.http_405 = true;
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

Promise<uploadFileReply> SWGPetApi::uploadFile(const qint64 &pet_id, const QString &additional_metadata, const QHttpPart &file) {
    QUrl url(m_config->url());
    QString fullPath = url.path() + "/pet/{petId}/uploadImage";

    fullPath.replace("{petId}", QVariant::fromValue(pet_id).toString());
    url.setPath(fullPath);

    QUrlQuery query(url);

    // START authentication
    // END authentication

    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, QVariant::fromValue(true));

    NetworkHelper helper;
    helper.addVar("additionalMetadata", QVariant::fromValue(additional_metadata).toString());
    helper.addFile("file", file);

    JsonSerializer serializer;
    QJsonDocument doc;


    // Set post content
    helper.setData(doc.toJson());


    // START authentication
    // END authentication

    m_config->prepareRequest(&request);

    QNetworkReply *reply = helper.execute("POST", request, m_config->networkAccessManager());

    m_config->processReply(reply);

    Promise<uploadFileReply> *promise = new Promise<uploadFileReply>;

    connect(reply, &QNetworkReply::finished, [=](){
        JsonSerializer serializer;
        uploadFileReply response;
        response.httpResponse = reply;

        // TODO: Error handling
        if (reply->error() != QNetworkReply::NoError) {
            promise->reject();

            qDebug() << "HTTP error:" << reply->errorString() << reply->readAll();

            reply->deleteLater();
            delete promise;
            return;
        }

        QByteArray data = reply->readAll();

        QJsonDocument doc;
        if (!data.isEmpty()) {
            QJsonParseError error;
            doc = QJsonDocument::fromJson(data, &error);

            if (error.error != QJsonParseError::NoError) {
                promise->reject();

                qDebug() << "JSON parse error:" << error.errorString();

                reply->deleteLater();
                delete promise;
                return;
            }
        }

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        response.statusCode = statusCode;
        switch(statusCode) {
        default: // successful operation
            {
                response.http_200 = QSharedPointer<SWGApiResponse>::create();
                serializer.fromJson(response.http_200.data(), doc.object());
            }
            break;
        }

        promise->resolve(response);

        reply->deleteLater();
        delete promise;
    });

    return *promise;
}

} /* namespace Swagger */
