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
 * SWGUser.h
 * 
 * A User who is purchasing from the pet store
 */

#ifndef SWGUser_H_
#define SWGUser_H_

#include "SwaggerConfig.h"

#include <QString>
#include <QSharedDataPointer>


namespace Swagger {

class SWGUserData;

class SWGUser {
public:
    SWGUser();
    SWGUser(const SWGUser &other);
    ~SWGUser();

    qint64 id() const;
    void setId(const qint64 &id);

    QString username() const;
    void setUsername(const QString &username);

    QString firstName() const;
    void setFirstName(const QString &first_name);

    QString lastName() const;
    void setLastName(const QString &last_name);

    QString email() const;
    void setEmail(const QString &email);

    QString password() const;
    void setPassword(const QString &password);

    QString phone() const;
    void setPhone(const QString &phone);

    qint32 userStatus() const;
    void setUserStatus(const qint32 &user_status);

private:
    QSharedDataPointer<SWGUserData> d;
};

}

Q_DECLARE_TYPEINFO(Swagger::SWGUser, Q_MOVABLE_TYPE);

#endif /* SWGUser_H_ */
