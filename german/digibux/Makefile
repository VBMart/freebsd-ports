# $FreeBSD$

PORTNAME=	digibux
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	german gnustep
MASTER_SITES=	http://gnu.ethz.ch/repository/digibux/
DISTNAME=	digibux_${PORTVERSION}+CVS20060118.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reader for editions of Digitale Bibliothek

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/digibux-${PORTVERSION}+CVS20060118

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
