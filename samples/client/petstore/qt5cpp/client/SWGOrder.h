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

/*
 * SWGOrder.h
 * 
 * An order for a pets from the pet store
 */

#ifndef SWGOrder_H_
#define SWGOrder_H_

#include "SwaggerConfig.h"

#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QSharedDataPointer>


namespace Swagger {

class SWGOrderData;

class SWGOrder {
    Q_GADGET
    Q_PROPERTY(qint64 id READ id)
    Q_PROPERTY(qint64 petId READ petId)
    Q_PROPERTY(qint32 quantity READ quantity)
    Q_PROPERTY(QDateTime shipDate READ shipDate)
    Q_PROPERTY(QString status READ status)
    Q_PROPERTY(bool complete READ complete)
public:
    SWGOrder();
    SWGOrder(const SWGOrder &other);
    ~SWGOrder();

    SWGOrder &operator =(const SWGOrder &other);

    bool operator ==(const SWGOrder &cmp) const;

    qint64 id() const;
    void setId(const qint64 &id);

    qint64 petId() const;
    void setPetId(const qint64 &petId);

    qint32 quantity() const;
    void setQuantity(const qint32 &quantity);

    QDateTime shipDate() const;
    void setShipDate(const QDateTime &shipDate);

    QString status() const;
    void setStatus(const QString &status);

    bool complete() const;
    void setComplete(const bool &complete);

private:
    QSharedDataPointer<SWGOrderData> d;
};

QDebug operator <<(QDebug stream, const SWGOrder &obj);

} // namespace Swagger

Q_DECLARE_TYPEINFO(Swagger::SWGOrder, Q_MOVABLE_TYPE);
Q_DECLARE_METATYPE(Swagger::SWGOrder)

#endif /* SWGOrder_H_ */
