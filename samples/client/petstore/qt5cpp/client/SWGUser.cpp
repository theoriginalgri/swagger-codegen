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


#include "SWGUser.h"
#include "SWGUser_p.h"

namespace Swagger {

SWGUser::SWGUser()
: d(new SWGUserData)
{
}

SWGUser::SWGUser(const SWGUser &other)
: d(other.d)
{
}

SWGUser::~SWGUser()
{
}

SWGUser &SWGUser::operator =(const SWGUser &other)
{
    d = other.d;
    return *this;
}

qint64 SWGUser::id() const
{
    return d->id;
}

void SWGUser::setId(const qint64 &id)
{
    d->id = id;
}

QString SWGUser::username() const
{
    return d->username;
}

void SWGUser::setUsername(const QString &username)
{
    d->username = username;
}

QString SWGUser::firstName() const
{
    return d->first_name;
}

void SWGUser::setFirstName(const QString &first_name)
{
    d->first_name = first_name;
}

QString SWGUser::lastName() const
{
    return d->last_name;
}

void SWGUser::setLastName(const QString &last_name)
{
    d->last_name = last_name;
}

QString SWGUser::email() const
{
    return d->email;
}

void SWGUser::setEmail(const QString &email)
{
    d->email = email;
}

QString SWGUser::password() const
{
    return d->password;
}

void SWGUser::setPassword(const QString &password)
{
    d->password = password;
}

QString SWGUser::phone() const
{
    return d->phone;
}

void SWGUser::setPhone(const QString &phone)
{
    d->phone = phone;
}

qint32 SWGUser::userStatus() const
{
    return d->user_status;
}

void SWGUser::setUserStatus(const qint32 &user_status)
{
    d->user_status = user_status;
}


} /* namespace Swagger */

