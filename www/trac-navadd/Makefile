# Created by: Brooks Davis <brooks@freebsd.org>
# $FreeBSD$

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;:L}
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Plugin for adding navigation items into Trac navigation bars

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	NavAdd
WRKSRC=			${WRKDIR}/${PORTNAME}plugin
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
