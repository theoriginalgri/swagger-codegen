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


#ifndef JSON_SERIALIZER_H_
#define JSON_SERIALIZER_H_

// Include models
#include "SWGApiResponse.h"
#include "SWGCategory.h"
#include "SWGOrder.h"
#include "SWGPet.h"
#include "SWGTag.h"
#include "SWGUser.h"

#include <QUuid>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

namespace Swagger {

class JsonSerializer
{
public:
    JsonSerializer();
    virtual ~JsonSerializer();

    virtual QJsonObject toJson(const SWGApiResponse &value);
    virtual bool fromJson(SWGApiResponse *dst, const QJsonValue &json);

    virtual QJsonObject toJson(const SWGCategory &value);
    virtual bool fromJson(SWGCategory *dst, const QJsonValue &json);

    virtual QJsonObject toJson(const SWGOrder &value);
    virtual bool fromJson(SWGOrder *dst, const QJsonValue &json);

    virtual QJsonObject toJson(const SWGPet &value);
    virtual bool fromJson(SWGPet *dst, const QJsonValue &json);

    virtual QJsonObject toJson(const SWGTag &value);
    virtual bool fromJson(SWGTag *dst, const QJsonValue &json);

    virtual QJsonObject toJson(const SWGUser &value);
    virtual bool fromJson(SWGUser *dst, const QJsonValue &json);

    // Builtin types
    virtual QJsonValue toJson(const QString &string);
    virtual QJsonValue toJson(const qint32 &number);
    virtual QJsonValue toJson(const qint64 &number);
    virtual QJsonValue toJson(const float &number);
    virtual QJsonValue toJson(const double &number);
    virtual QJsonValue toJson(const bool &boolean);
    virtual QJsonValue toJson(const QDateTime &dateTime);
    virtual QJsonValue toJson(const QByteArray &byteArray);
    virtual QJsonValue toJson(const QUuid &uuid);
    virtual QJsonValue toJson(const QVariant &variant);

    virtual bool fromJson(QVariant *dst, const QJsonValue &value);
    virtual bool fromJson(QUuid *dst, const QJsonValue &value);
    virtual bool fromJson(QByteArray *dst, const QJsonValue &value);
    virtual bool fromJson(QString *dst, const QJsonValue &value);
    virtual bool fromJson(QDateTime *dst, const QJsonValue &value);
    virtual bool fromJson(qint32 *dst, const QJsonValue &value);
    virtual bool fromJson(qint64 *dst, const QJsonValue &value);
    virtual bool fromJson(float *dst, const QJsonValue &value);
    virtual bool fromJson(double *dst, const QJsonValue &value);
    virtual bool fromJson(bool *dst, const QJsonValue &value);

    template <typename T>
    bool fromJson(QList<T> *list, const QJsonArray &array);

    template <typename T>
    bool fromJson(QMap<QString, T> *map, const QJsonObject &object);

    template <typename T>
    bool fromJson(QMap<QString, T> *map, const QJsonValue &value) {
        return fromJson(map, value.toObject());
    }

    template <typename T>
    QJsonObject toJson(const QMap<QString, T> &map);

    template <typename T>
    QJsonArray toJson(const QList<T> &list);

    template <typename T, typename V>
    T fromJson(const V &value);

    template <typename T>
    QList<T> fromJson(const QJsonArray &array);
};

template <typename T>
bool JsonSerializer::fromJson(QMap<QString, T> *map, const QJsonObject &object)
{
    for(auto iter=object.constBegin(); iter != object.constEnd(); ++iter) {
        map->insert(iter.key(), fromJson<T>(iter.value()));
    }
    return true;
}

template <typename T>
bool JsonSerializer::fromJson(QList<T> *list, const QJsonArray &array)
{
    for(const QJsonValue &value : array) {
        *list << fromJson<T>(value);
    }
    return true;
}

template <typename T>
QJsonObject JsonSerializer::toJson(const QMap<QString, T> &map) {
    QJsonObject object;
    QMapIterator<QString, T> iter(map);
    while (iter.hasNext()) {
        iter.next();

        object.insert(iter.key(), toJson(iter.value()));
    }

    return object;
}

template <typename T>
QJsonArray JsonSerializer::toJson(const QList<T> &list)
{
    QJsonArray array;
    for (const T &item : list) {
        array.append(toJson(item));
    }
    return array;
}

template <typename T, typename V>
T JsonSerializer::fromJson(const V &value) {
    T tmp;
    fromJson(&tmp, value);
    return tmp;
}

template <typename T>
QList<T> JsonSerializer::fromJson(const QJsonArray &array) {
    QList<T> list;
    for (const QJsonValue &value : array) {
        list << fromJson<T>(value);
    }
    return list;
}

} // namespace Swagger

#endif // JSON_SERIALIZER_H_
