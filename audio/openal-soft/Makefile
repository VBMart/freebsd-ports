# $FreeBSD$

PORTNAME=	openal-soft
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/openal-releases/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A software implementation of the OpenAL specification

CONFLICTS=	openal-200[0-9]*

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DALSA:BOOL=OFF -DPORTAUDIO:BOOL=OFF -DSOLARIS:BOOL=OFF \
		-DDSOUND:BOOL=OFF -DALSOFT_CONFIG:BOOL=ON -DEXAMPLES:BOOL=OFF

OPTIONS_DEFINE=		PULSEAUDIO
PULSEAUDIO_DESC=	Enable sound streaming using PulseAudio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse-simple:${PORTSDIR}/audio/pulseaudio
CFLAGS+=	-Iinclude -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DPULSEAUDIO:BOOL=ON
.else
CMAKE_ARGS+=	-DPULSEAUDIO:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc/openal|${ETCDIR}|' \
		${WRKSRC}/Alc/alcConfig.c \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|alsoft.conf|alsoft.conf.sample|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
