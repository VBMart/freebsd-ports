# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	abacus
PORTVERSION=	0.9.13
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	http://kdbio.inesc-id.pt/~aml/abacus/

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	steve
PATCHFILES=	${PORTNAME}-${PORTVERSION}.patch.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spread sheet for X Window System

LICENSE=	GPLv2

BROKEN=		crashes on start
EXPIRATION_DATE=2012-12-01
DEPRECATED=	project dead

USE_GMAKE=	yes
USE_XORG=	x11
USE_TK=		82
USE_TCL=	82

CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tcl8.2 \
		-I${LOCALBASE}/include/tk8.2
CXXFLAGS+=	-Wno-deprecated
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	dep tcl_interf/nxlc

MAN1=		abacus.1

post-extract:
	@(cd ${WRKSRC}; ${FIND} -d . -name RCS -exec ${RM} -rf {} \;)
	@(cd ${WRKSRC}; ${RM} canvas; ${LN} -sf canvas-tcl8.2.2 canvas)

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/abacus

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abacus ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/abacus.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/abacus
	@${MKDIR} ${PREFIX}/share/abacus/display
	${INSTALL_DATA} ${WRKSRC}/display/*.tcl ${PREFIX}/share/abacus/display
	@${MKDIR} ${PREFIX}/share/abacus/graphics
	${INSTALL_DATA} ${WRKSRC}/graphics/*.tcl ${PREFIX}/share/abacus/graphics
	@${MKDIR} ${PREFIX}/share/abacus/runlib
	${INSTALL_DATA} ${WRKSRC}/runlib/*.tcl ${PREFIX}/share/abacus/runlib
	${INSTALL_DATA} ${WRKSRC}/runlib/version ${PREFIX}/share/abacus/runlib
	@${MKDIR} ${PREFIX}/share/abacus/runlib/bitmaps
	${INSTALL_DATA} ${WRKSRC}/runlib/bitmaps/* ${PREFIX}/share/abacus/runlib/bitmaps
	@${MKDIR} ${PREFIX}/share/abacus/tcl_interf
	${INSTALL_PROGRAM} ${WRKSRC}/tcl_interf/nxlc ${PREFIX}/share/abacus/tcl_interf
	@${MKDIR} ${PREFIX}/share/abacus/doc
	${TAR} -C ${WRKSRC} --exclude abacus.1 -cf - doc | \
		${TAR} -C ${PREFIX}/share/abacus --unlink -xf -
	@${MKDIR} ${PREFIX}/share/examples/abacus
	${INSTALL_DATA} ${WRKSRC}/regressive/* ${PREFIX}/share/examples/abacus

.include <bsd.port.mk>
