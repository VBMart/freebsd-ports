# New ports collection makefile for:	xfce4-smartbookmark-plugin
# Date created:				28 Januar 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-smartbookmark-plugin
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	www xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A bookmark plugin for the Xfce panel

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui panel
USE_XORG=	ice

.include <bsd.port.mk>
