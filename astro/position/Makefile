# $FreeBSD$

PORTNAME=	position
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	astro gnustep
MASTER_SITES=	http://www.gnustep.it/enrico/position/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPS and Moving-Map Applikation

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Position/Position
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

post-patch:
	${REINPLACE_CMD} -e 's|UV |projUV |' \
		${WRKSRC}/Functions.m

.include <bsd.port.mk>
