# New ports collection makefile for:	nacl
# Date created:		2011-10-03
# Whom:			David Thiel <lx@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nacl
PORTVERSION=	20110221
CATEGORIES=	security
MASTER_SITES=	http://hyperelliptic.org/nacl/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	High speed cryptography library

ALL_TARGET=	do
USE_BZIP2=	YES
MAKE_JOBS_UNSAFE=	YES

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

HOSTNAME_CMD?=	/bin/hostname

do-build:
	cd ${WRKSRC} && ./do

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/bin/nacl-sha256 \
		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/bin/nacl-sha512 \
		${PREFIX}/bin
.if ${ARCH} == "i386"
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/lib/x86/* \
		${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/include/x86/* \
		${PREFIX}/include
.elif ${ARCH} == "powerpc"
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/lib/ppc/* \
		${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/include/ppc/* \
		${PREFIX}/include
.else
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/lib/${ARCH}/* \
		${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/include/${ARCH}/* \
		${PREFIX}/include
.endif

.include <bsd.port.post.mk>
