# Created by: roberto
# $FreeBSD$

PORTNAME=	xfig
PORTVERSION=	3.2.5.a5
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://xfig.org/software/xfig/${PORTVERSION:R}-alpha/
DISTNAME=	${PORTNAME}.${PORTVERSION:S,.a,-alpha,}.full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drawing program for X11 (Alpha version)

DEPRECATED=	Stable version is more recent than devel version
EXPIRATION_DATE=	2012-11-26

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

CONFLICTS=	xfig-[12].* xfig-3.1* xfig-3.2.[1234]*

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION:S,.a,-alpha,}

LATEST_LINK=	xfig-devel
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xi xmu xpm xt
USE_GETTEXT=	yes
MAN1=		xfig.1

MAKE_ENV+=	DOCSDIR=${DOCSDIR}

OPTIONS_DEFINE=	DOCS GHOSTSCRIPT
OPTIONS_DEFAULT=	GHOSTSCRIPT
GHOSTSCRIPT_DESC=	Ghostscript support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install install.all
.endif

post-extract:
	@${CP} ${WRKSRC}/Doc/xfig.man ${WRKSRC}

post-patch:
.if ! ${PORT_OPTIONS:MGHOSTSCRIPT}
	@${REINPLACE_CMD} -e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.endif
	echo "NOPORTDOCS=${NOPORTDOCS}"

.include <bsd.port.mk>
