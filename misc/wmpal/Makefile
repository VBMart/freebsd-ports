# New ports collection makefile for:	wmpal
# Date created:				20 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpal
PORTVERSION=	0.6.1
CATEGORIES=	misc windowmaker
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A one of the most useless dockapps in the world

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/wmpal

post-patch:
	@${REINPLACE_CMD} -e 's|"dino"|"daemon"|g' ${WRKSRC}/wmpal.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
