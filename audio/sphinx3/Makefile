# New ports collection makefile for:	sphinx3
# Date created:				4 Jan 2008
# Whom:					Richard Neese
#
# $FreeBSD$
#

PORTNAME=	sphinx3
PORTVERSION=	0.7
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	r.neese@gmail.com
COMMENT=	Speech recognition system

LIB_DEPENDS=	sphinxbase:${PORTSDIR}/audio/sphinxbase

BROKEN=		does not compile

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=libtool

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/sphinxbase
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
