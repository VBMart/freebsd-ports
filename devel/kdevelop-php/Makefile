# New ports collection makefile for:	kdevelop-php
# Date created:				4 April 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdevelop
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
PKGNAMESUFFIX=	-php
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop

BUILD_DEPENDS=	${KDE4_PREFIX}/bin/kdev-pg-qt:${PORTSDIR}/devel/kdevelop-pg-qt
LIB_DEPENDS=	kdevplatforminterfaces.5:${PORTSDIR}/devel/kdevplatform

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	DOCS	"Integrate with PHP.net online documentation" on

.include <bsd.port.options.mk>

.ifdef(WITH_DOCS)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kdevphpdocs.so:${PORTSDIR}/devel/kdevelop-php-docs
.endif

.include <bsd.port.mk>
