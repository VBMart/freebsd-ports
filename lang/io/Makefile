# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	io
PORTVERSION=	2011.09.12
CATEGORIES=	lang

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small prototype-based programming language

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	stevedekorte
GH_COMMIT=	23afbcc

USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=release

PORTDOCS=	*
PORTEXAMPLES=	*

.include "${.CURDIR}/Makefile.addons"

post-patch:
	${REINPLACE_CMD} -e 's/^[ ]*add_subdirectory/#&/' \
		${WRKSRC}/addons/CMakeLists.txt
.for addon in ${ADDONS}
	${ECHO} "add_subdirectory(${addon})" >> ${WRKSRC}/addons/CMakeLists.txt
.endfor
	${FIND} ${WRKSRC}/addons -name "*.bak" -o -name "*.orig" -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
