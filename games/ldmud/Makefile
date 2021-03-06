# New ports collection makefile for:	ldmud
# Date created:		13 August 2003
# Whom:			glewis@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ldmud
PORTVERSION=	3.3.720
PORTEPOCH=	1
CATEGORIES=	games net
MASTER_SITES=	http://www.bearnip.com/ftp/mud/ \
		ftp://mud.stack.nl/pub/ldmud/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A modern version of the LPMud game driver

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes
CONFIGURE_ARGS+=--libdir=${DATADIR} \
		--bindir=${PREFIX}/sbin \
		--enable-use-pcre \
		--enable-use-tls=ssl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
ALL_TARGET=	ldmud
MAN1=		ldmud.1
USE_RC_SUBR=	ldmud
SUB_LIST+=	LDUSER=${USERS}
MAKE_JOBS_UNSAFE=	yes

USERS=		mud
GROUPS=		mud

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE IPV6 LPMUD
OPTIONS_DEFAULT=MYSQL PGSQL SQLITE IPV6 LPMUD
LPMUD_DESC=	Install default mudlib (LP-245)

PORTSCOUT=	skipv:3.4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-use-ipv6
.else
CONFIGURE_ARGS+=--disable-use-ipv6
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
CONFIGURE_ARGS+=--enable-use-mysql
.else
CONFIGURE_ARGS+=--disable-use-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-use-pgsql
.else
CONFIGURE_ARGS+=--disable-use-pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
CONFIGURE_ARGS+=--enable-use-sqlite
.else
CONFIGURE_ARGS+=--disable-use-sqlite
.endif

.if ${PORT_OPTIONS:MLPMUD}
PLIST_SUB+=	LPMUD="" DEMOLIB="@comment "
.else
PLIST_SUB+=	LPMUD="@comment " DEMOLIB=""
.endif

.include <bsd.port.pre.mk>

post-install:
#	# Install mudlib and other directories
	@${MKDIR} ${DATADIR} /var/log/${PORTNAME} /var/run/${PORTNAME}
	@${CHOWN} ${USERS}:${GROUPS} /var/log/${PORTNAME} /var/run/${PORTNAME}
.if ${PORT_OPTIONS:MLPMUD}
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mud/lp-245 && ${FIND} . \
		| ${CPIO} -pdmu -R ${USERS}:${GROUPS} ${DATADIR}
.else
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mudlib && ${FIND} . \
		| ${CPIO} -pdmu -R ${USERS}:${GROUPS} ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${RM} -f ${DOCSDIR}/Makefile
.endif

.include <bsd.port.post.mk>
