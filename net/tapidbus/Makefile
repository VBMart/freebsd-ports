# New ports collection makefile for:    tapidbus
# Date created:		2006-01-11
# Whom:			Babak Farrokhi
#
# $FreeBSD$
#

PORTNAME=	tapidbus
PORTVERSION=	0.2.1
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/tapioca-voip/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction layer for interprocess communication

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|\-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
