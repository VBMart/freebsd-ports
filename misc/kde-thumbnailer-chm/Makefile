# $FreeBSD$

PORTNAME=	kde-thumbnailer-chm
PORTVERSION=	0.2
CATEGORIES=	misc kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	153410-${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE thumbnail generator for CHM files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	lib/kde4/chmthumbnail.so \
		share/kde4/services/chmthumbnail.desktop

.include <bsd.port.mk>
