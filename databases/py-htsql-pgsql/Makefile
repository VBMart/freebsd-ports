# Created by: Kubilay Kocak <koobs.freebsd@gmail.com>
# $FreeBSD$

PORTNAME=	htsql-pgsql
PORTVERSION=	2.3.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	PostgreSQL backend for HTSQL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}htsql>2.3:${PORTSDIR}/databases/py-htsql \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2

USE_PYTHON=		2.6-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:U}

.include <bsd.port.mk>
