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
 * SWGCategory.h
 * 
 * A category for a pet
 */

#ifndef SWGCategory_H_
#define SWGCategory_H_

#include "SwaggerConfig.h"

#include <QString>
#include <QSharedDataPointer>


namespace Swagger {

class SWGCategoryData;

class SWGCategory {
public:
    SWGCategory();
    SWGCategory(const SWGCategory &other);
    ~SWGCategory();

    qint64 id() const;
    void setId(const qint64 &id);

    QString name() const;
    void setName(const QString &name);

private:
    QSharedDataPointer<SWGCategoryData> d;
};

} /* namespace Swagger */

Q_DECLARE_TYPEINFO(Swagger::SWGCategory, Q_MOVABLE_TYPE);

#endif /* SWGCategory_H_ */
