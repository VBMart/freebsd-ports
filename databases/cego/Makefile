# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	cego
PORTVERSION=	2.14.0
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	A relational and transactional database system

LICENSE=	GPLv2

LIB_DEPENDS=	lfc.1:${PORTSDIR}/devel/lfc \
		lfcxml.1:${PORTSDIR}/devel/lfcxml

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env
USE_RC_SUBR=	cego

USE_NCURSES=	yes

USERS=	cego
GROUPS=	cego

PLIST_SUB+=	USER=${USERS}

post-patch:
	@${REINPLACE_CMD} -e 's,-O3,,g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
