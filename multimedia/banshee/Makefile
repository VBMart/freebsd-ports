# Created by:	Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	banshee
PORTVERSION=	2.6.0
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Music management and playback for gnome

# Could do without bash, but it's brought in by gnome anyway.
BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono.pc:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:${PORTSDIR}/devel/dbus-sharp-glib \
		${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:${PORTSDIR}/audio/taglib-sharp \
		${LOCALBASE}/libdata/pkgconfig/mono-zeroconf.pc:${PORTSDIR}/net/mono-zeroconf \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/notify-sharp.pc:${PORTSDIR}/devel/notify-sharp

# For now, remove APPLEDEV and BOO since they are broken
OPTIONS_DEFINE=	DOCS BPMDETECT GIO MTP WEBKIT YOUTUBE

APPLEDEV_DESC=	Apple device
BOO_DESC=	Boo
BPMDETECT_DESC=	Force dependency on soundtouch (required for BPM detection)
GIO_DESC=	Use GIO for disk access
WEBKIT_DESC=	Build and/or install extensions using Webkit 
YOUTUBE_DESC=	Build and/or install the Youtube extension

OPTIONS_DEFAULT=BPMDETECT GIO MTP WEBKIT YOUTUBE

USE_XZ=		yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtksharp20 gnomesharp20
USE_GSTREAMER=	cdparanoia
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME:C/-.*//}
USE_XORG=	xrandr xxf86vm
USE_SQLITE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-vendor-build-id=FreeBSD\ BSD\#\ Project --disable-gio-hardware

.include <bsd.port.options.mk>

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# Need absolute path for build/icon-install-theme.
INSTALL=	/usr/bin/install

.if ${PORT_OPTIONS:MGIO}
CONFIGURE_ARGS+=--enable-gio
LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/gtk-sharp-beans-2.0.pc:${PORTSDIR}/x11-toolkits/gtk-sharp-beans
PLIST_SUB+=	OPT_GIO=""
.else
CONFIGURE_ARGS+=--disable-gio
PLIST_SUB+=	OPT_GIO="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-docs
PLIST_SUB+=	OPT_DOCS=""
.else
CONFIGURE_ARGS+=--disable-docs
PLIST_SUB+=	OPT_DOCS="@comment "
.endif

.if ${PORT_OPTIONS:MBPMDETECT}
USE_GSTREAMER+=	soundtouch
.endif

.if ${PORT_OPTIONS:MBOO}
CONFIGURE_ARGS+=--enable-boo
BUILD_DEPENDS+=	booc:${PORTSDIR}/lang/boo
RUN_DEPENDS+=	booc:${PORTSDIR}/lang/boo
PLIST_SUB+=	OPT_BOO=""
.else
CONFIGURE_ARGS+=--disable-boo
PLIST_SUB+=	OPT_BOO="@comment "
.endif

.if ${PORT_OPTIONS:MAPPLEDEV}
CONFIGURE_ARGS+=--enable-appledevice
LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/libgpodsharp.pc:${PORTSDIR}/audio/libgpod
BROKEN=		Missing dependency
PLIST_SUB+=	APPLEDEV=""
.else
CONFIGURE_ARGS+=--disable-appledevice
PLIST_SUB+=	APPLEDEV="@comment "
.endif

.if ${PORTSDIR:MMTP}
CONFIGURE_ARGS+=--enable-mtp
LIB_DEPENDS+=	mtp:${PORTSDIR}/audio/libmtp
PLIST_SUB+=	OPT_MTP=""
.else
CONFIGURE_ARGS+=--disable-mtp
PLIST_SUB+=	OPT_MTP="@comment "
.endif

.if ${PORT_OPTIONS:MWEBKIT}
CONFIGURE_ARGS+=--enable-webkit
LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/webkit-sharp-1.0.pc:${PORTSDIR}/www/webkit-sharp
PLIST_SUB+=	OPT_WEBKIT=""
.else
CONFIGURE_ARGS+=--disable-webkit
PLIST_SUB+=	OPT_WEBKIT="@comment "
.endif

.if ${PORT_OPTIONS:MYOUTUBE}
CONFIGURE_ARGS+=--enable-youtube
LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/gdata-sharp-youtube.pc:${PORTSDIR}/devel/google-gdata
PLIST_SUB+=	OPT_YOUTUBE=""
.else
CONFIGURE_ARGS+=--disable-youtube
PLIST_SUB+=	OPT_YOUTUBE="@comment "
.endif

.if ${PORT_OPTIONS:MWEBKIT} || ${PORT_OPTIONS:MYOUTUBE}
PLIST_SUB+=	OPT_WEBKITORYOUTUBE=""
.else
PLIST_SUB+=	OPT_WEBKITORYOUTUBE="@comment "
.endif

.include <bsd.port.mk>
