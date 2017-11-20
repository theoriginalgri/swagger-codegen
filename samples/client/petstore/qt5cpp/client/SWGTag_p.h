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
* SWGTag.h
*
* A tag for a pet
*/

#ifndef SWGTag_PRIVATE_H_
#define SWGTag_PRIVATE_H_


#include <QString>
#include <QSharedData>


namespace Swagger {

class SWGTagData : public QSharedData {
public:
    SWGTagData()
    : QSharedData(), id(0L)
    {
    }

    SWGTagData(const SWGTagData &other)
    : QSharedData(other)
    , id(other.id)
    , name(other.name)
    {
    }

    ~SWGTagData() {
    }

    qint64 id;
    QString name;
};

} // namespace Swagger

#endif /* SWGTag_PRIVATE_H_ */
