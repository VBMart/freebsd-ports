# Created by: arved
# $FreeBSD$
#   $MCom: ports-stable/multimedia/kaffeine-mozilla/Makefile,v 1.1 2008/08/01 23:13:21 mezz Exp $

PORTNAME=	kaffeine-mozilla
PORTVERSION=	0.2
PORTREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	SF/kaffeine/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kaffeine Mozilla plugin

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

RUN_DEPENDS=	kaffeine>=0:${PORTSDIR}/multimedia/kaffeine

USE_XORG=	x11 xaw
USE_BZIP2=	yes
USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=kaffeineplugin.so
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
USE_AUTOTOOLS=	libtool

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

post-patch:
	${REINPLACE_CMD} -e "s,[$$][(]prefix[)]/plugins,${WEBPLUGINS_DIR}," \
		${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e "s,echo aout, echo elf," ${WRKSRC}/configure

.include <bsd.port.post.mk>
