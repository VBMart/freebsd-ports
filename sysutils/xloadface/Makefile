# Created by: FURUSAWA,Kazuhisa <kazu@jp.freebsd.org>
# $FreeBSD$

PORTNAME=	xloadface
PORTVERSION=	1.6.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kazu.kz/freebsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network load monitor for X11

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

PATCH_STRIP=	-p1
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt
XLOADFACEDIR=	$(LOCALBASE)/lib/X11/xloadface

MAN1=		xloadface.1
MANLANG=	ja

.include <bsd.port.pre.mk>

pre-build:
	${LOCALBASE}/bin/nkf -e ${WRKSRC}/xloadface.1 > ${WRKSRC}/xloadface.man

pre-install:
	${MKDIR} $(XLOADFACEDIR)
	${INSTALL_DATA} ${WRKSRC}/README $(XLOADFACEDIR)
	${INSTALL_DATA} ${WRKSRC}/host_org.sample $(XLOADFACEDIR)
	${MKDIR} $(XLOADFACEDIR)/bigfaces
	${MKDIR} $(XLOADFACEDIR)/bitmap
	${MKDIR} $(XLOADFACEDIR)/catfaces
	${INSTALL_DATA} ${WRKSRC}/bigfaces/* $(XLOADFACEDIR)/bigfaces
	${INSTALL_DATA} ${WRKSRC}/bitmap/*   $(XLOADFACEDIR)/bitmap
	${INSTALL_DATA} ${WRKSRC}/catfaces/* $(XLOADFACEDIR)/catfaces

.include <bsd.port.post.mk>
