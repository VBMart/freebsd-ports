# $FreeBSD$

PORTNAME=	tryst
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	net gnustep
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
DISTNAME=	tryst-108pl6
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of Apples Bonjour for GNUstep

DEPRECATED=	Abandonware
EXPIRATION_DATE=	2012-11-26

LIB_DEPENDS=	dns_sd:${PORTSDIR}/net/mDNSResponder

LICENSE_COMB=	dual
LICENSE=	BSD LGPL21
LICENSE_BSD_FILE=	${WRKSRC}/Documentation/COPYING

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Tryst-108.pl6

.if defined(FETCH_MAKESUM)
MASTER_SITES=	http://gnustep.dyndns.org/Downloads/Frameworks/
.endif

# to build on 64bit
post-patch:
	${REINPLACE_CMD} -e 's|-Werror||' \
		${WRKSRC}/GNUmakefile.preamble

.include <bsd.port.mk>
