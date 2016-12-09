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

#include "SWGHttpRequest.h"

#include <QMap>
#include <QString>
#include "SWGOrder.h"

#include <QObject>

namespace Swagger {

class SWGStoreApi : public QObject
{
    Q_OBJECT

public:
    explicit SWGStoreApi(QObject *parent = Q_NULLPTR);
    SWGStoreApi(const SwaggerConfig &config, QObject *parent = Q_NULLPTR);
    ~SWGStoreApi();

    void setConfig(const SwaggerConfig &config);
    SwaggerConfig config() const;

    Promise<> deleteOrder(const QString &order_id);
    Promise<QMap<QString, qint32>> getInventory();
    Promise<SWGOrder> getOrderById(const qint64 &order_id);
    Promise<SWGOrder> placeOrder(const SWGOrder &body);
    

private:
    SwaggerConfig config;
};
}
#endif
