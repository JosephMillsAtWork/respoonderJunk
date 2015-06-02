/*
 * Copyright (C) 2012-2013 Joseph Mills.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BONJOURREGISTER_H
#define BONJOURREGISTER_H
#include <QObject>
#include <dns_sd.h>
#include <QSocketNotifier>
#include <QtEndian>
#include <QDebug>
#include <stdlib.h>

class QSocketNotifier;

class BonjourRegister : public QObject
{
    Q_OBJECT
  public:
    BonjourRegister(QObject *parent = 0);
   ~BonjourRegister();

    bool Register(uint16_t port, const QByteArray &type, const QByteArray &name,
                  const QByteArray &txt);

    QByteArray       m_name;
    QByteArray       m_type;

  private slots:
    void socketReadyRead();

  private:
    static void DNSSD_API BonjourCallback(DNSServiceRef ref,
                                          DNSServiceFlags flags,
                                          DNSServiceErrorType errorcode,
                                          const char *name, const char *type,
                                          const char *domain, void *object);
    DNSServiceRef    m_dnssref;
    QSocketNotifier *m_socket;
};
#endif
