# New ports collection makefile for:	xcheckers
# Date created:				25 January 2003
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcheckers
PORTVERSION=	2.2.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://arton.cunst.net/xcheckers/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A checkers game for X11

USE_IMAKE=	yes
USE_XORG=	x11 xext xpm

MAN6=		xcheckers.6 simplech.6

# included by both imake and sh
post-patch:
	@${REINPLACE_CMD} '/^#/d' ${WRKSRC}/Local.config

pre-install:
	@${REINPLACE_CMD} 's:@LOCALBASE@:${LOCALBASE}:g' \
		${WRKSRC}/xcheckers.src/xcheckers.man

.include <bsd.port.mk>
