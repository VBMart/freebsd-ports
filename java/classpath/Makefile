# Created by:	Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	classpath
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME:S|$|:src|}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	java@FreeBSD.org
COMMENT=	A GNU project to create a free Java class library

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
USE_PKGCONFIG=	build
USE_XORG=	x11 ice xtst xaw xproto xext
WANT_GNOME=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--enable-jni --disable-alsa --disable-dssi --disable-plugin
CONFIGURE_ARGS+=--with-jar=${JAR}
CONFIGURE_ENV=	JAVA="${JAVA}" JAVAC="${JAVAC}"
CONFIGURE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"
MAKE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"

MAN1=		gappletviewer.1 \
		gcjh.1 \
		gjar.1 \
		gjarsigner.1 \
		gjavah.1 \
		gkeytool.1 \
		gnative2ascii.1 \
		gorbd.1 \
		grmid.1 \
		grmiregistry.1 \
		gserialver.1 \
		gtnameserv.1

INFO=		cp-hacking cp-tools cp-vmintegration

CONFLICTS=	sablevm-classpath-1.13 sablevm-classpath-1.13_[1-9]

OPTIONS_DEFINE=	CAIRO ECJ GCONF GJDOC GMP GTK2 JDK QT4
OPTIONS_DEFAULT=GMP GJDOC GTK2 JDK
CAIRO_DESC=	Use Gtk+ Cairo based Graphics2D
ECJ_DESC=	Embed ECJ as com.sun.tools.javac
GJDOC_DESC=	Build javadoc replacement
GMP_DESC=	Enable native java.math.BigInteger
GTK2_DESC=	Enable Gtk+ AWT peer
JDK_DESC=	Build with native JDK
QT4_DESC=	Enable Qt AWT peer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MECJ} || \
    (!defined(WITH_GCJ) && empty(PORT_OPTIONS:MJDK))
MASTER_SITES+=		${MASTER_SITE_ECLIPSE:S|$|:ecj|}
MASTER_SITE_SUBDIR+=	R-${ECJ_VERSION}-${ECJ_DROPDATE}/:ecj
DISTFILES+=		${ECJ_JAR}:ecj
ECJ_VERSION=		3.8.1
ECJ_DROPDATE=		201209141540
ECJ_JAR=		ecj-${ECJ_VERSION}.jar
.endif

.if ${PORT_OPTIONS:MECJ}
CONFIGURE_ARGS+=	--with-ecj-jar=${DISTDIR}/${ECJ_JAR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLESDIR=		${DATADIR}/examples
.else
CONFIGURE_ARGS+=	--disable-examples
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-default-preferences-peer=gconf
PLIST_SUB+=		GCONF=""
.else
CONFIGURE_ARGS+=	--enable-default-preferences-peer=file \
			--disable-gconf-peer
PLIST_SUB+=		GCONF="@comment "
.endif

.if ${PORT_OPTIONS:MGJDOC}
ANTLR_JAR=		antlr-2.7.7.jar
MASTER_SITES+=		http://www.antlr2.org/download/:antlr
DISTFILES+=		${ANTLR_JAR}:antlr
MAN1+=			gjdoc.1
CONFIGURE_ARGS+=	--with-antlr-jar=${DISTDIR}/${ANTLR_JAR}
PLIST_SUB+=		GJDOC=""
.else
CONFIGURE_ARGS+=	--disable-gjdoc
PLIST_SUB+=		GJDOC="@comment "
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=		gmp:${PORTSDIR}/math/gmp
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}
PLIST_SUB+=		GMP=""
.else
CONFIGURE_ARGS+=	--disable-gmp
PLIST_SUB+=		GMP="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=		gtk20
PLIST_SUB+=		GTK2=""
.if ${PORT_OPTIONS:MCAIRO}
CONFIGURE_ARGS+=	--enable-gtk-cairo
.endif
.else
CONFIGURE_ARGS+=	--disable-gtk-peer
PLIST_SUB+=		GTK2="@comment "
.if ${PORT_OPTIONS:MCAIRO}
IGNORE=you need to enable the Gtk+ AWT peer in order to use Cairo based Graphics2D.
.endif
.endif

.if ${PORT_OPTIONS:MJDK}
USE_JAVA=		yes
JAVA_BUILD=		jdk
JAVA_VERSION=		1.5+
.else
.if defined(WITH_GCC)
GCC_SUFX=		${WITH_GCC:S/.//}
.endif
GCC_SUFX?=		46
BUILD_DEPENDS+=		gcj${GCC_SUFX}:${PORTSDIR}/lang/gcc${GCC_SUFX}
JAR=			${LOCALBASE}/bin/gjar${GCC_SUFX}
JAVA=			${LOCALBASE}/bin/gij${GCC_SUFX}
.if defined(WITH_GCJ)
JAVAC=			${LOCALBASE}/bin/gcj${GCC_SUFX}
JAVACFLAGS?=		-C
.else
JAVAC=			${WRKDIR}/ecj.sh
.endif
.endif

.if ${PORT_OPTIONS:MQT4}
CONFIGURE_ARGS+=	--enable-qt-peer
.if empty(PORT_OPTIONS:MGTK2)
CONFIGURE_ARGS+=	--enable-default-toolkit=gnu.java.awt.peer.qt.QtToolkit
.endif
CONFIGURE_ENV+=		MOC="${LOCALBASE}/bin/moc-qt4"
USE_QT4=		moc_build corelib gui
PLIST_SUB+=		QT4=""
.else
PLIST_SUB+=		QT4="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -i.bak -e 's|@JAVA@|$${JAVACMD:-java}|g' \
	    ${WRKSRC}/tools/g*.in

.if !defined(WITH_GCJ) && empty(PORT_OPTIONS:MJDK)
pre-configure:
	@if [ ! -x ${JAVAC} ]; then \
		${PRINTF} "%s\n%s\n%s\n%s\n" \
		    '#!/bin/sh' \
		    '"${JAVA}" -Xmx768M -classpath "${DISTDIR}/${ECJ_JAR}" \' \
		    '    org.eclipse.jdt.internal.compiler.batch.Main \' \
		    '    "$${@:--help}"' > ${JAVAC}; \
		${CHMOD} 755 ${JAVAC}; \
	fi
.endif

.include <bsd.port.mk>
