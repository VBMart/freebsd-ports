# New ports collection makefile for:   scrotwm
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	spectrwm
PORTVERSION=	2.1.0
CATEGORIES=	x11-wm
MASTER_SITES=	https://opensource.conformal.com/snapshots/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	A small, dynamic tiling window manager for X11

LICENSE=	ISCL

LIB_DEPENDS+=	xcb:${PORTSDIR}/x11/libxcb \
		xcb-util:${PORTSDIR}/x11/xcb-util \
		xcb-icccm:${PORTSDIR}/x11/xcb-util-wm \
		xcb-keysyms:${PORTSDIR}/x11/xcb-util-keysyms
RUN_DEPENDS+=	dmenu:${PORTSDIR}/x11/dmenu

USE_XORG=	x11 xcursor xft xrandr xt

MAN1=		spectrwm.1
USE_LDCONFIG=	yes
PORTEXAMPLES=	spectrwm_cz.conf \
		spectrwm_es.conf \
		spectrwm_fr.conf \
		spectrwm_fr_ch.conf \
		spectrwm_se.conf \
		spectrwm_us.conf

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/spectrwm.*

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/freetype2 -I${WRKSRC}/freebsd \
		-lutil -L${LOCALBASE}/lib -lX11 -lX11-xcb -lxcb -lxcb-icccm \
		-lxcb-keysyms -lxcb-randr -lxcb-util -lxcb-xtest -lXcursor \
		-lXft -lXrandr -DSWM_LIB=\"${PREFIX}/lib/libswmhack.so\" \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} -I${LOCALBASE}/include -shared -fpic -DPIC \
		-o ${WRKSRC}/libswmhack.so ${WRKSRC}/lib/swm_hack.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/screenshot.sh ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libswmhack.so ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/spectrwm.1 ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/spectrwm.conf ${PREFIX}/etc/spectrwm.conf.sample
	@if [ ! -f ${PREFIX}/etc/spectrwm.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/spectrwm.conf.sample ${PREFIX}/etc/spectrwm.conf ; \
	fi
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for conf in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${conf} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
