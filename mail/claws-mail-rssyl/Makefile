# New ports collection makefile for:	rssyl
# Date created:				17 December 2005
# Whom:					v.velox@vvelox.net
#
# $FreeBSD$
#

PORTNAME=	rssyl
PORTVERSION=	0.33
PORTEPOCH=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	A RSS/Atom plugin for claws-mail

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail

USE_AUTOTOOLS=	autoconf
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
