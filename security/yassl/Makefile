# $FreeBSD$

PORTNAME=	cyassl
PORTVERSION=	1.6.0
CATEGORIES=	security devel
MASTER_SITES=	http://www.yassl.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A embedded SSL C-Library

LICENSE=	GPLv2

USE_ZIP=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--enable-shared --enable-static
CONFIGURE_ARGS+=	--enable-dtls --enable-opensslExtra --enable-ipv6
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PORTNAME} --includedir=${PREFIX}/include/${PORTNAME}
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog NEWS README

post-configure:
	${REINPLACE_CMD} \
		-e 's|$${prefix}/cyassl/include|$${prefix}/include/cyassl|' \
		-e 's|$${prefix}/cyassl/lib|$${prefix}/lib/cyassl|' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
