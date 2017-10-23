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

#ifndef _SWG_SWGStoreApi_H_
#define _SWG_SWGStoreApi_H_

#include <QMap>
#include <QString>
#include "SWGOrder.h"
#include "Promise.h"

#include <QObject>
#include <QSharedPointer>

namespace Swagger {

struct deleteOrderReply
{
    QNetworkReply *httpResponse = nullptr;
    int statusCode = 0;

    bool http_400 = false; // Invalid ID supplied
    bool http_404 = false; // Order not found
};

struct getInventoryReply
{
    QNetworkReply *httpResponse = nullptr;
    int statusCode = 0;

    QSharedPointer<QMap<QString, qint32>> http_200; // successful operation
};

struct getOrderByIdReply
{
    QNetworkReply *httpResponse = nullptr;
    int statusCode = 0;

    QSharedPointer<SWGOrder> http_200; // successful operation
    bool http_400 = false; // Invalid ID supplied
    bool http_404 = false; // Order not found
};

struct placeOrderReply
{
    QNetworkReply *httpResponse = nullptr;
    int statusCode = 0;

    QSharedPointer<SWGOrder> http_200; // successful operation
    bool http_400 = false; // Invalid Order
};


class SWGStoreApi : public QObject
{
    Q_OBJECT

public:
    explicit SWGStoreApi(QObject *parent = Q_NULLPTR);
    SWGStoreApi(SwaggerConfig *config, QObject *parent = Q_NULLPTR);
    ~SWGStoreApi();

    void setConfig(SwaggerConfig *config);
    SwaggerConfig *config() const;

    Promise<deleteOrderReply> deleteOrder(const QString &order_id);
    Promise<getInventoryReply> getInventory();
    Promise<getOrderByIdReply> getOrderById(const qint64 &order_id);
    Promise<placeOrderReply> placeOrder(const SWGOrder &body);
    

private:
    SwaggerConfig *m_config;
};

} // namespace Swagger

#endif
