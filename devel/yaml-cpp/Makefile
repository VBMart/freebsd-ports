# Created by: Tim Niemueller <tim@niemueller.de>
# $FreeBSD$

PORTNAME=	yaml-cpp
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	tim@niemueller.de
COMMENT=	YAML parser and emitter in C++ matching the YAML 1.2 spec

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON -DYAML_CPP_BUILD_TOOLS=0

post-patch:     .SILENT
	${REINPLACE_CMD} 's|$${LIB_INSTALL_DIR}/pkgconfig|${LOCALBASE}/libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
