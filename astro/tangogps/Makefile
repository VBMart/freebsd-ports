# Created by: stas
# $FreeBSD$

PORTNAME=	tangogps
PORTVERSION=	0.99.4
PORTREVISION=	2
CATEGORIES=	astro geography
MASTER_SITES=	http://www.tangogps.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehencive GPS mapping application

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		exif.12:${PORTSDIR}/graphics/libexif \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_AUTOTOOLS=	automake aclocal libtool autoconf
ACLOCAL_ARGS=	--force
AUTCONF_ARGS=	--force
AUTOMAKE_ARGS=	--force
GNU_CONFIGURE=	yes

USE_GNOME=	gtk20 gconf2 libxml2
USE_SQLITE=	3
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/tile_management.c ${WRKSRC}/src/util.h ${WRKSRC}/src/friends.c

.include <bsd.port.mk>
