# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	nbd-server
PORTVERSION=	2.8.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/nbd/nbd/${PORTVERSION}
DISTNAME=	nbd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for the Linux network block device (nbd)

USE_BZIP2=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-lfs --enable-syslog

PLIST_FILES=	bin/nbd-server
MAN1=		nbd-server.1

post-extract:
	@${CP} ${FILESDIR}/nbd.h ${WRKSRC}

.include <bsd.port.mk>
