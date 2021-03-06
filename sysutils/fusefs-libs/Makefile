# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	fusefs
PORTVERSION=	2.9.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/fuse-2.X/${PORTVERSION}
PKGNAMESUFFIX=	-libs
DISTNAME=	fuse-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE allows filesystem implementation in userspace

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MOUNT_FUSE_PATH=${PREFIX}/sbin
CFLAGS+=	${PTHREAD_CFLAGS}
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
TXT_DOCS=	how-fuse-works \
		kernel.txt

post-patch:
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},' \
		-e 's,-D_FILE_OFFSET_BITS=64,-D_FILE_OFFSET_BITS=64 ${PTHREAD_CFLAGS},' \
		${WRKSRC}/fuse.pc.in
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},' \
		${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/example/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h ${PREFIX}/include/fuse

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/libs
.for i in ${TXT_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/$i ${DOCSDIR}/libs
.endfor
.endif

MAN1=	fusermount.1 \
	ulockmgr_server.1
MAN8=	mount.fuse.8

.include <bsd.port.mk>
