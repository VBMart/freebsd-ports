# Created by: Jeremy Faulkner <gldisater@gldis.ca>
# $FreeBSD$

PORTNAME=	vuze
PORTVERSION=	4.8.0.0
CATEGORIES=	net-p2p java
# Moved to x-obsolete, could do with an update
MASTER_SITES=	SF/azureus/vuze/Vuze_${PORTVERSION:S/.//g}
DISTNAME=	Vuze_${PORTVERSION:S/.//g}_source

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	BitTorrent client written in Java

BUILD_DEPENDS=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
USE_ANT=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
INSTALLS_ICONS=	yes

JARFILE=	${PORTNAME}.jar

OPTIONS_DEFINE=	SWTDEVEL
OPTIONS_DEFAULT=	SWTDEVEL
SWTDEVEL_DESC=	Use SWT Development port

# build classpath from BUILD_DEPENDS
MAKE_ENV=	LANG=C
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar:T}

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/${PORTNAME} \
		share/icons/hicolor/16x16/apps/${PORTNAME}.png \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png

SUB_FILES=	${PORTNAME}
SUB_LIST=	LIBDIR="${LOCALBASE}/lib" JARFILE="${JARFILE}" \
		SWTJAR="${JAVALIBDIR}/${SWT}.jar" JAVA="${LOCALBASE}/bin/java"

DESKTOP_ENTRIES=	"Vuze" \
			"A full feature BitTorrent client" \
			"${PORTNAME}.png" \
			"${PORTNAME}" \
			"Application;Network;P2P;" \
			true

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSWTDEVEL}
SWT=		swt-devel
BUILD_DEPENDS+=	${JAVALIBDIR}/swt-devel.jar:${PORTSDIR}/x11-toolkits/swt-devel
RUN_DEPENDS+=	${JAVALIBDIR}/swt-devel.jar:${PORTSDIR}/x11-toolkits/swt-devel
.else
SWT=		swt
BUILD_DEPENDS+=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt
RUN_DEPENDS+=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt
.endif

CLASSPATH=.
.for jar in ${CLASSPATH_JARS}
CLASSPATH:=${CLASSPATH}:${JAVALIBDIR}/${jar}
.endfor

post-patch:
	${RM} -rf ${WRKSRC}/org/eclipse
	@${SED} -E -e 's|%%CLASSPATH%%|${CLASSPATH}|' \
		${FILESDIR}/build.xml > ${WRKSRC}/build.xml
# bash -> sh
	@${REINPLACE_CMD} -E -e 's|/bin/bash|${SH}|' \
		${WRKSRC}/com/aelitis/azureus/core/update/impl/AzureusRestarterImpl.java

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${JARFILE} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.for s in 16 32 64
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKDIR}/org/gudy/azureus2/ui/icons/a${s}.png \
		${PREFIX}/share/icons/hicolor/${s}x${s}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
