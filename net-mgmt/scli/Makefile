# New ports collection makefile for:	scli
# Date created:		10 September 2001
# Whom:			Michael Lyngb�l <lyngbol@wheel.dk>
#
# $FreeBSD$
#

PORTNAME=	scli
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/local/${PORTNAME}/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	lyngbol@wheel.dk
COMMENT=	A collection of SNMP command line management tools

LIB_DEPENDS=	gsnmp:${PORTSDIR}/net-mgmt/gsnmp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2

MAN1=		scli.1
INFO=		scli
PLIST_FILES=	bin/scli

.include <bsd.port.mk>
