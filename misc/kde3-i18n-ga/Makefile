# New ports collection makefile for:    kde3-i18n-ga
# Date created:                         22 January 2005
# Whom:                                 Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	5
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src/kde-i18n
PKGNAMEPREFIX=	ga-
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Irish messages and documentation for KDE3

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	build
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
