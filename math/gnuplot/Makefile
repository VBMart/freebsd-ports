# New ports collection makefile for:    gnuplot
# Date created:         19 April 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	gnuplot
PORTVERSION=	4.6.1
CATEGORIES=	math graphics
MASTER_SITES=	SF

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A command-driven interactive function plotting program

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-lasergnu \
		--with-readline=gnu \
		--without-linux-vga \
		--without-lisp-files \
		--without-tutorial \
		--with-bitmap-terminals
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	CAIRO GD GRIDBOX PDF PLOT TETEX THINSPLINES WX X11
CAIRO_DESC=		Enable CAIRO support
GD_DESC=		Enable GD support
GRIDBOX_DESC=		Use the gridbox optimization for hidden3d
PDF_DESC=		Enable PDF support
PLOT_DESC=		Enable plot support
TETEX_DESC=		Search kpsexpand at run-time
THINSPLINES_DESC=	Enable thin plate splines for grids in dgrid3d
WX_DESC=		Enable WX support
X11_DESC=		Enable X11 support

OPTIONS_DEFAULT=CAIRO GD PDF PLOT TETEX WX X11

USE_GCC=	any

MAN1=		gnuplot.1 lasergnu.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
USE_GNOME+=		pango
.else
CONFIGURE_ARGS+=	--without-cairo
.endif

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=	--with-gd=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-gd
.endif

.if ! ${PORT_OPTIONS:MGRIDBOX}
CONFIGURE_ARGS+=	--disable-h3d-quadtree --enable-h3d-gridbox
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=		pdf.6:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-pdf
.endif

.if ${PORT_OPTIONS:MPLOT}
USE_XORG+=		xaw xmu xt xext
LIB_DEPENDS+=		plot.4:${PORTSDIR}/graphics/plotutils
CONFIGURE_ARGS+=	--with-plot=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-plot
.endif

.if ${PORT_OPTIONS:MTETEX}
BUILD_DEPENDS+=		kpsexpand:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=		kpsexpand:${PORTSDIR}/print/teTeX-base
CONFIGURE_ARGS+=	--with-kpsexpand \
			--with-texdir=${LOCALBASE}/share/texmf/tex/latex/gnuplot
PLIST_SUB+=		TETEX=""
.else
PLIST_SUB+=		TETEX="@comment "
.endif

.if ${PORT_OPTIONS:MTHINSPLINES}
CONFIGURE_ARGS+=	--enable-thin-splines
.else
CONFIGURE_ARGS+=	--disable-thin-splines
.endif

.if ${PORT_OPTIONS:MWX}
USE_WX=			2.5-2.8
WX_CONF_ARGS=		absolute
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11
PLIST_SUB+=		X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

post-patch:
.if ! ${PORT_OPTIONS:MTETEX}
	@${REINPLACE_CMD} -e \
		'/^install:/s/install-am//' ${WRKSRC}/share/LaTeX/Makefile.in
.endif
	@${REINPLACE_CMD} -e \
		's|)/@PACKAGE@/@PKG_MAJOR@|)|g' ${WRKSRC}/src/Makefile.in
	@${FIND} "${WRKSRC}" -name '*.orig' -delete

.if !defined(NOPORTDOCS)
post-build:
	@cd ${WRKSRC}/docs && ${MAKE} groff
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/lasergnu ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/psdoc
	cd ${WRKSRC}/docs && ${INSTALL_DATA} gnuplot.txt gnuplot.dvi \
		gnuplot.ps ${DOCSDIR}
	cd ${WRKSRC}/docs/psdoc && ${INSTALL_DATA} README ps_* ${DOCSDIR}/psdoc
.endif

check test: build
	@( cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check ; )

.include <bsd.port.mk>
