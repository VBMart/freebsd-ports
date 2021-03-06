# New ports collection makefile for:	motion
# Date created:				22 Dec 2005
# Whom:					Angel Carpintero <ack@telefonica.net>
#
# $FreeBSD$
#

PORTNAME=	motion
PORTVERSION=	3.2.12
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	A motion detection application

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	VIDEO LTHREAD FFMPEG MYSQL PGSQL DOCS EXAMPLES
OPTIONS_SINGLE=	VIDEO
OPTIONS_SINGLE_VIDEO=	BKTR PWCBSD
OPTIONS_DEFAULT=	VIDEO BKTR FFMPEG
VIDEO_DESC=	Video capture driver. Choose one of BKTR or PWCBSD
BKTR_DESC=	BKTR based TV capture cards
PWCBSD_DESC=	PWCBSD based Webcams
LTHREAD_DESC=	Use LinuxThreads instead of native POSIX threads

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		motion.1
PORTDOCS=	CHANGELOG CREDITS README README.FreeBSD \
		motion_guide.html
PORTEXAMPLES=	motion-dist.conf thread1.conf thread2.conf \
		thread3.conf thread4.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBKTR}
CONFIGURE_ARGS+=--with-bktr
.else
CONFIGURE_ARGS+=--without-bktr
.endif

.if ${PORT_OPTIONS:MPWCBSD}
BUILD_DEPENDS+=	v4l_compat>=1.0.20060801:${PORTSDIR}/multimedia/v4l_compat
RUN_DEPENDS+=	/boot/modules/pwc.ko:${PORTSDIR}/multimedia/pwcbsd
CONFIGURE_ARGS+=--with-pwcbsd
.else
CONFIGURE_ARGS+=--without-pwcbsd
CFLAGS+=	-DWITHOUT_V4L
.endif

.if ${PORT_OPTIONS:MLTHREAD}
LIB_DEPENDS+=	lthread:${PORTSDIR}/devel/linuxthreads
CONFIGURE_ARGS+=--with-linuxthreads
.else
CONFIGURE_ARGS+=--without-linuxthreads
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--with-ffmpeg=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-include=${LOCALBASE}/include/mysql
.else
CONFIGURE_ARGS+=--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/lib \
		--with-pgsql-include=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--without-pgsql
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure.in
# Resolve name collision with jpeg-8
	@${REINPLACE_CMD} -e \
		's|jpeg_mem_dest|local_jpeg_mem_dest|' ${WRKSRC}/picture.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/motion ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/motion.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/motion.init-FreeBSD.sh \
		${PREFIX}/etc/rc.d/motion
	${INSTALL_DATA} ${WRKSRC}/motion-dist.conf \
		${PREFIX}/etc/motion.conf.sample
.if !exists(${PREFIX}/etc/motion.conf)
	${INSTALL_DATA} ${PREFIX}/etc/motion.conf.sample \
		${PREFIX}/etc/motion.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
